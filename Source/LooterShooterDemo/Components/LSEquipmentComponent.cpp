// Copyright Danny Kay


#include "LSEquipmentComponent.h"
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
	if (ItemData == nullptr || !ItemData->ItemActorClass)
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

	ALSItemActor* ItemActor = GetWorld()->SpawnActorDeferred<ALSItemActor>(
		ItemData->ItemActorClass,
		SpawnTransform,
		MyOwner,
		Cast<APawn>(MyOwner),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn
	);

	if (ItemActor == nullptr)
	{
		return;
	}

	ItemActor->SetItemStack(nullptr);
	ItemActor->FinishSpawning(SpawnTransform);

	ItemActor->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, ItemData->SocketEquipName);

	PrimarySlot.ItemActor = ItemActor;
}

#pragma optimize("", on)
