// Copyright Danny Kay


#include "LSEnemyController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "LooterShooterDemo/Characters/LSCharacter.h"

#pragma optimize("", off)

ALSEnemyController::ALSEnemyController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALSEnemyController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	SetFocus(PlayerPawn);

	// Random fire interval
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ALSEnemyController::FireAtPlayer, 2.0f, true, 1.0f);
}

void ALSEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerPawn)
	{
		MoveToActor(PlayerPawn, 200.f); // Move close to player
		SetFocus(PlayerPawn);
	}
}

void ALSEnemyController::FireAtPlayer()
{
	ALSCharacter* ControlledCharacter = Cast<ALSCharacter>(GetPawn());
	if (ControlledCharacter && PlayerPawn)
	{
		ControlledCharacter->FireWeapon();
	}
}

#pragma optimize("", on)
