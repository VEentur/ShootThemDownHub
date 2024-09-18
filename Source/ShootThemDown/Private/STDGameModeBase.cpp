// ShootThemDown game. All rights reserved.

#include "STDGameModeBase.h"
#include "Player/STDBaseCharacter.h"
#include "Player/STDPlayerController.h"
#include "UI/STDGameHUD.h"


ASTDGameModeBase::ASTDGameModeBase()
{
	DefaultPawnClass = ASTDBaseCharacter::StaticClass();
	PlayerControllerClass = ASTDPlayerController::StaticClass();
	HUDClass = ASTDGameHUD::StaticClass();
	
}