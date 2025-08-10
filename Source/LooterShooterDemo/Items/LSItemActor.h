// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LooterShooterDemo/Data/LSItemData.h"
#include "LSItemActor.generated.h"

class UStaticMeshComponent;
class USkeletalMeshComponent;
class ULSItemStack;

UCLASS()
class LOOTERSHOOTERDEMO_API ALSItemActor : public AActor
{
	GENERATED_BODY()

public:
	ALSItemActor();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;

public:
	FItemData* GetItemData();
	void SetItemStack(ULSItemStack* InItemStack);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ItemActor")
	void StartPrimaryAction();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ItemActor")
	void StopPrimaryAction();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ItemActor")
	void StartSecondaryAction();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ItemActor")
	void StopSecondaryAction();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
	
	UPROPERTY(BlueprintReadOnly, Category = "Items")
	TObjectPtr<ULSItemStack> ItemStack;

	
};
