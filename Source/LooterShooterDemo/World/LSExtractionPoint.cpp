// Copyright Danny Kay


#include "LSExtractionPoint.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "LooterShooterDemo/LSDebugHelper.h"

#pragma optimize("", off)

ALSExtractionPoint::ALSExtractionPoint()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	SetRootComponent(BoxComponent);
	
	BoxComponent->SetBoxExtent(FVector(100.f));
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ALSExtractionPoint::OnOverlapBegin);
}

void ALSExtractionPoint::BeginPlay()
{
	Super::BeginPlay();
}

void ALSExtractionPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	LSDebug::Print(TEXT("Player Extracted! Restarting..."));
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

#pragma optimize("", on)
