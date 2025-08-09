// Copyright Danny Kay

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "LSItemData.generated.h"

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()

	FItemData()
	{
		DisplayName = FText::GetEmpty();
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> Icon;
};