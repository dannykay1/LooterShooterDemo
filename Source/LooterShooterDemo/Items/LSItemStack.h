// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LooterShooterDemo/Data/LSItemData.h"
#include "LSItemStack.generated.h"

UCLASS(BlueprintType)
class LOOTERSHOOTERDEMO_API ULSItemStack : public UObject
{
	GENERATED_BODY()
	
public:
	ULSItemStack();

	UFUNCTION(BlueprintCallable, Category = "Items")
	void InitializeItem(const FDataTableRowHandle& InItemData, int32 InQuantity = 1);

	FItemData* GetItemData();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FDataTableRowHandle ItemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	int32 Quantity;
	
	
};
