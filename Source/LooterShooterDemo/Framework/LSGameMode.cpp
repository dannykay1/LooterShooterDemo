// Copyright Danny Kay


#include "LSGameMode.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "LooterShooterDemo/Characters/LSCharacter.h"
#include "LooterShooterDemo/World/LSExtractionPoint.h"

#pragma optimize("", off)

ALSGameMode::ALSGameMode()
{
    // Set defaults here if needed
}

void ALSGameMode::BeginPlay()
{
    Super::BeginPlay();

    SpawnExtractionPoint();
    SpawnEnemy();
}

void ALSGameMode::SpawnExtractionPoint()
{
    if (!ExtractionPointClass) return;

    FVector Location = FVector(FMath::RandRange(-1000, 1000), FMath::RandRange(-1000, 1000), 100);
    GetWorld()->SpawnActor<ALSExtractionPoint>(ExtractionPointClass, Location, FRotator::ZeroRotator);
}

void ALSGameMode::SpawnEnemy()
{
    if (!EnemyClass) return;

    FVector Location = FVector(FMath::RandRange(-800, 800), FMath::RandRange(-800, 800), 100);
    UAIBlueprintHelperLibrary::SpawnAIFromClass(this, EnemyClass, nullptr, Location, FRotator::ZeroRotator);
}

#pragma optimize("", on)
