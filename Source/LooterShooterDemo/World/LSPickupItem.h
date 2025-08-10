// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LooterShooterDemo/Interfaces/LSInteractInterface.h"
#include "LSPickupItem.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Weapon,
	Armor,
	Equipment
};

UCLASS()
class LOOTERSHOOTERDEMO_API ALSPickupItem : public AActor, public ILSInteractInterface
{
	GENERATED_BODY()

public:
	ALSPickupItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual FText GetDisplayName_Implementation() override;
	virtual UTexture2D* GetIcon_Implementation() override;
	virtual void OnInteract_Implementation(ALSCharacter* InteractingCharacter) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pickup")
	FDataTableRowHandle ItemRowHandle;
};
