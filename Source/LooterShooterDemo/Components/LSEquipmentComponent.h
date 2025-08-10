// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LSEquipmentComponent.generated.h"

class ALSItemActor;
class USkeletalMeshComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LOOTERSHOOTERDEMO_API ULSEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULSEquipmentComponent();

protected:
	virtual void BeginPlay() override;
	USkeletalMeshComponent* GetSkeletalMeshComponentFromOwner();

public:
	void EquipItem(TSoftClassPtr<ALSItemActor> ItemClassToEquip);
	void OnItemClassLoaded(TSoftClassPtr<ALSItemActor> LoadedItemClass);
	
	UPROPERTY(BlueprintReadOnly, Category = "EquipmentComponent")
	TArray<TObjectPtr<ALSItemActor>> EquippedItems;
};
