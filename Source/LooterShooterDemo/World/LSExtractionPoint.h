// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LSExtractionPoint.generated.h"

class UBoxComponent;

UCLASS()
class LOOTERSHOOTERDEMO_API ALSExtractionPoint : public AActor
{
	GENERATED_BODY()

public:
	ALSExtractionPoint();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBoxComponent> BoxComponent;
};
