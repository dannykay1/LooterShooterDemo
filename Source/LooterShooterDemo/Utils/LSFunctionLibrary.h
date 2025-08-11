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
	static ULSInventoryComponent* GetInventoryComponent(AActor* SourceActor);

	UFUNCTION(BlueprintPure, Category = "LS Function Library")
	static bool GetPlayerEyesViewPoint(AActor* Player, FVector& OutLocation, FRotator& OutRotation);

	UFUNCTION(BlueprintPure, Category = "LS Function Library")
	static AActor* GetCurrentInteractable(AActor* Player);
};
