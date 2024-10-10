// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "STDProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class SHOOTTHEMDOWN_API ASTDProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ASTDProjectile();

	void SetShotDirection(const FVector& Direction) { ShotDirection = Direction;}

protected:
		UPROPERTY(VisibleAnywhere, Category = "Weapon")
	USphereComponent* CollisionComponent;

		UPROPERTY(VisibleAnywhere, Category = "Weapon")
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon");
	float DamageRadius = 200.0f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon");
	float DamageAmount = 100.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon");
	bool DoFullDamage = false;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon");
	float LifeSeconds = 5.0f;

	virtual void BeginPlay() override;

private:
	FVector ShotDirection;

	UFUNCTION()
	void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	const FHitResult& Hit);

	AController* GetController() const;
};
