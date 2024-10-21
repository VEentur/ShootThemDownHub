// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STDWeaponComponent.generated.h"


//DECLARE_MULTICAST_DELEGATE_OneParam(FWeaponHit, float);

class ASTDBaseWeapon;

USTRUCT(BlueprintType)
struct FWeaponData
{
    GENERATED_USTRUCT_BODY()

        UPROPERTY( EditDefaultsOnly, BlueprintReadWrite,  Category = "Weapon")
    TSubclassOf<ASTDBaseWeapon> WeaponClass;

    UPROPERTY( EditDefaultsOnly, BlueprintReadWrite,  Category = "Weapon")
    UAnimMontage* ReloadAnimMontage;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTTHEMDOWN_API USTDWeaponComponent : public UActorComponent
{
    GENERATED_BODY()
	
public:

	USTDWeaponComponent();

    void StartFire();
    void StopFire();
    void NextWeapon();
    void Reload();

protected:
    
    UPROPERTY( EditDefaultsOnly, Category = "Weapon")
    TArray<FWeaponData> WeaponData;

    UPROPERTY( EditDefaultsOnly, Category = "Weapon")
    FName WeaponEquipSocketName = "WeaponSocket";

    UPROPERTY( EditDefaultsOnly, Category = "Weapon")
    FName WeaponArmorySocketName = "ArmorySocket";

    UPROPERTY( EditDefaultsOnly, Category = "Animation")
    UAnimMontage* EquipAnimMontage;

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
private:
    UPROPERTY()
    ASTDBaseWeapon* CurrentWeapon = nullptr;

    UPROPERTY()
    TArray<ASTDBaseWeapon*> Weapons;

    UPROPERTY()
    UAnimMontage* CurrentReloadAnimMontage = nullptr;

    int32 CurrentWeaponIndex = 0;

    bool EquipAnimInProgress = false;

    void SpawnWeapons();

     void AttachWeaponToSocket(ASTDBaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& SocketName);
     void EquipWeapon(int32 WeaponIndex);

     void PlayAnimMontage(UAnimMontage* Animation);
     void InitAnimations(); // find and subscribe to AnimNotify
     void OnEquipFinished(USkeletalMeshComponent* MeshComp);  //callback to OnNotified delegate

     bool CanFire()const;
     bool CanEquip() const;

};
