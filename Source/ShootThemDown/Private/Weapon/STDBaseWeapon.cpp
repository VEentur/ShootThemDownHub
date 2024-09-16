// ShootThemDown game. All rights reserved.


#include "Weapon/STDBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"

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


