// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemUI.generated.h"

/**
 * 
 */
class USlotUI;
class UItemData;
UCLASS()
class HACKANDSLASHPROJECT_API UItemUI : public UUserWidget
{
	GENERATED_BODY()
public : 
	UFUNCTION(BlueprintImplementableEvent)
	UImage* GetItemUIThumbnail();

	UPROPERTY(BlueprintReadWrite)
	UItemData* itemData;

	UPROPERTY(BlueprintReadWrite)
	USlotUI * slotUI;
};
