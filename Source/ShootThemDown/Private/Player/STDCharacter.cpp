// ShootThemDown game. All rights reserved.


#include "Player/STDCharacter.h"

// Sets default values
ASTDCharacter::ASTDCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASTDCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASTDCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASTDCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

