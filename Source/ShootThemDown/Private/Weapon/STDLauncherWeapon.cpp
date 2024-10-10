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
    if(!GetWorld()) return;

	FVector TraceStart, TraceEnd;
	if(!GetTraceData(TraceStart, TraceEnd)) return;

	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);

    const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
    const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();

    const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
    ASTDProjectile* Projectile = GetWorld()->SpawnActorDeferred<ASTDProjectile>(ProjectileClass, SpawnTransform);
    if(Projectile)
    {
        Projectile->SetShotDirection(Direction);
        Projectile->SetOwner(GetOwner());
        Projectile->FinishSpawning(SpawnTransform);
    }
}