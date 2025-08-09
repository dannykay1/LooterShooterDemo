// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "LSEnemyController.generated.h"

UCLASS()
class LOOTERSHOOTERDEMO_API ALSEnemyController : public AAIController
{
	GENERATED_BODY()

public:
	ALSEnemyController();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	APawn* PlayerPawn;

	FTimerHandle FireTimerHandle;
	void FireAtPlayer();
};
