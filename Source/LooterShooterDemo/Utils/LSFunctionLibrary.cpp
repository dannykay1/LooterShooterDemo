// Copyright Danny Kay


#include "LSFunctionLibrary.h"
#include "LooterShooterDemo/Components/InteractResponseComponent.h"

#pragma optimize("", on)

UInteractResponseComponent* ULSFunctionLibrary::GetInteractResponseComponent(AActor* SourceActor)
{
	if (SourceActor)
	{
		return nullptr;
	}
	
	return SourceActor->GetComponentByClass<UInteractResponseComponent>();
}

FItemData* ULSFunctionLibrary::GetItemData(AActor* SourceActor)
{
	if (UInteractResponseComponent* InteractResponseComponent = GetInteractResponseComponent(SourceActor))
	{
		return InteractResponseComponent->GetItemData();
	}

	return nullptr;
}

bool ULSFunctionLibrary::BP_GetItemData(AActor* SourceActor, FItemData& ItemData)
{
	if (FItemData* Data = GetItemData(SourceActor))
	{
		ItemData = *Data;
		return true;
	}

	ItemData = FItemData();
	return false;
}

#pragma optimize("", on)
