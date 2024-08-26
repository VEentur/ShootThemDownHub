// ShootThemDown game. All rights reserved.


#include "Components/STDCharacterMovementComponent.h"
#include "Player/STDBaseCharacter.h"

float USTDCharacterMovementComponent::GetMaxSpeed() const
{
  const float MaxSpeed = Super::GetMaxSpeed();
  const ASTDBaseCharacter* Player = Cast<ASTDBaseCharacter>(GetPawnOwner());

  return Player && Player-> IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
}
