// Copyright Danny Kay


#include "LSFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "LooterShooterDemo/Components/InteractResponseComponent.h"
#include "LooterShooterDemo/Components/LSInventoryComponent.h"
#include "LooterShooterDemo/Components/LSEquipmentComponent.h"
#include "LooterShooterDemo/Components/LSInteractTraceComponent.h"

#pragma optimize("", on)

UInteractResponseComponent* ULSFunctionLibrary::GetInteractResponseComponent(AActor* SourceActor)
{
	if (SourceActor)
	{
		return nullptr;
	}

	return SourceActor->GetComponentByClass<UInteractResponseComponent>();
}

ULSInventoryComponent* ULSFunctionLibrary::GetInventoryComponent(AActor* SourceActor)
{
	if (SourceActor)
	{
		return nullptr;
	}

	return SourceActor->GetComponentByClass<ULSInventoryComponent>();
}

ULSEquipmentComponent* ULSFunctionLibrary::GetEquipmentComponent(AActor* SourceActor)
{
	if (SourceActor)
	{
		return nullptr;
	}

	return SourceActor->GetComponentByClass<ULSEquipmentComponent>();
}

bool ULSFunctionLibrary::GetPlayerEyesViewPoint(AActor* Player, FVector& OutLocation, FRotator& OutRotation)
{
	if (Player == nullptr)
	{
		OutLocation = FVector::ZeroVector;
		OutRotation = FRotator::ZeroRotator;
		return false;
	}

	UCameraComponent* CameraComponent = Player->GetComponentByClass<UCameraComponent>();
	if (CameraComponent == nullptr)
	{
		OutLocation = FVector::ZeroVector;
		OutRotation = FRotator::ZeroRotator;
		return false;
	}

	OutLocation = CameraComponent->GetComponentLocation();
	OutRotation = CameraComponent->GetComponentRotation();
	return true;
}

AActor* ULSFunctionLibrary::GetCurrentInteractable(AActor* Player)
{
	if (Player == nullptr)
	{
		return nullptr;
	}

	ULSInteractTraceComponent* InteractTraceComponent = Player->GetComponentByClass<ULSInteractTraceComponent>();
	if (InteractTraceComponent == nullptr)
	{
		return nullptr;
	}

	return InteractTraceComponent->CurrentInteractable;
}

#pragma optimize("", on)
