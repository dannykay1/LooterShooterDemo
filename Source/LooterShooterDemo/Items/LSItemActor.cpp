// Copyright Danny Kay


#include "LSItemActor.h"

#include "EnhancedInputSubsystems.h"
#include "LSItemStack.h"
#include "LooterShooterDemo/LSDebugHelper.h"
#include "LooterShooterDemo/Controllers/LSPlayerController.h"
#include "LooterShooterDemo/Data/LSInputConfig.h"

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

ULSInputConfig* ALSItemActor::GetInputConfig()
{
	if (ItemStack == nullptr)
	{
		return nullptr;
	}

	return ItemStack->GetInputConfig();
}

void ALSItemActor::SetItemStack(ULSItemStack* InItemStack)
{
	if (InItemStack == nullptr)
	{
		return;
	}

	ItemStack = InItemStack;
}

void ALSItemActor::SetupInput(ALSPlayerController* PlayerController)
{
	if (PlayerController == nullptr)
	{
		return;
	}

	ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
	if (LocalPlayer == nullptr)
	{
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	if (Subsystem == nullptr)
	{
		return;
	}

	ULSInputConfig* InputConfig = GetInputConfig();
	if (InputConfig == nullptr)
	{
		return;
	}

	Subsystem->AddMappingContext(InputConfig->DefaultMappingContext, 1);
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
