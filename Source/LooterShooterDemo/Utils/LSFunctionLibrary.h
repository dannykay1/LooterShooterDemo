// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LooterShooterDemo/Data/LSItemData.h"
#include "LSFunctionLibrary.generated.h"

class UInteractResponseComponent;

UCLASS()
class LOOTERSHOOTERDEMO_API ULSFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "LS Function Library")
	static UInteractResponseComponent* GetInteractResponseComponent(AActor* SourceActor);

	static FItemData* GetItemData(AActor* SourceActor);

	UFUNCTION(BlueprintCallable, DisplayName = "Get Item Data", Category = "LS Function Library", meta = (ExpandBoolAsExecs = "ReturnValue"))
	static bool BP_GetItemData(AActor* SourceActor, FItemData& ItemData);
};
