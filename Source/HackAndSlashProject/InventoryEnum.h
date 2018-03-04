// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType, meta = (Bitflags))		//"BlueprintType" is essential to include
enum class EItemType : uint8
{
	Weapon 	UMETA(DisplayName = "Weapon"),
	Helmet 	UMETA(DisplayName = "Helmet"),
	Armor 	UMETA(DisplayName = "Armor"),
	Feet 	UMETA(DisplayName = "Feet"),
	Arm 	UMETA(DisplayName = "Arm"),
	Ring	UMETA(DisplayName = "Ring"),
	Consumable	UMETA(DisplayName = "Consumable"),
};

