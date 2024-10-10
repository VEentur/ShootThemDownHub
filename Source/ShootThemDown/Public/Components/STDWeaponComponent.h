// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STDWeaponComponent.generated.h"


//DECLARE_MULTICAST_DELEGATE_OneParam(FWeaponHit, float);

class ASTDBaseWeapon;

UCLASS()
class SHOOTTHEMDOWN_API USTDWeaponComponent : public UActorComponent
{GENERATED_BODY()
	
public:

	USTDWeaponComponent();

    void StartFire();
    void StopFire();
    void NextWeapon();

protected:
    
    UPROPERTY( EditDefaultsOnly, Category = "Weapon")
    FName WeaponEquipSocketName = "WeaponSocket";

    UPROPERTY( EditDefaultsOnly, Category = "Weapon")
    TArray<TSubclassOf<ASTDBaseWeapon>> WeaponClasses;

    UPROPERTY( EditDefaultsOnly, Category = "Weapon")
    FName WeaponArmorySocketName = "ArmorySocket";

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
private:
    UPROPERTY()
    ASTDBaseWeapon* CurrentWeapon = nullptr;

    UPROPERTY()
    TArray<ASTDBaseWeapon*> Weapons;

    int32 CurrentWeaponIndex = 0;

    void SpawnWeapons();

     void AttachWeaponToSocket(ASTDBaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& SocketName);
     void EquipWeapon(int32 WeaponIndex);
};
