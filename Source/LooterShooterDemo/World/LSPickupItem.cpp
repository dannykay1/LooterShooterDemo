// Copyright Danny Kay


#include "LSPickupItem.h"
#include "Engine/Engine.h"
#include "LooterShooterDemo/Characters/LSCharacter.h"
#include "LooterShooterDemo/Components/LSInventoryComponent.h"

#pragma optimize("", off)

ALSPickupItem::ALSPickupItem()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(GetRootComponent());

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());
}

void ALSPickupItem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	UpdateVisuals();
}

#if WITH_EDITOR
void ALSPickupItem::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName PropertyName = PropertyChangedEvent.Property ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(ALSPickupItem, ItemRowHandle))
	{
		UpdateVisuals();
	}
}
#endif

void ALSPickupItem::BeginPlay()
{
	Super::BeginPlay();
}

void ALSPickupItem::UpdateVisuals()
{
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

FItemData* ALSPickupItem::GetItemData()
{
	if (ItemRowHandle.IsNull())
	{
		return nullptr;
	}

	return ItemRowHandle.GetRow<FItemData>("Pickup Item Lookup");
}

FText ALSPickupItem::GetDisplayName_Implementation()
{
	FItemData* ItemData = GetItemData();
	if (ItemData)
	{
		return ItemData->DisplayName;
	}

	return FText::FromString("Pickup");
}

UTexture2D* ALSPickupItem::GetIcon_Implementation()
{
	FItemData* ItemData = GetItemData();
	if (ItemData)
	{
		return ItemData->Icon;
	}

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
