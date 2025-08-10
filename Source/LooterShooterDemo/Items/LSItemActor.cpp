// Copyright Danny Kay


#include "LSItemActor.h"
#include "LSItemStack.h"
#include "LooterShooterDemo/LSDebugHelper.h"

#pragma optimize("", off)

ALSItemActor::ALSItemActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(GetRootComponent());

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());
}

void ALSItemActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	FItemData* ItemData = GetItemData();
	if (ItemData == nullptr)
	{
		return;
	}

	if (StaticMeshComponent && ItemData->StaticMesh)
	{
		StaticMeshComponent->SetStaticMesh(ItemData->StaticMesh);
		StaticMeshComponent->SetVisibility(true);
		SkeletalMeshComponent->SetVisibility(false);
	}
	else if (SkeletalMeshComponent && ItemData->SkeletalMesh)
	{
		SkeletalMeshComponent->SetSkeletalMesh(ItemData->SkeletalMesh);
		SkeletalMeshComponent->SetVisibility(true);
		StaticMeshComponent->SetVisibility(false);
	}
}

void ALSItemActor::BeginPlay()
{
	Super::BeginPlay();
}

FItemData* ALSItemActor::GetItemData()
{
	if (ItemStack == nullptr)
	{
		return nullptr;
	}

	return ItemStack->GetItemData();
}

void ALSItemActor::SetItemStack(ULSItemStack* InItemStack)
{
	if (InItemStack == nullptr)
	{
		return;
	}

	ItemStack = InItemStack;
}

void ALSItemActor::StartPrimaryAction_Implementation()
{
	LSDebug::Print(TEXT("Start Primary Action"));
}

void ALSItemActor::StopPrimaryAction_Implementation()
{
	LSDebug::Print(TEXT("Stop Primary Action"));
}

void ALSItemActor::StartSecondaryAction_Implementation()
{
	LSDebug::Print(TEXT("Start Secondary Action"));
}

void ALSItemActor::StopSecondaryAction_Implementation()
{
	LSDebug::Print(TEXT("Stop Secondary Action"));
}

#pragma optimize("", on)
