// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "LSItemActor.h"
#include "LSItemActor_Weapon.generated.h"

UCLASS()
class LOOTERSHOOTERDEMO_API ALSItemActor_Weapon : public ALSItemActor
{
	GENERATED_BODY()

public:
	ALSItemActor_Weapon();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SetupInput(ALSPlayerController* PlayerController) override;
};
