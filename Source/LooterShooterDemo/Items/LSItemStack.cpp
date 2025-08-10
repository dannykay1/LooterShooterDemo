// Copyright Danny Kay


#include "LSItemStack.h"

#pragma optimize("", off)

ULSItemStack::ULSItemStack()
{
	Quantity = 0;
}

void ULSItemStack::InitializeItem(const FDataTableRowHandle& InItemData, int32 InQuantity)
{
	ItemData = InItemData;
	Quantity = InQuantity;
}

FItemData* ULSItemStack::GetItemData()
{
	if (ItemData.IsNull())
	{
		return nullptr;
	}

	return ItemData.GetRow<FItemData>("ItemStack Lookup");
}

#pragma optimize("", on)
