// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemData.h"
#include "ItemDb.generated.h"

/**
 * 
 */



UCLASS(Blueprintable, BlueprintType)
class HACKANDSLASHPROJECT_API UItemDb : public UDataAsset
{
	GENERATED_BODY()
public : 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemVariables")
	TArray<UClass*> items;
	
};
