#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LSGameMode.generated.h"

UCLASS()
class LOOTERSHOOTERDEMO_API ALSGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ALSGameMode();

protected:
    virtual void BeginPlay() override;
};
