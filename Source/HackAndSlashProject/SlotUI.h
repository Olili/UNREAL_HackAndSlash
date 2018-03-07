// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryEnum.h"
#include "SlotUI.generated.h"

class UItemData;
class UItemUI;
class UCanvasPanel;

/**
 * 
 */
class AItemInWorld;
UCLASS()
class HACKANDSLASHPROJECT_API USlotUI : public UUserWidget
{
	GENERATED_BODY()
public : 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (Bitmask, BitmaskEnum = "EItemType"))
	int32 itemMask;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UItemUI> ItemUIWidgetTemplate;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UItemUI * itemUIBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isEquipmentSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AItemInWorld *equippedItem;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Init(UItemData * UItemData);
	UFUNCTION(BlueprintCallable)
	void EmptySlot();

	UFUNCTION(BlueprintCallable)
	void AddItem(UItemUI * itemUI);

	UFUNCTION(BlueprintImplementableEvent, Category = "Slot")
	UCanvasPanel* GetCanvasPanel();

	UFUNCTION(BlueprintCallable)
	void AddItemFromGround(UItemData * UItemData);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Equipment")
	void AddEquipement(UItemData * UItemData);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Equipment")
	void RemoveEquipement();
};
