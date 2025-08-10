// Copyright Danny Kay


#include "LSPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "LooterShooterDemo/LSDebugHelper.h"
#include "LooterShooterDemo/Characters/LSCharacter.h"
#include "LooterShooterDemo/Components/LSEquipmentComponent.h"
#include "LooterShooterDemo/Items/LSItemActor.h"
#include "LooterShooterDemo/Utils/LSFunctionLibrary.h"
#include "LooterShooterDemo/World/LSPickupItem.h"

#pragma optimize("", off)

ALSPlayerController::ALSPlayerController()
{
}

void ALSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Contexts
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (const UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);

		// Looking
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);

		// Primary/Secondary
		EnhancedInputComponent->BindAction(PrimaryAction, ETriggerEvent::Started, this, &ThisClass::StartUsingPrimaryItem);
		EnhancedInputComponent->BindAction(PrimaryAction, ETriggerEvent::Completed, this, &ThisClass::StopUsingPrimaryItem);

		EnhancedInputComponent->BindAction(SecondaryAction, ETriggerEvent::Started, this, &ThisClass::StartUsingSecondaryItem);
		EnhancedInputComponent->BindAction(SecondaryAction, ETriggerEvent::Completed, this, &ThisClass::StopUsingSecondaryItem);

		// Grenade
		EnhancedInputComponent->BindAction(PrimaryAction, ETriggerEvent::Started, this, &ThisClass::UseGrenadeItem);

		// Interaction
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ThisClass::Interact);
	}
}

ULSEquipmentComponent* ALSPlayerController::GetEquipmentComonent()
{
	TObjectPtr<APawn> MyPawn = GetPawn();
	if (MyPawn == nullptr)
	{
		return nullptr;
	}

	return MyPawn->GetComponentByClass<ULSEquipmentComponent>();
}

void ALSPlayerController::Move(const FInputActionValue& Value)
{
	TObjectPtr<APawn> MyPawn = GetPawn();
	if (MyPawn == nullptr)
	{
		return;
	}

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	FVector2D MovementVector = Value.Get<FVector2D>();

	MyPawn->AddMovementInput(ForwardDirection, MovementVector.X);
	MyPawn->AddMovementInput(RightDirection, MovementVector.Y);
}

void ALSPlayerController::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void ALSPlayerController::Jump()
{
	ACharacter* MyCharacter = Cast<ACharacter>(GetPawn());
	if (MyCharacter == nullptr)
	{
		return;
	}

	MyCharacter->Jump();
}

void ALSPlayerController::StopJumping()
{
	ACharacter* MyCharacter = Cast<ACharacter>(GetPawn());
	if (MyCharacter == nullptr)
	{
		return;
	}

	MyCharacter->StopJumping();
}

void ALSPlayerController::StartUsingPrimaryItem()
{
	ULSEquipmentComponent* EquipmentComponent = GetEquipmentComonent();
	if (EquipmentComponent && EquipmentComponent->PrimarySlot.ItemActor)
	{
		EquipmentComponent->PrimarySlot.ItemActor->StartPrimaryAction();
	}
}

void ALSPlayerController::StopUsingPrimaryItem()
{
	ULSEquipmentComponent* EquipmentComponent = GetEquipmentComonent();
	if (EquipmentComponent && EquipmentComponent->PrimarySlot.ItemActor)
	{
		EquipmentComponent->PrimarySlot.ItemActor->StopPrimaryAction();
	}
}

void ALSPlayerController::StartUsingSecondaryItem()
{
	ULSEquipmentComponent* EquipmentComponent = GetEquipmentComonent();
	if (EquipmentComponent && EquipmentComponent->SecondarySlot.ItemActor)
	{
		EquipmentComponent->SecondarySlot.ItemActor->StartSecondaryAction();
	}
}

void ALSPlayerController::StopUsingSecondaryItem()
{
	ULSEquipmentComponent* EquipmentComponent = GetEquipmentComonent();
	if (EquipmentComponent && EquipmentComponent->SecondarySlot.ItemActor)
	{
		EquipmentComponent->SecondarySlot.ItemActor->StopSecondaryAction();
	}
}

void ALSPlayerController::UseGrenadeItem()
{
	ULSEquipmentComponent* EquipmentComponent = GetEquipmentComonent();
	if (EquipmentComponent && EquipmentComponent->GrenadeSlot.ItemActor)
	{
		EquipmentComponent->GrenadeSlot.ItemActor->StartPrimaryAction();
	}
}

void ALSPlayerController::Interact()
{
	TObjectPtr<APawn> MyPawn = GetPawn();
	if (MyPawn == nullptr)
	{
		return;
	}

	AActor* Interactable = ULSFunctionLibrary::GetCurrentInteractable(MyPawn);
	if (Interactable == nullptr)
	{
		return;
	}

	if (!Interactable->Implements<ULSInteractInterface>())
	{
		return;
	}

	ILSInteractInterface::Execute_OnInteract(Interactable, Cast<ALSCharacter>(GetPawn()));
	FText InteractText = ILSInteractInterface::Execute_GetDisplayName(Interactable);
	LSDebug::Print(InteractText.ToString());
}

#pragma optimize("", on)
