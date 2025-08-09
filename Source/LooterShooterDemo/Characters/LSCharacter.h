#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LSCharacter.generated.h"

UCLASS()
class LOOTERSHOOTERDEMO_API ALSCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ALSCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void Interact();
    void FireWeapon();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Role")
    bool bIsPlayerControlled;
};
