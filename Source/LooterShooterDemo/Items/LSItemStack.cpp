// Copyright Danny Kay


#include "LSItemStack.h"

#pragma optimize("", off)

ULSItemStack::ULSItemStack()
{
	Quantity = 0;
}

FItemData* ULSItemStack::GetItemData()
{
	if (ItemRowHandle.IsNull())
	{
		return nullptr;
	}

	return ItemRowHandle.GetRow<FItemData>("ItemStack Lookup");
}

ULSInputConfig* ULSItemStack::GetInputConfig()
{
	FItemData* ItemData = GetItemData();
	if (ItemData == nullptr)
	{
		return nullptr;
	}

	return ItemData->InputConfig;
}

void ULSItemStack::InitializeItem(const FDataTableRowHandle& InItemData, int32 InQuantity)
{
	ItemRowHandle = InItemData;
	Quantity = InQuantity;
}

#pragma optimize("", on)
