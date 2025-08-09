// Copyright Danny Kay


#include "LSCharacter.h"

#pragma optimize("", off)

ALSCharacter::ALSCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    Health = 100.f;
    bIsPlayerControlled = false;
}

void ALSCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ALSCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

#pragma optimize("", on)
