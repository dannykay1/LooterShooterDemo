// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LooterShooterDemo/Data/LSItemData.h"
#include "InteractResponseComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractSignature, const FItemData&, ItemData);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LOOTERSHOOTERDEMO_API UInteractResponseComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInteractResponseComponent();

protected:
	virtual void BeginPlay() override;

public:
	FItemData* GetItemData();
	void Interact();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interact")
	FDataTableRowHandle ItemRowHandle;

	UPROPERTY(BlueprintAssignable, Category="Interact")
	FOnInteractSignature OnInteract;
};
