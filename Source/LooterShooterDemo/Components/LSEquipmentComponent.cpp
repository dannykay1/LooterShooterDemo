// Copyright Danny Kay


#include "LSEquipmentComponent.h"
#include "Engine/AssetManager.h"
#include "LooterShooterDemo/LSDebugHelper.h"
#include "LooterShooterDemo/Items/LSItemActor.h"

#pragma optimize("", off)

ULSEquipmentComponent::ULSEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULSEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();
}

USkeletalMeshComponent* ULSEquipmentComponent::GetSkeletalMeshComponentFromOwner()
{
	AActor* MyOwner = GetOwner();
	if (MyOwner == nullptr)
	{
		return nullptr;
	}

	return MyOwner->GetComponentByClass<USkeletalMeshComponent>();
}

void ULSEquipmentComponent::EquipItem(FItemData* ItemData)
{
	if (ItemData == nullptr || ItemData->ItemActorClass.IsNull())
	{
		return;
	}

	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
		ItemData->ItemActorClass.ToSoftObjectPath(),
		FStreamableDelegate::CreateUObject(this, &ULSEquipmentComponent::OnItemClassLoaded, ItemData)
	);
}

void ULSEquipmentComponent::OnItemClassLoaded(FItemData* ItemData)
{	
	if (ItemData == nullptr || !ItemData->ItemActorClass.IsValid())
	{
		return;
	}

	USkeletalMeshComponent* SkeletalMeshComponent = GetSkeletalMeshComponentFromOwner();
	if (SkeletalMeshComponent == nullptr)
	{
		return;
	}

	AActor* MyOwner = GetOwner();
	FTransform SpawnTransform = SkeletalMeshComponent->GetSocketTransform(ItemData->SocketEquipName);

	ALSItemActor* Item = GetWorld()->SpawnActorDeferred<ALSItemActor>(
		ItemData->ItemActorClass.Get(),
		SpawnTransform,
		MyOwner,
		Cast<APawn>(MyOwner),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn
	);

	if (Item == nullptr)
	{
		return;
	}

	Item->SetItemStack(nullptr);
	Item->FinishSpawning(SpawnTransform);

	Item->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, ItemData->SocketEquipName);
}

#pragma optimize("", on)
