// ShootThemDown game. All rights reserved.


#include "Player/STDBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

DEFINE_LOG_CATEGORY_STATIC (LogMovement, All, All)

// Sets default values
ASTDBaseCharacter::ASTDBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void ASTDBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

	PlayerInputComponent->BindAxis("MoveForward", this, &ASTDBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASTDBaseCharacter::MoveRight);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ASTDBaseCharacter::RunOn);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &ASTDBaseCharacter::RunOff);

	PlayerInputComponent->BindAxis("LookUp", this, &ASTDBaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &ASTDBaseCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASTDBaseCharacter::Jump);
}

void ASTDBaseCharacter::MoveForward(float Amount) 
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void ASTDBaseCharacter::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}

void ASTDBaseCharacter::RunOn() 
{
	GetCharacterMovement()->MaxWalkSpeed = 1200.f;
	
	UE_LOG(LogMovement, Warning, TEXT("SHIFT NAZHAT!!!!!!"));
}

void ASTDBaseCharacter::RunOff() 
{
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	
	UE_LOG(LogMovement, Warning, TEXT("SHIFT OTZHAT!!!!!!"));
}