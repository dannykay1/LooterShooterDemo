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
		Guid = FGuid::NewGuid();
		DisplayName = FText::GetEmpty();
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGuid Guid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> Icon;

	bool operator==(const FItemData& Other) const
	{
		return Guid == Other.Guid;
	}

	bool operator!=(const FItemData& Other) const
	{
		return !(*this == Other);
	}
};