// ShootThemDown game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "STD_EquipFinishedAnimNotify.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnNotifiedSignature, USkeletalMeshComponent*);

UCLASS()
class SHOOTTHEMDOWN_API USTD_EquipFinishedAnimNotify : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	FOnNotifiedSignature OnNotified;
};
