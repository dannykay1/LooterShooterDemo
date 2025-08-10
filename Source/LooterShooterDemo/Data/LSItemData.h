// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "LSItemData.generated.h"

class ULSInputConfig;
class ALSItemActor;

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()

	FItemData()
	{
		DisplayName = FText::FromString("Display Name");
		Description = FText::FromString("Description");
		SocketEquipName = FName("Socket Name Here");
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<ALSItemActor> ItemActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<ULSInputConfig> InputConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SocketEquipName;
};