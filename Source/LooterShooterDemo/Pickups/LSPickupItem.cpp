// Copyright Danny Kay


#include "LSPickupItem.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"
#include "LooterShooterDemo/LSDebugHelper.h"

#pragma optimize("", off)

ALSPickupItem::ALSPickupItem()
{
	PrimaryActorTick.bCanEverTick = false;

	// Defaults for demonstration
	ItemType = EItemType::Weapon;
	Damage = 10.f;
	FireRate = 0.5f;
	ArmorValue = 0.f;
}

void ALSPickupItem::BeginPlay()
{
	Super::BeginPlay();

	// Randomize stats based on item type
	switch (ItemType)
	{
	case EItemType::Weapon:
		Damage = UKismetMathLibrary::RandomFloatInRange(8.f, 15.f);
		FireRate = UKismetMathLibrary::RandomFloatInRange(0.3f, 1.0f);
		break;

	case EItemType::Armor:
		ArmorValue = UKismetMathLibrary::RandomFloatInRange(5.f, 20.f);
		break;

	case EItemType::Equipment:
		// Add equipment randomization here later
		break;
	}
}

void ALSPickupItem::OnPickedUp()
{
	LSDebug::Print(FString::Printf(TEXT("Picked up %s"), *UEnum::GetValueAsString(ItemType)));
	Destroy();
}

#pragma optimize("", on)
