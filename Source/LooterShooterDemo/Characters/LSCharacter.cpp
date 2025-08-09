// Copyright Danny Kay


#include "LSCharacter.h"
#include "LooterShooterDemo/LSDebugHelper.h"

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

void ALSCharacter::Interact()
{
	LSDebug::Print(TEXT("Interacted!"));
}

void ALSCharacter::FireWeapon()
{
	LSDebug::Print(TEXT("Bang! Enemy Fired!"));
}

#pragma optimize("", on)
