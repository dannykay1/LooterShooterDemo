#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "LSPlayerController.generated.h"

class ULSEquipmentComponent;
class UInputAction;
class UInputMappingContext;

UCLASS()
class LOOTERSHOOTERDEMO_API ALSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ALSPlayerController();

protected:
	virtual void SetupInputComponent() override;
	ULSEquipmentComponent* GetEquipmentComonent();

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Jump();
	void StopJumping();
	void StartUsingPrimaryItem();
	void StopUsingPrimaryItem();
	void StartUsingSecondaryItem();
	void StopUsingSecondaryItem();
	void UseGrenadeItem();
	void Interact();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Input")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* MouseLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* PrimaryAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* SecondaryAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* InteractAction;
};
