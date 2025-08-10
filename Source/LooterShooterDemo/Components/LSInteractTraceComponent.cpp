// Copyright Danny Kay


#include "LSInteractTraceComponent.h"
#include "LooterShooterDemo/Interfaces/LSInteractInterface.h"
#include "LooterShooterDemo/Utils/LSFunctionLibrary.h"

#pragma optimize("", off)

ULSInteractTraceComponent::ULSInteractTraceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void ULSInteractTraceComponent::BeginPlay()
{
	Super::BeginPlay();
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
	if (MyPawn)
	{
		return nullptr;
	}

	return Cast<APlayerController>(MyPawn->GetController());
}

void ULSInteractTraceComponent::CheckForInteractable()
{
	APawn* MyPawn = Cast<APawn>(GetOwner());
	if (MyPawn == nullptr)
	{
		return;
	}

	FVector StartLocation;
	FRotator Direction;
	ULSFunctionLibrary::GetPlayerEyesViewPoint(GetOwner(), StartLocation, Direction);

	FVector EndLocation = StartLocation + (Direction.Vector() * 2000.f);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(MyPawn);

	FHitResult HitResult;

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, Params);
	if (!bHit)
	{
		bCanInteract = false;
		CurrentInteractable = nullptr;
		OnInteractResponseLost.Broadcast();
		return;
	}

	AActor* HitActor = HitResult.GetActor();
	if (HitActor == nullptr || !HitActor->Implements<ULSInteractInterface>())
	{
		bCanInteract = false;
		CurrentInteractable = nullptr;
		OnInteractResponseLost.Broadcast();
		return;
	}

	bCanInteract = true;
	CurrentInteractable = HitActor;
	OnInteractResponseFound.Broadcast(HitActor);
}

#pragma optimize("", on)
