// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STDBaseWeapon.h"
#include "STDLauncherWeapon.generated.h"

class ASTDProjectile;

UCLASS()

class SHOOTTHEMDOWN_API ASTDLauncherWeapon : public ASTDBaseWeapon
{
	GENERATED_BODY()

public:

	virtual void StartFire() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<ASTDProjectile> ProjectileClass;

	virtual void MakeShot() override;

};
