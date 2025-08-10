// Copyright Danny Kay


#include "LSPickupItem.h"
#include "Engine/Engine.h"
#include "LooterShooterDemo/Characters/LSCharacter.h"
#include "LooterShooterDemo/Components/LSInventoryComponent.h"

#pragma optimize("", off)

ALSPickupItem::ALSPickupItem()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALSPickupItem::BeginPlay()
{
	Super::BeginPlay();
}

FText ALSPickupItem::GetDisplayName_Implementation()
{
	return FText::FromString("Pickup");
}

UTexture2D* ALSPickupItem::GetIcon_Implementation()
{
	return nullptr;
}

void ALSPickupItem::OnInteract_Implementation(ALSCharacter* InteractingCharacter)
{	
	if (InteractingCharacter == nullptr)
	{
		return;
	}

	ULSInventoryComponent* InventoryComponent = InteractingCharacter->GetComponentByClass<ULSInventoryComponent>();
	if (InventoryComponent == nullptr)
	{
		return;
	}

	InventoryComponent->AddItem(ItemRowHandle);

	Destroy();
}

#pragma optimize("", on)
