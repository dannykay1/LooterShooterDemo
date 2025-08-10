// Copyright Danny Kay


#include "LSFunctionLibrary.h"
#include "LooterShooterDemo/Components/InteractResponseComponent.h"
#include "LooterShooterDemo/Components/LSInventoryComponent.h"
#include "LooterShooterDemo/Components/LSEquipmentComponent.h"

#pragma optimize("", on)

UInteractResponseComponent* ULSFunctionLibrary::GetInteractResponseComponent(AActor* SourceActor)
{
	if (SourceActor)
	{
		return nullptr;
	}

	return SourceActor->GetComponentByClass<UInteractResponseComponent>();
}

ULSInventoryComponent* ULSFunctionLibrary::GetInventoryComponent(AActor* SourceActor)
{
	if (SourceActor)
	{
		return nullptr;
	}

	return SourceActor->GetComponentByClass<ULSInventoryComponent>();
}

ULSEquipmentComponent* ULSFunctionLibrary::GetEquipmentComponent(AActor* SourceActor)
{
	if (SourceActor)
	{
		return nullptr;
	}

	return SourceActor->GetComponentByClass<ULSEquipmentComponent>();
}

#pragma optimize("", on)
