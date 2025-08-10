// Copyright Danny Kay


#include "LSItemStack.h"

#pragma optimize("", off)

ULSItemStack::ULSItemStack()
{
	Quantity = 0;
}

void ULSItemStack::InitializeItem(const FDataTableRowHandle& InItemData, int32 InQuantity)
{
	ItemRowHandle = InItemData;
	Quantity = InQuantity;
}

FItemData* ULSItemStack::GetItemData()
{
	if (ItemRowHandle.IsNull())
	{
		return nullptr;
	}

	return ItemRowHandle.GetRow<FItemData>("ItemStack Lookup");
}

#pragma optimize("", on)
