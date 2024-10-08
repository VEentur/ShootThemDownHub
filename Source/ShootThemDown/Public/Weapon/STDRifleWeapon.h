// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STDBaseWeapon.h"
#include "STDRifleWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMDOWN_API ASTDRifleWeapon : public ASTDBaseWeapon
{
	GENERATED_BODY()

public:

    virtual void StartFire()override;
	virtual void StopFire() override;

protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeBetweenShots = 0.1f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float BulletSpread = 1.5f;

    virtual void MakeShot() override;
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;

private:
	FTimerHandle ShotTimerHandle;
};
