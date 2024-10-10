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

	CurrentWeaponIndex = 0;
	SpawnWeapons();
	EquipWeapon(CurrentWeaponIndex);
}

void USTDWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    CurrentWeapon = nullptr;
	for (auto Weapon : Weapons)
	{
	    Weapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		Weapon->Destroy();
	}
	Weapons.Empty();

	Super::EndPlay(EndPlayReason);
}


void USTDWeaponComponent::SpawnWeapons()
{ 
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character || !GetWorld()) return;

	for (auto WeaponClass : WeaponClasses)
	{
	    auto Weapon = GetWorld()->SpawnActor<ASTDBaseWeapon>(WeaponClass);
	    if (!Weapon) continue;

	    Weapon->SetOwner(Character);
		Weapons.Add(Weapon);

		AttachWeaponToSocket(Weapon, Character->GetMesh(), WeaponArmorySocketName);
	}
}

void USTDWeaponComponent::AttachWeaponToSocket(ASTDBaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& SocketName)
{
	if (!Weapon || !SceneComponent) return;

    FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
    Weapon->AttachToComponent(SceneComponent, AttachmentRules, SocketName);
}

void USTDWeaponComponent::EquipWeapon(int32 WeaponIndex)
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character) return;

	if(CurrentWeapon)
	{
		CurrentWeapon->StopFire();
	    AttachWeaponToSocket(CurrentWeapon, Character->GetMesh(), WeaponArmorySocketName);
	}

	CurrentWeapon = Weapons[WeaponIndex];
	AttachWeaponToSocket(CurrentWeapon, Character->GetMesh(), WeaponEquipSocketName);
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

void USTDWeaponComponent::NextWeapon()
{
    CurrentWeaponIndex = (CurrentWeaponIndex + 1) % Weapons.Num();
	EquipWeapon(CurrentWeaponIndex);
}
