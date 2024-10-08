// ShootThemDown game. All rights reserved.

#include "Weapon/STDProjectile.h"
#include "Components/SphereComponent.h"

ASTDProjectile::ASTDProjectile()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	CollisionComponent->InitSphereRadius(5.0f);
	SetRootComponent(CollisionComponent);
}

void ASTDProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

