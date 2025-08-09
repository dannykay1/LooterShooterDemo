// Copyright Danny Kay


#include "LSInputComponent.h"

#pragma optimize("", off)

ULSInputComponent::ULSInputComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULSInputComponent::BeginPlay()
{
	Super::BeginPlay();	
}

void ULSInputComponent::Move(const FInputActionValue& Value)
{
}

void ULSInputComponent::Look(const FInputActionValue& Value)
{
}

void ULSInputComponent::Jump()
{
}

void ULSInputComponent::StopJumping()
{
}

#pragma optimize("", on)
