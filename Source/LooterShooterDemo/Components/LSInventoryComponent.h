// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LooterShooterDemo/Data/LSItemData.h"
#include "LSInventoryComponent.generated.h"

class ULSItemStack;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LOOTERSHOOTERDEMO_API ULSInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULSInventoryComponent();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Inventory")
	TArray<ULSItemStack*> Items;

	UFUNCTION(BlueprintCallable, Category="Inventory")
	ULSItemStack* FindItem(const FDataTableRowHandle& ItemData);
	
	UFUNCTION(BlueprintCallable, Category="Inventory")
	ULSItemStack* AddItem(const FDataTableRowHandle& ItemData, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	bool RemoveItem(ULSItemStack* ItemStack);
};
