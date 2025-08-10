// Copyright Danny Kay


#include "InteractResponseComponent.h"

#pragma optimize("", off)

UInteractResponseComponent::UInteractResponseComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractResponseComponent::BeginPlay()
{
	Super::BeginPlay();
}

FItemData* UInteractResponseComponent::GetItemData()
{
	return ItemRowHandle.GetRow<FItemData>("InteractComponent Lookup");
}

void UInteractResponseComponent::Interact()
{
	FItemData* ItemData = GetItemData();
	if (ItemData == nullptr)
	{
		return;
	}

	OnInteract.Broadcast(*ItemData);
}

#pragma optimize("", on)
