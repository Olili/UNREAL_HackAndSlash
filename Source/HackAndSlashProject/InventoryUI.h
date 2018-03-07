// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryUI.generated.h"

/**
 * 
 */
class UItemData;

UCLASS()
class HACKANDSLASHPROJECT_API UInventoryUI : public UUserWidget
{
	GENERATED_BODY()
	
protected  : 

	UFUNCTION(BlueprintImplementableEvent,BluePrintCallable, Category = "ItemFactory")
	UItemData* GetRandomItem();
	UFUNCTION(BlueprintImplementableEvent, BluePrintCallable, Category = "ItemFactory")
	UItemData* GetItemOfType(TSubclassOf<UItemData> itemClass);
	UFUNCTION(BlueprintImplementableEvent, BluePrintCallable, Category = "InventorySlots")
	bool AddItemToBag(UItemData * itemData);

	UFUNCTION(BlueprintImplementableEvent, BluePrintCallable, Category = "Bag")
	void InitBag();

};
