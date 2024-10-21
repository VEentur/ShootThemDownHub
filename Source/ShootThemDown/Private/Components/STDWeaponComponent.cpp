// ShootThemDown game. All rights reserved.

#include "Components/STDWeaponComponent.h"
#include "Weapon/STDBaseWeapon.h"
#include "GameFramework/Character.h"
#include "Animations/STD_EquipFinishedAnimNotify.h"

DEFINE_LOG_CATEGORY_STATIC (LogWeaponComponent, All, All);

USTDWeaponComponent::USTDWeaponComponent()
{
 	PrimaryComponentTick.bCanEverTick = false;
}

void USTDWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentWeaponIndex = 0;
	InitAnimations();
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

	for (auto OneWeaponData : WeaponData)
	{
	    auto Weapon = GetWorld()->SpawnActor<ASTDBaseWeapon>(OneWeaponData.WeaponClass);
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
    if (WeaponIndex < 0 || WeaponIndex >= Weapons.Num())
    {
    UE_LOG(LogWeaponComponent, Warning, TEXT("WeaponIndex NOT VALID"));
	}
    ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character) return;

	if(CurrentWeapon)
	{
		CurrentWeapon->StopFire();
	    AttachWeaponToSocket(CurrentWeapon, Character->GetMesh(), WeaponArmorySocketName);
	}

	CurrentWeapon = Weapons[WeaponIndex];
	//CurrentReloadAnimMontage = WeaponData[WeaponIndex].ReloadAnimMontage;
	const auto CurrentWeaponData = WeaponData.FindByPredicate([&](const FWeaponData& Data){ //
		return Data.WeaponClass == CurrentWeapon->GetClass();//
		});
	CurrentReloadAnimMontage = CurrentWeaponData ? CurrentWeaponData->ReloadAnimMontage : nullptr;

	AttachWeaponToSocket(CurrentWeapon, Character->GetMesh(), WeaponEquipSocketName);
	EquipAnimInProgress = true;
	PlayAnimMontage(EquipAnimMontage);
}


void USTDWeaponComponent::StartFire()
{
   if(!CanFire()) return;
	CurrentWeapon->StartFire();
}

void USTDWeaponComponent::StopFire()
{
	CurrentWeapon->StopFire();
}

void USTDWeaponComponent::NextWeapon()
{
	if(!CanEquip()) return;
    CurrentWeaponIndex = (CurrentWeaponIndex + 1) % Weapons.Num();
	EquipWeapon(CurrentWeaponIndex);
}

void USTDWeaponComponent::Reload()
{
	PlayAnimMontage(CurrentReloadAnimMontage);
}
 
void USTDWeaponComponent::PlayAnimMontage(UAnimMontage* Animation)
{
	    ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character) return;
	Character->PlayAnimMontage(Animation);
}

void USTDWeaponComponent::InitAnimations() 
{
	if (!EquipAnimMontage) return;

	const auto NotifyEvents = EquipAnimMontage->Notifies;
	for(auto NotifyEvent : NotifyEvents)
    {
    auto EquipFinishedNotify = Cast<USTD_EquipFinishedAnimNotify>(NotifyEvent.Notify);
	if(EquipFinishedNotify)
		{
		EquipFinishedNotify->OnNotified.AddUObject(this, &USTDWeaponComponent::OnEquipFinished);
		break;
		}
	}
}

void USTDWeaponComponent::OnEquipFinished(USkeletalMeshComponent* MeshComp)
{
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character || MeshComp != Character->GetMesh()) return;
	EquipAnimInProgress = false;
}

bool USTDWeaponComponent::CanFire() const
{
    return CurrentWeapon && !EquipAnimInProgress;
}

bool USTDWeaponComponent::CanEquip() const
{
    return !EquipAnimInProgress;
}
