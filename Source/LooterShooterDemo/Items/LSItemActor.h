// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LSItemActor.generated.h"

class ULSItemStack;

UCLASS()
class LOOTERSHOOTERDEMO_API ALSItemActor : public AActor
{
	GENERATED_BODY()

public:
	ALSItemActor();

protected:
	virtual void BeginPlay() override;

public:
	void SetItemStack(ULSItemStack* InItemStack);
	
	UPROPERTY(BlueprintReadOnly, Category = "Items")
	TObjectPtr<ULSItemStack> ItemStack;

	
};
