// ShootThemDown game. All rights reserved.


#include "Weapon/STDBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include  "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"

DEFINE_LOG_CATEGORY_STATIC (LogBaseWeapon, All, All)

ASTDBaseWeapon::ASTDBaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);
}

void ASTDBaseWeapon::BeginPlay()
{
	Super::BeginPlay();

	check(WeaponMesh);

}

void ASTDBaseWeapon::StartFire()
{

}

void ASTDBaseWeapon::StopFire()
{

}





void ASTDBaseWeapon::MakeShot()
{

}

APlayerController* ASTDBaseWeapon::GetPlayerController() const
{
    const auto Player = Cast<ACharacter>(GetOwner());
	if (!Player) return nullptr;
	return Player->GetController<APlayerController>();
}

bool ASTDBaseWeapon::GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const
{
	const auto Controller = GetPlayerController();
	if(!Controller) return false;
    Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);
	return true;
}

FVector ASTDBaseWeapon::GetMuzzleWorldLocation() const
{
	return WeaponMesh->GetSocketLocation(MuzzleSocketName);
}

bool ASTDBaseWeapon::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
    FVector ViewLocation;
	FRotator ViewRotation;
	if(!GetPlayerViewPoint(ViewLocation, ViewRotation)) return false;

	TraceStart = ViewLocation;
	
	const FVector ShootDirection = ViewRotation.Vector();
	TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
	return true;
}

void ASTDBaseWeapon::MakeHit(FHitResult& HitResult, const FVector& TraceStart, FVector& TraceEnd)
{
	if(!GetWorld()) return;

    FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart,TraceEnd, ECC_Visibility, CollisionParams);
}