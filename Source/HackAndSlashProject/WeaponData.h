// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemData.h"
#include "WeaponData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class HACKANDSLASHPROJECT_API UWeaponData : public UItemData
{
	GENERATED_BODY()
public : 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UAnimMontage*> attackMontage;
	
};
