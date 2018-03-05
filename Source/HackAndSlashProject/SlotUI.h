// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryEnum.h"
#include "SlotUI.generated.h"

class UItemData;

/**
 * 
 */
UCLASS()
class HACKANDSLASHPROJECT_API USlotUI : public UUserWidget
{
	GENERATED_BODY()
public : 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (Bitmask, BitmaskEnum = "EItemType"))
	int32 itemMask;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UItemData* itemData;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Init(UItemData * UItemData);
};
