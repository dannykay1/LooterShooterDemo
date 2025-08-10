// Copyright Danny Kay


#include "LSInventoryComponent.h"

#pragma optimize("", off)

ULSInventoryComponent::ULSInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULSInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void ULSInventoryComponent::AddItem(const FItemData& ItemToAdd)
{
	Items.Add(ItemToAdd);
}

bool ULSInventoryComponent::RemoveItem(const FItemData& ItemToRemove)
{
	if (Items.Contains(ItemToRemove))
	{
		Items.RemoveSingle(ItemToRemove);
		return true;
	}
	
	return false;
}

#pragma optimize("", on)
