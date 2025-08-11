// Copyright Danny Kay


#include "LSLoadoutComponent.h"


#pragma optimize("", off)

ULSLoadoutComponent::ULSLoadoutComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void ULSLoadoutComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void ULSLoadoutComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

#pragma optimize("", on)

