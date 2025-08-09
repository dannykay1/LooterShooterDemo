// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LooterShooterDemo/Interfaces/LSInteractInterface.h"
#include "LSChest.generated.h"

UCLASS()
class LOOTERSHOOTERDEMO_API ALSChest : public AActor, public ILSInteractInterface
{
	GENERATED_BODY()

public:
	ALSChest();

	void SpawnRandomItems();

protected:
	virtual void BeginPlay() override;

public:	
	virtual FText GetDisplayName_Implementation() override;
	virtual UTexture2D* GetIcon_Implementation() override;
	virtual void OnInteract_Implementation(ALSCharacter* InteractingCharacter) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Chest")
	TSubclassOf<class ALSPickupItem> PickupItemClass;

	// Number of items to spawn per chest
	UPROPERTY(EditDefaultsOnly, Category="Chest")
	int32 ItemsToSpawn = 3;
};
