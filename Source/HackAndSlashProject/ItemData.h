// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class HACKANDSLASHPROJECT_API UItemData : public UObject
{
	GENERATED_BODY()
public : 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString itemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* itemThumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBlueprint* item3DBlueprint;
	
};
