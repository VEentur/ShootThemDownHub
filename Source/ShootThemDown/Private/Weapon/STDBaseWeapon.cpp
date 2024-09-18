// ShootThemDown game. All rights reserved.


#include "Weapon/STDBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"

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
	
}


void ASTDBaseWeapon::Fire()
{
    UE_LOG(LogBaseWeapon, Display, TEXT("Fire!"));
}  