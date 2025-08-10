// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LooterShooterDemo/Data/LSItemData.h"
#include "LSEquipmentComponent.generated.h"

class ULSItemStack;
class ALSItemActor;
class USkeletalMeshComponent;

USTRUCT(BlueprintType)
struct FEquipmentSlot
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<ALSItemActor> ItemActor;
};

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
	void EquipItem(FItemData* ItemData);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EquipmentComponent")
	FEquipmentSlot CurrentEquippedSlot;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EquipmentComponent")
	FEquipmentSlot PrimarySlot;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EquipmentComponent")
	FEquipmentSlot SecondarySlot;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EquipmentComponent")
	FEquipmentSlot GrenadeSlot;
};
