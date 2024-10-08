// ShootThemDown game. All rights reserved.


#include "Weapon/STDLauncherWeapon.h"
#include "Weapon/STDProjectile.h"
#include "Kismet/GameplayStatics.h"


void ASTDLauncherWeapon::StartFire()
{
    MakeShot();
}

void ASTDLauncherWeapon::MakeShot()
{
    const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
    auto Projectile = UGameplayStatics::BeginDeferredActorSpawnFromClass(GetWorld(), ProjectileClass, SpawnTransform);
    // set projectile params

    UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);
}