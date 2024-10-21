// ShootThemDown game. All rights reserved.


#include "Animations/STD_EquipFinishedAnimNotify.h"

void USTD_EquipFinishedAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	OnNotified.Broadcast(MeshComp);
Super::Notify(MeshComp, Animation);
}
