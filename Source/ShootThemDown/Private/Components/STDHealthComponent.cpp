// ShootThemDown game. All rights reserved.


#include "Components/STDHealthComponent.h"
#include "GameFramework/Actor.h"


DEFINE_LOG_CATEGORY_STATIC (LogHealthComponent, All, All)


USTDHealthComponent::USTDHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void USTDHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	OnHealthChanged.Broadcast(Health);
	
	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USTDHealthComponent::OnTakeAnyDamage);
	}
}

void USTDHealthComponent::OnTakeAnyDamage(
	AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.0f || IsDead())
        return;

    Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
    OnHealthChanged.Broadcast(Health);

    if (IsDead())
        {
        OnDeath.Broadcast();
        }

  /*  if (GetWorld()->GetTimerManager().IsTimerActive(HealRateHandle))
        {
           GetWorld()->GetTimerManager().ClearTimer(HealRateHandle);
        }
        */  
    else if (AutoHeal && GetWorld())
        {
           GetWorld()->GetTimerManager().SetTimer(HealRateHandle, this, &USTDHealthComponent::Healing, HealRate, true, HealDelay);
        }
}

void USTDHealthComponent::Healing()
{

    if (Health >= MaxHealth || Health == 0 )
    {
        GetWorld()->GetTimerManager().ClearTimer(HealRateHandle);
        return;
    }

    Health = FMath::Clamp(Health + HealValue, 0.0f, MaxHealth);
    OnHealthChanged.Broadcast(Health);
    UE_LOG(LogHealthComponent, Warning, TEXT("Healing Is Active. Health = %f, Health tick is %f"), Health, HealValue);
       
}