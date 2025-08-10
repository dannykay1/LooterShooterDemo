// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LooterShooterDemo/Data/LSItemData.h"
#include "LooterShooterDemo/Interfaces/LSInteractInterface.h"
#include "LSPickupItem.generated.h"

class UStaticMeshComponent;
class USkeletalMeshComponent;

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
	virtual void OnConstruction(const FTransform& Transform) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	virtual void BeginPlay() override;
	void UpdateVisuals();

public:
	FItemData* GetItemData();
	virtual FText GetDisplayName_Implementation() override;
	virtual UTexture2D* GetIcon_Implementation() override;
	virtual void OnInteract_Implementation(ALSCharacter* InteractingCharacter) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pickup", meta = (RowType = "FItemData"))
	FDataTableRowHandle ItemRowHandle;
};
