// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "LSInputConfig.generated.h"

class UInputMappingContext;
class UInputAction;

USTRUCT(BlueprintType)
struct FInputActionConfig
{
	GENERATED_BODY()

	FInputActionConfig()
	{
	}

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputAction;

	bool IsValid() const { return InputTag.IsValid() && InputAction; }
};

UCLASS()
class LOOTERSHOOTERDEMO_API ULSInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	ULSInputConfig();

	UInputAction* FindInputActionByTag(const FGameplayTag& InInputTag);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FInputActionConfig> InputActions;
};
