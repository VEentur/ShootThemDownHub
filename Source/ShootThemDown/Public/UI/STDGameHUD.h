// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "STDGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMDOWN_API ASTDGameHUD : public AHUD
{
	GENERATED_BODY()

public:

	virtual void DrawHUD() override;

private:

	void DrawCrossHair();
};
