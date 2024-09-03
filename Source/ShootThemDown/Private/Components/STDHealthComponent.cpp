// ShootThemDown game. All rights reserved.


#include "Components/STDHealthComponent.h"
#include "GameFramework/Actor.h"

DEFINE_LOG_CATEGORY_STATIC (HealthComponentLog, All, All)


USTDHealthComponent::USTDHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void USTDHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	
	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USTDHealthComponent::OnTakeAnyDamage);
	}
}

void USTDHealthComponent::OnTakeAnyDamage(
	AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	Health -= Damage;
	UE_LOG(HealthComponentLog, Display, TEXT("Damage: %f"), Damage);
}