// Copyright Danny Kay


#include "LSCharacter.h"

#include "Camera/CameraComponent.h"
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

FVector ALSCharacter::GetPawnViewLocation() const
{
	UCameraComponent* CameraComponent = GetComponentByClass<UCameraComponent>();
	if (CameraComponent)
	{
		return CameraComponent->GetComponentLocation();
	}

	return Super::GetPawnViewLocation();
}

FRotator ALSCharacter::GetViewRotation() const
{
	UCameraComponent* CameraComponent = GetComponentByClass<UCameraComponent>();
	if (CameraComponent)
	{
		return CameraComponent->GetComponentRotation();
	}

	return Super::GetViewRotation();
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
