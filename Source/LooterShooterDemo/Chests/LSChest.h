// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LSChest.generated.h"

UCLASS()
class LOOTERSHOOTERDEMO_API ALSChest : public AActor
{
	GENERATED_BODY()

public:
	ALSChest();

	void SpawnRandomItems();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Chest")
	TSubclassOf<class ALSPickupItem> PickupItemClass;

	// Number of items to spawn per chest
	UPROPERTY(EditDefaultsOnly, Category="Chest")
	int32 ItemsToSpawn = 3;
};
