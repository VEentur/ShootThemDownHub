// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "STDCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMDOWN_API USTDCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	public:
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement", 
				  meta = (ClampMin = "1.5", ClampMax = "10.0"))
		float RunModifier = 2.0f;

	virtual float GetMaxSpeed() const override;
	
};
