// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STDHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float)



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHEMDOWN_API USTDHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	USTDHealthComponent();

	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable)

	bool IsDead() const { return Health <=0.0f;}

	FOnDeath  OnDeath;
	FOnHealthChanged OnHealthChanged;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "1000.0"))
	float MaxHealth = 100;

	virtual void BeginPlay() override;

private:

	float Health = 0;
	
	UFUNCTION()
	void OnTakeAnyDamage(
		AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};
