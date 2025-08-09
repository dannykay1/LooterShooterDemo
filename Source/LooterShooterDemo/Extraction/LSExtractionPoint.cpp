// Copyright Danny Kay


#include "LSExtractionPoint.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

#pragma optimize("", off)

ALSExtractionPoint::ALSExtractionPoint()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	RootComponent = BoxComp;
	BoxComp->SetBoxExtent(FVector(100.f));
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ALSExtractionPoint::OnOverlapBegin);
}

void ALSExtractionPoint::BeginPlay()
{
	Super::BeginPlay();
}

void ALSExtractionPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
										UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
										bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Player Extracted! Restarting..."));
	}

	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

#pragma optimize("", on)
