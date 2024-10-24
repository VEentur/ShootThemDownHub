// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STDBaseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USTDHealthComponent;
class UTextRenderComponent;
class USTDWeaponComponent;

UCLASS()
class SHOOTTHEMDOWN_API ASTDBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASTDBaseCharacter(const FObjectInitializer& ObjInit);

protected:

	UPROPERTY( VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY( VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;


	UPROPERTY( VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USTDHealthComponent* HealthComponent;

	UPROPERTY( VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UTextRenderComponent* HealthTextComponent;

    UPROPERTY( VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USTDWeaponComponent* WeaponComponent;

	UPROPERTY( EditDefaultsOnly, Category = "Animation")
	UAnimMontage* DeathAnimMontage;

	UPROPERTY( EditDefaultsOnly, Category = "Damage")
	float LiveSpanOnDeath = 5.0f;

	UPROPERTY( EditDefaultsOnly, Category = "Damage")
    FVector2D LandedDamageVelocity = FVector2D(900.0f, 1400.0f);

	UPROPERTY( EditDefaultsOnly, Category = "Damage")
	FVector2D LandedDamage = FVector2D(10.0f, 100.0f);

	virtual void BeginPlay() override;

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
		void OnDeath();
		void OnHealthChanged(float Health);
	UFUNCTION()
		void OnGroundLanded(const FHitResult& Hit);
};