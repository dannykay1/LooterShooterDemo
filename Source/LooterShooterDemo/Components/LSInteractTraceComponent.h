// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LSInteractTraceComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LOOTERSHOOTERDEMO_API ULSInteractTraceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULSInteractTraceComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	APawn* GetOwnerPawn();
	APlayerController* GetOwnerPawnController();
	void CheckForInteractable();
	void ShowInteractionUI(bool bShow);

	UPROPERTY(EditDefaultsOnly, Category="InteractTraceComponent")
	TSubclassOf<UUserWidget> InteractionWidgetClass;

	UPROPERTY(Transient)
	TObjectPtr<UUserWidget> InteractionWidget;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CurrentInteractable = nullptr;

	bool bCanInteract = false;
};
