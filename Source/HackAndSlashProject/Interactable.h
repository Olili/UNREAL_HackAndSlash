// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.generated.h"

class AHackAndSlashProjectPlayerController;
// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class HACKANDSLASHPROJECT_API IInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "IInteraction")
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IInteraction")
	void OnSelected(AHackAndSlashProjectPlayerController * playerController);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "IInteraction")
	void OnInteraction(AHackAndSlashProjectPlayerController * playerController);
};
