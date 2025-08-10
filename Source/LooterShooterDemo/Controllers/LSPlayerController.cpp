// Copyright Danny Kay


#include "LSPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "LooterShooterDemo/LSDebugHelper.h"
#include "LooterShooterDemo/Characters/LSCharacter.h"
#include "LooterShooterDemo/World/LSChest.h"
#include "LooterShooterDemo/Components/InteractResponseComponent.h"
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
		EnhancedInputComponent->BindAction(PrimaryAction, ETriggerEvent::Started, this, &ThisClass::Primary);
		EnhancedInputComponent->BindAction(SecondaryAction, ETriggerEvent::Started, this, &ThisClass::Secondary);

		// Interaction
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ThisClass::Interact);
	}
}

void ALSPlayerController::Move(const FInputActionValue& Value)
{
	// find out which way is forward
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	// get right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	TObjectPtr<APawn> MyPawn = GetPawn();
	if (MyPawn == nullptr)
	{
		return;
	}

	// add movement
	MyPawn->AddMovementInput(ForwardDirection, MovementVector.X);
	MyPawn->AddMovementInput(RightDirection, MovementVector.Y);
}

void ALSPlayerController::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// add yaw and pitch input to controller
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

void ALSPlayerController::Primary()
{
}

void ALSPlayerController::Secondary()
{
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
