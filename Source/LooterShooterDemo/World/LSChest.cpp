// Copyright Danny Kay


#include "LSChest.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "LooterShooterDemo/LSDebugHelper.h"
#include "LooterShooterDemo/World/LSPickupItem.h"

#pragma optimize("", off)

ALSChest::ALSChest()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALSChest::BeginPlay()
{
	Super::BeginPlay();
}

FText ALSChest::GetDisplayName_Implementation()
{
	return FText::FromString("Chest");
}

UTexture2D* ALSChest::GetIcon_Implementation()
{
	return nullptr;
}

void ALSChest::OnInteract_Implementation(ALSCharacter* InteractingCharacter)
{
	SpawnRandomItems();
}

void ALSChest::SpawnRandomItems()
{
	if(!PickupItemClass) return;

	for(int32 i = 0; i < ItemsToSpawn; i++)
	{
		FVector SpawnOffset = FVector(
			UKismetMathLibrary::RandomFloatInRange(-150.f, 150.f),
			UKismetMathLibrary::RandomFloatInRange(-150.f, 150.f),
			50.f);

		FVector SpawnLocation = GetActorLocation() + SpawnOffset;
		FRotator SpawnRotation = FRotator::ZeroRotator;

		ALSPickupItem* SpawnedItem = GetWorld()->SpawnActor<ALSPickupItem>(PickupItemClass, SpawnLocation, SpawnRotation);
	}

	LSDebug::Print(TEXT("Chest spawned items"));
}

#pragma optimize("", on)
