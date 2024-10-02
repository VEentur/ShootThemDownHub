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

	virtual void Fire();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FName MuzzleSocketName = "MuzzleSocket";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TraceMaxDistance = 1500.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float DamageAmount = 10.0f;


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* WeaponMesh;

	virtual void BeginPlay() override;

	void MakeShot();

	void MakeDamage(const FHitResult& HitResult);

	APlayerController* GetPlayerController() const;

	bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;

	FVector GetMuzzleWorldLocation() const;

	bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;

	void MakeHit(FHitResult& HitResult, const FVector& TraceStart, FVector& TraceEnd);

};
