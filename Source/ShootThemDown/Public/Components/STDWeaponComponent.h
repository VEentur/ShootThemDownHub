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

protected:

	virtual void BeginPlay() override;

    UPROPERTY( EditDefaultsOnly, Category = "Weapon")
    FName WeaponAttachPointName = "WeaponSocket";

    UPROPERTY( EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<ASTDBaseWeapon> WeaponClass;

private:
    UPROPERTY()
    ASTDBaseWeapon* CurrentWeapon = nullptr;

    void SpawnWeapon();
};
