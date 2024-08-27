// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STDBaseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SHOOTTHEMDOWN_API ASTDBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASTDBaseCharacter(const FObjectInitializer& ObjInit);

protected:
	// Called when the game starts or when spawned	
	virtual void BeginPlay() override;

	UPROPERTY( VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY( VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION (BlueprintCallable, Category = "Movement")
		bool IsRunning() const;

	UFUNCTION (BlueprintCallable, Category = "Movement")
	float GetMovementDirection() const;

	private:
		bool WantsToRun = false;
		bool IsMovingForward = false;

		void MoveForward(float Amount);
		void MoveRight(float Amount);
		void OnStartRunning();
		void OnStopRunning();
};
