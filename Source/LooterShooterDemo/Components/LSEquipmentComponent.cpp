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

void ULSEquipmentComponent::EquipItem(TSoftClassPtr<ALSItemActor> ItemClassToEquip)
{
	if (ItemClassToEquip.IsNull())
	{
		return;
	}

	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
		ItemClassToEquip.ToSoftObjectPath(),
		FStreamableDelegate::CreateUObject(this, &ULSEquipmentComponent::OnItemClassLoaded, ItemClassToEquip)
	);
}

void ULSEquipmentComponent::OnItemClassLoaded(TSoftClassPtr<ALSItemActor> LoadedItemClass)
{
	if (!LoadedItemClass.IsValid())
	{
		LSDebug::Print(TEXT("Failed to async load item class"));
		return;
	}

	USkeletalMeshComponent* SkeletalMeshComponent = GetSkeletalMeshComponentFromOwner();
	if (SkeletalMeshComponent == nullptr)
	{
		return;
	}

	AActor* MyOwner = GetOwner();
	FTransform SpawnTransform = SkeletalMeshComponent->GetSocketTransform("Rifle");

	ALSItemActor* Item = GetWorld()->SpawnActorDeferred<ALSItemActor>(
		LoadedItemClass.Get(),
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
}

#pragma optimize("", on)
