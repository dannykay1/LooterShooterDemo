// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LSInteractInterface.generated.h"

class ALSCharacter;
class UTexture2D;

// This class does not need to be modified.
UINTERFACE()
class ULSInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LOOTERSHOOTERDEMO_API ILSInteractInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	FText GetDisplayName();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	UTexture2D* GetIcon();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteract(ALSCharacter* InteractingCharacter);
};
