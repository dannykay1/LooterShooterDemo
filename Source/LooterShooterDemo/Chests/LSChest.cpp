// Copyright Danny Kay


#include "LSChest.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "LooterShooterDemo/Pickups/LSPickupItem.h"

#pragma optimize("", off)

ALSChest::ALSChest()
{
	PrimaryActorTick.bCanEverTick = false;

	// Set default pickup class (make sure to assign your pickup BP in editor or code)
	PickupItemClass = ALSPickupItem::StaticClass();
}

void ALSChest::BeginPlay()
{
	Super::BeginPlay();
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
		if(SpawnedItem)
		{
			// Randomize item type per spawn
			int32 RandType = UKismetMathLibrary::RandomIntegerInRange(0, 2);
			SpawnedItem->ItemType = static_cast<EItemType>(RandType);
		}
	}

	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Chest spawned items"));
	}
}

#pragma optimize("", on)
