// ShootThemDown game. All rights reserved.


#include "Components/STDHealthComponent.h"


USTDHealthComponent::USTDHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void USTDHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	
}
