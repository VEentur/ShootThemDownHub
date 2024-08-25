// ShootThemDown game. All rights reserved.

#include "STDGameModeBase.h"
#include "Player/STDBaseCharacter.h"
#include "Player/STDPlayerController.h"


ASTDGameModeBase::ASTDGameModeBase()
{
	DefaultPawnClass = ASTDBaseCharacter::StaticClass();
	PlayerControllerClass = ASTDPlayerController::StaticClass();

}