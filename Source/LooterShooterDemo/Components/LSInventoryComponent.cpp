// Copyright Danny Kay


#include "LSInventoryComponent.h"

#include "LSEquipmentComponent.h"
#include "LooterShooterDemo/LSDebugHelper.h"
#include "LooterShooterDemo/Items/LSItemStack.h"

#pragma optimize("", off)

ULSInventoryComponent::ULSInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULSInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

ULSItemStack* ULSInventoryComponent::FindItem(const FDataTableRowHandle& ItemData)
{
	ULSItemStack** Result = Items.FindByPredicate([&](ULSItemStack* Stack)
	{
		return Stack &&
			Stack->ItemData.DataTable == ItemData.DataTable &&
			Stack->ItemData.RowName == ItemData.RowName;
	});

	if (Result)
	{
		return *Result;
	}

	return nullptr;
}

ULSItemStack* ULSInventoryComponent::AddItem(const FDataTableRowHandle& ItemData, int32 Quantity)
{
	if (ItemData.IsNull())
	{
		LSDebug::Print(TEXT("Invalid ItemData passed to AddItem"));
		return nullptr;
	}

	// ULSItemStack* ExistingStack = FindItem(ItemData);
	// if (ExistingStack)
	// {
	// 	ExistingStack->Quantity += Quantity;
	// 	return ExistingStack;
	// }

	ULSItemStack* NewStack = NewObject<ULSItemStack>(this);
	if (NewStack)
	{
		NewStack->InitializeItem(ItemData, Quantity);
		Items.Add(NewStack);
	}

	FItemData* ItemStackData = NewStack->GetItemData();
	if (ItemStackData == nullptr)
	{
		return nullptr;
	}

	ULSEquipmentComponent* EquipmentComponent = GetOwner()->GetComponentByClass<ULSEquipmentComponent>();
	if (EquipmentComponent == nullptr)
	{
		return nullptr;
	}

	EquipmentComponent->EquipItem(ItemStackData);

	return NewStack;
}

bool ULSInventoryComponent::RemoveItem(ULSItemStack* ItemStack)
{
	if (ItemStack && Items.Contains(ItemStack))
	{
		Items.Remove(ItemStack);
		return true;
	}
	
	return false;
}

#pragma optimize("", on)
