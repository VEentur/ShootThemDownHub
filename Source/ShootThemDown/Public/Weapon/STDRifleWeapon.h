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

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TimeBetweenShots = 0.1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float BulletSpread = 1.5f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DamageAmount = 10.0f;

    virtual void MakeShot() override;
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;

private:
	FTimerHandle ShotTimerHandle;
	void MakeDamage(const FHitResult& HitResult);
};
