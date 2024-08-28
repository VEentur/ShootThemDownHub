// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STDHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHEMDOWN_API USTDHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	USTDHealthComponent();

	float GetHealth() const { return Health; }

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "1000.0"))
	float MaxHealth = 100;

	virtual void BeginPlay() override;

private:

	float Health = 0;

};
