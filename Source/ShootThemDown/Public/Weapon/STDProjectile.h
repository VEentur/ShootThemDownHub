// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "STDProjectile.generated.h"

class USphereComponent;

UCLASS()
class SHOOTTHEMDOWN_API ASTDProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ASTDProjectile();

protected:

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	USphereComponent* CollisionComponent;

	virtual void BeginPlay() override;
};
