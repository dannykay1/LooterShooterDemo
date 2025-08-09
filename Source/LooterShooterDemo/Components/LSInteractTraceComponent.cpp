// Copyright Danny Kay


#include "LSInteractTraceComponent.h"
#include "Blueprint/UserWidget.h"
#include "LooterShooterDemo/Chests/LSChest.h"
#include "LooterShooterDemo/Pickups/LSPickupItem.h"

#pragma optimize("", off)

ULSInteractTraceComponent::ULSInteractTraceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void ULSInteractTraceComponent::BeginPlay()
{
	Super::BeginPlay();

	if (InteractionWidgetClass)
	{
		InteractionWidget = CreateWidget<UUserWidget>(GetOwnerPawnController(), InteractionWidgetClass);
		if (InteractionWidget)
		{
			InteractionWidget->AddToViewport();
			InteractionWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void ULSInteractTraceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	CheckForInteractable();
}

APawn* ULSInteractTraceComponent::GetOwnerPawn()
{
	return Cast<APawn>(GetOwner());
}

APlayerController* ULSInteractTraceComponent::GetOwnerPawnController()
{
	APawn* MyPawn = Cast<APawn>(GetOwner());
	if (!MyPawn) return nullptr;

	return Cast<APlayerController>(MyPawn->GetController());
}

void ULSInteractTraceComponent::CheckForInteractable()
{
	APawn* MyPawn = Cast<APawn>(GetOwner());
	if (!MyPawn) return;

	FVector Location;
	FRotator Rotation;
	MyPawn->GetActorEyesViewPoint(Location, Rotation);

	FVector End = Location + (Rotation.Vector() * 300.f);

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(MyPawn);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Location, End, ECC_Visibility, Params);

	if (bHit)
	{
		AActor* HitActor = HitResult.GetActor();

		// Check if the actor is interactable (chest or pickup)
		if (HitActor && (HitActor->IsA(ALSChest::StaticClass()) || HitActor->IsA(ALSPickupItem::StaticClass())))
		{
			bCanInteract = true;
			CurrentInteractable = HitActor;
			ShowInteractionUI(true);
			return;
		}
	}

	// No interactable found
	bCanInteract = false;
	CurrentInteractable = nullptr;
	ShowInteractionUI(false);
}

void ULSInteractTraceComponent::ShowInteractionUI(bool bShow)
{
	if (!InteractionWidget) return;

	InteractionWidget->SetVisibility(bShow ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

#pragma optimize("", on)
