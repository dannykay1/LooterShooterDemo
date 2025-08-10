// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LSFunctionLibrary.generated.h"

class ULSEquipmentComponent;
class ULSInventoryComponent;
class UInteractResponseComponent;

UCLASS()
class LOOTERSHOOTERDEMO_API ULSFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "LS Function Library")
	static UInteractResponseComponent* GetInteractResponseComponent(AActor* SourceActor);

	UFUNCTION(BlueprintCallable, Category = "LS Function Library")
	static ULSInventoryComponent* GetInventoryComponent(AActor* SourceActor);

	UFUNCTION(BlueprintCallable, Category = "LS Function Library")
	static ULSEquipmentComponent* GetEquipmentComponent(AActor* SourceActor);
};
