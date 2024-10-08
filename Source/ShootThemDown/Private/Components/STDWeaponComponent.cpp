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
	//CurrentWeapon->WeaponHit.AddUObject(this, ApplyWeaponDamage);
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
	CurrentWeapon->SetOwner(Character);
}


void USTDWeaponComponent::StartFire()
{
    if(!CurrentWeapon) return;
	CurrentWeapon->StartFire();
}

void USTDWeaponComponent::StopFire()
{
	CurrentWeapon->StopFire();
}