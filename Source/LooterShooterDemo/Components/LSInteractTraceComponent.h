// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LSInteractTraceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractResponseFoundDelegate, AActor*, InteractActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractResponseLostDelegate);


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

public:
	UPROPERTY(BlueprintAssignable, Category="InteractTraceComponent")
	FOnInteractResponseFoundDelegate OnInteractResponseFound;
	
	UPROPERTY(BlueprintAssignable, Category="InteractTraceComponent")
	FOnInteractResponseLostDelegate OnInteractResponseLost;

protected:
	APawn* GetOwnerPawn();
	APlayerController* GetOwnerPawnController();
	void CheckForInteractable();

	UPROPERTY(Transient)
	TObjectPtr<AActor> CurrentInteractable = nullptr;

	bool bCanInteract = false;
};
