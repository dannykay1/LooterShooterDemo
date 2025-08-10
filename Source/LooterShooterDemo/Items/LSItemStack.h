// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LSItemStack.generated.h"

UCLASS(BlueprintType)
class LOOTERSHOOTERDEMO_API ULSItemStack : public UObject
{
	GENERATED_BODY()
	
public:
	ULSItemStack();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FDataTableRowHandle ItemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantity;
	
	UFUNCTION(BlueprintCallable, Category = "Item")
	void InitializeItem(const FDataTableRowHandle& InItemData, int32 InQuantity = 1);
};
