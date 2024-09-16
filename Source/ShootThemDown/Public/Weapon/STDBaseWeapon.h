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

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* WeaponMesh;



	virtual void BeginPlay() override;


};
