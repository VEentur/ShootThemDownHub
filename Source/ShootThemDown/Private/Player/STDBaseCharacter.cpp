// ShootThemDown game. All rights reserved.

#include "STDBaseCharacter.h"
#include "STDWeaponComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/STDCharacterMovementComponent.h"
#include "Components/STDHealthComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/STDWeaponComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"

DEFINE_LOG_CATEGORY_STATIC (LogMovement, All, All)
DEFINE_LOG_CATEGORY_STATIC (BaseCharacterLog, All, All)

// Sets default values
ASTDBaseCharacter::ASTDBaseCharacter(const FObjectInitializer& ObjInit)
	: Super(ObjInit.SetDefaultSubobjectClass<USTDCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SocketOffset = FVector(0.0f, 100.0f, 80.0f);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	HealthComponent = CreateDefaultSubobject<USTDHealthComponent>("HealthComponent");
		
	HealthTextComponent = CreateDefaultSubobject<UTextRenderComponent>("HealthTextComponent");
	HealthTextComponent->SetupAttachment(GetRootComponent());
	HealthTextComponent->bOwnerNoSee = true;

	WeaponComponent = CreateDefaultSubobject<USTDWeaponComponent>("WeaponComponent");
}

// Called when the game starts or when spawned
void ASTDBaseCharacter::BeginPlay()
{ 
	Super::BeginPlay();
	
	check(HealthComponent);
	check(HealthTextComponent);
	check(GetCharacterMovement());

	OnHealthChanged(HealthComponent->GetHealth());
	HealthComponent->OnDeath.AddUObject(this, &ASTDBaseCharacter::OnDeath);
	HealthComponent->OnHealthChanged.AddUObject(this, &ASTDBaseCharacter::OnHealthChanged);

	LandedDelegate.AddDynamic(this, &ASTDBaseCharacter::OnGroundLanded);
}	

void ASTDBaseCharacter::OnHealthChanged(float Health)
{
HealthTextComponent->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), Health)));
}

// Called every frame
void ASTDBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



// Called to bind functionality to input
void ASTDBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	check(WeaponComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASTDBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASTDBaseCharacter::MoveRight);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ASTDBaseCharacter::OnStartRunning);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &ASTDBaseCharacter::OnStopRunning);

	PlayerInputComponent->BindAxis("LookUp", this, &ASTDBaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &ASTDBaseCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASTDBaseCharacter::Jump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &USTDWeaponComponent::StartFire);
    PlayerInputComponent->BindAction("Fire", IE_Released, WeaponComponent, &USTDWeaponComponent::StopFire);
}

void ASTDBaseCharacter::MoveForward(float Amount) 
{
	IsMovingForward = Amount > 0.0f;
	AddMovementInput(GetActorForwardVector(), Amount);
}

void ASTDBaseCharacter::MoveRight(float Amount)
{
	if(Amount == 0.0f) return;
	AddMovementInput(GetActorRightVector(), Amount);
}




void ASTDBaseCharacter::OnStartRunning()
{
	 WantsToRun = true;
	//GetCharacterMovement()->MaxWalkSpeed = 1200.f;
	//UE_LOG(LogMovement, Warning, TEXT("SHIFT NAZHAT!!!!!!"));
}

void ASTDBaseCharacter::OnStopRunning()
{
	 WantsToRun = false;
	//GetCharacterMovement()->MaxWalkSpeed = 600.f;
	//UE_LOG(LogMovement, Warning, TEXT("SHIFT OTZHAT!!!!!!"));
}

bool ASTDBaseCharacter::IsRunning() const
{
    return WantsToRun && IsMovingForward && !GetVelocity().IsZero();
}

float ASTDBaseCharacter::GetMovementDirection() const
{
	if(GetVelocity().IsZero()) return 0.0f;
	const auto VelocityNormal = GetVelocity().GetSafeNormal();
	const auto AngleBetween = FMath::Acos(FVector::DotProduct(GetActorForwardVector(), VelocityNormal));
	const auto CrossProduct = FVector::CrossProduct(GetActorForwardVector(), VelocityNormal);
	const auto Degrees = FMath::RadiansToDegrees(AngleBetween);
    return CrossProduct.IsZero() ? Degrees : Degrees * FMath::Sign(CrossProduct.Z);
} 

void ASTDBaseCharacter::OnDeath() 
{
	UE_LOG(BaseCharacterLog, Warning, TEXT("Player %s is Dead"), *GetName());
	PlayAnimMontage(DeathAnimMontage);
	//WeaponComponent->StopFire();

	GetCharacterMovement()->DisableMovement();
	SetLifeSpan(LiveSpanOnDeath);
	if (Controller)
      {
          Controller->ChangeState(NAME_Spectating);
      }
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
}

void ASTDBaseCharacter::OnGroundLanded(const FHitResult& Hit)
{
    const auto FallVelocityZ = -GetVelocity().Z;
    UE_LOG(BaseCharacterLog, Display, TEXT ("On land speed is %f"), FallVelocityZ );

	if (FallVelocityZ < LandedDamageVelocity.X) return;

	const auto FinalDamage = FMath::GetMappedRangeValueClamped(LandedDamageVelocity, LandedDamage, FallVelocityZ);
	UE_LOG(BaseCharacterLog, Display, TEXT ("FinalDamage is %f"), FinalDamage );
	TakeDamage(FinalDamage, FDamageEvent{}, nullptr, nullptr);
}