// Copyright Danny Kay


#include "LSInputConfig.h"

#pragma optimize("", off)

ULSInputConfig::ULSInputConfig()
{
}

UInputAction* ULSInputConfig::FindInputActionByTag(const FGameplayTag& InInputTag)
{
	FInputActionConfig* Result = InputActions.FindByPredicate([InInputTag](const FInputActionConfig& Config)
	{
		return Config.IsValid() && Config.InputTag == InInputTag;
	});

	if (Result && Result->IsValid())
	{
		return Result->InputAction;
	}

	return nullptr;
}

#pragma optimize("", on)
