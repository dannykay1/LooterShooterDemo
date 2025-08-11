// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LooterShooterDemo/Items/LSItemActor.h"
#include "LSLoadoutComponent.generated.h"

class ALSItemActor;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LOOTERSHOOTERDEMO_API ULSLoadoutComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULSLoadoutComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Loadout")
	TMap<FGameplayTag, ALSItemActor*> LoadoutSlots;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Loadout")
	FGameplayTag EquippedSlot;
};
