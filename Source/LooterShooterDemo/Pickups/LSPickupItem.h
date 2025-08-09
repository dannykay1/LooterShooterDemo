// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LSPickupItem.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Weapon,
	Armor,
	Equipment
};

UCLASS()
class LOOTERSHOOTERDEMO_API ALSPickupItem : public AActor
{
	GENERATED_BODY()

public:
	ALSPickupItem();

	// The type of this item (weapon, armor, etc)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	EItemType ItemType;

	// Example weapon stats (add more as you expand)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon Stats")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon Stats")
	float FireRate;

	// Example armor stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Armor Stats")
	float ArmorValue;

	// You can add more stats like sprint speed, health regen, etc.

	// Called when player picks this up
	void OnPickedUp();

protected:
	virtual void BeginPlay() override;
};
