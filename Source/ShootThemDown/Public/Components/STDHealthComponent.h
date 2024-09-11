// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STDHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float);



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHEMDOWN_API USTDHealthComponent : public UActorComponent
{
      GENERATED_BODY()

public:	

      USTDHealthComponent();

    FOnDeathSignature  OnDeath;
    FOnHealthChangedSignature OnHealthChanged;

    UFUNCTION(BlueprintCallable, Category = "Health")
    bool IsDead() const { return Health <=0.0f;}

    float GetHealth() const { return Health; }


protected:

      UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "1000.0"))
      float MaxHealth = 100;

      UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "AutoHeal"))
      float HealDelay = 3;

      UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "AutoHeal"))
      float HealRate = 0.5;

      UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "AutoHeal"))
      float HealValue = 2;

      UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal")
      bool AutoHeal = true;



      virtual void BeginPlay() override;

private:

      FTimerHandle HealRateHandle;
      void Healing();

      float Health = 0;
      
      UFUNCTION()
      void OnTakeAnyDamage(
AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};