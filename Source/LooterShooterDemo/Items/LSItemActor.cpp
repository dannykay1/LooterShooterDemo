// Copyright Danny Kay


#include "LSItemActor.h"

#pragma optimize("", off)

ALSItemActor::ALSItemActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALSItemActor::BeginPlay()
{
	Super::BeginPlay();
}

void ALSItemActor::SetItemStack(ULSItemStack* InItemStack)
{
	if (InItemStack == nullptr)
	{
		return;
	}

	ItemStack = InItemStack;
}

#pragma optimize("", on)
