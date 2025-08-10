// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LooterShooterDemo/Data/LSItemData.h"
#include "LSInventoryComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LOOTERSHOOTERDEMO_API ULSInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULSInventoryComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void AddItem(const FItemData& ItemToAdd);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	bool RemoveItem(const FItemData& ItemToRemove);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Inventory")
	TArray<FItemData> Items;
};
