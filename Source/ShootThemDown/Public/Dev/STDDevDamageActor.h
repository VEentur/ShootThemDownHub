// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STDDevDamageActor.generated.h"

UCLASS()
class SHOOTTHEMDOWN_API ASTDDevDamageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASTDDevDamageActor();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Radius = 300.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FColor SphereColor = FColor::Red;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Damage = 10.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool DoFullDamage = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<UDamageType> DamageType;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
