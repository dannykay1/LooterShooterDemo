// Copyright Danny Kay


#include "LSItemActor_Weapon.h"
#include "EnhancedInputComponent.h"
#include "LooterShooterDemo/Controllers/LSPlayerController.h"
#include "LooterShooterDemo/Data/LSInputConfig.h"

#pragma optimize("", off)

ALSItemActor_Weapon::ALSItemActor_Weapon()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALSItemActor_Weapon::BeginPlay()
{
	Super::BeginPlay();
}

void ALSItemActor_Weapon::SetupInput(ALSPlayerController* PlayerController)
{
	Super::SetupInput(PlayerController);

	// if (PlayerController == nullptr)
	// {
	// 	return;
	// }
	//
	// UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);
	// if (EnhancedInputComponent == nullptr)
	// {
	// 	return;
	// }
	//
	// ULSInputConfig* InputConfig = GetInputConfig();
	// if (InputConfig == nullptr)
	// {
	// 	return;
	// }
	//
	// EnhancedInputComponent->BindAction(InputConfig->FindInputActionByTag(FGameplayTag()), ETriggerEvent::Started, this, &ThisClass::StartFire);
	// EnhancedInputComponent->BindAction(InputConfig->FindInputActionByTag(FGameplayTag()), ETriggerEvent::Completed, this, &ThisClass::StopFire);
}

#pragma optimize("", on)

