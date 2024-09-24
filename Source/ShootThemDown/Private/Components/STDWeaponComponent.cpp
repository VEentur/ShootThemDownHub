// ShootThemDown game. All rights reserved.

#include "Components/STDWeaponComponent.h"
#include "Weapon/STDBaseWeapon.h"
#include "GameFramework/Character.h"

USTDWeaponComponent::USTDWeaponComponent()
{
 	PrimaryComponentTick.bCanEverTick = false;
}


void USTDWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnWeapon();
}

void USTDWeaponComponent::SpawnWeapon()
{
    if (!GetWorld()) return;

	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if(!Character) return;

	CurrentWeapon = GetWorld()->SpawnActor<ASTDBaseWeapon>(WeaponClass);
	if (!CurrentWeapon) return;

;	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
      CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, WeaponAttachPointName);
}


void USTDWeaponComponent::Fire()
{
    if(!CurrentWeapon) return;
	CurrentWeapon->Fire();
}