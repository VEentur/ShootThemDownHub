// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STDBaseWeapon.generated.h"



class USkeletalMeshComponent;


UCLASS()
class SHOOTTHEMDOWN_API ASTDBaseWeapon : public AActor
{
	GENERATED_BODY()
	  
public:	
	ASTDBaseWeapon();

	virtual void StartFire();
	virtual void StopFire();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName MuzzleSocketName = "MuzzleSocket";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TraceMaxDistance = 1500.0f;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* WeaponMesh;

	virtual void BeginPlay() override;

	virtual void MakeShot();
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;

	APlayerController* GetPlayerController() const;

	bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;

	FVector GetMuzzleWorldLocation() const;



	void MakeHit(FHitResult& HitResult, const FVector& TraceStart, FVector& TraceEnd);

};
