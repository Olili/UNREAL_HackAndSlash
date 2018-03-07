// Fill out your copyright notice in the Description page of Project Settings.

#include "SlotUI.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "ItemData.h"
#include "ItemUI.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/UMG/Public/Components/Widget.h"
#include "Runtime/UMG/Public/Components/CanvasPanel.h"

void USlotUI::EmptySlot()
{
	if (isEquipmentSlot)
		RemoveEquipement();
	itemUIBP = nullptr;
	UE_LOG(LogTemp, Warning, TEXT("Empty Slot"));
}
void USlotUI::AddItem(UItemUI * otherItemUI)
{
	itemUIBP = otherItemUI;
	itemUIBP->slotUI = this;
	UCanvasPanel* canvasPanel = GetCanvasPanel();
	if (ensure(canvasPanel))
		canvasPanel->AddChild(itemUIBP);
	if (isEquipmentSlot && equippedItem)
		RemoveEquipement();
	if (isEquipmentSlot)
		AddEquipement(itemUIBP->itemData);

}

void USlotUI::AddItemFromGround(UItemData * _UItemData)
{
	if ((!ensure(_UItemData)))
	{
		UE_LOG(LogTemp, Warning, TEXT("UItemData null"));
		return;
	}
	// Create Item2D
	if (ItemUIWidgetTemplate)
	{
		itemUIBP = CreateWidget<UItemUI>(GetOwningPlayer(), ItemUIWidgetTemplate);
		
		if (ensure(itemUIBP))
		{
			itemUIBP->AddToViewport();
			itemUIBP->SetVisibility(ESlateVisibility::Visible);
			UCanvasPanel* canvasPanel = GetCanvasPanel();
			if (ensure(canvasPanel))
				canvasPanel->AddChild(itemUIBP);
			UImage* itemUIImage = itemUIBP->GetItemUIThumbnail();
			if (ensure(itemUIImage) && ensure(_UItemData))
				itemUIImage->SetBrushFromTexture(_UItemData->itemThumbnail);
			itemUIBP->itemData = _UItemData;
			itemUIBP->slotUI = this;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to ensure itemUIWidget"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("missing  ItemUIWidgetTemplate"));
	}
}

//static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Items/Blueprints/BP_ItemTest.BP_ItemTest'"));
//static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("'TopDownCPP/Blueprints/Inventory/Widgets/ItemUI_BP'"));
//{
//	if (ensure(ItemBlueprint.Object))
//		uiItem_BP = (UClass*)ItemBlueprint.Object->GeneratedClass;
//	else
//		UE_LOG(LogTemp, Warning, TEXT("Can't find ItemUI_BP"));
//}