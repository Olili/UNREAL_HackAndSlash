// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HackAndSlashProjectPlayerController.generated.h"

class IInteractable;
class UAttackComponent;

UCLASS()
class AHackAndSlashProjectPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AHackAndSlashProjectPlayerController();
	UFUNCTION(BlueprintCallable, Category = "Order")
	void OrderActivate(AActor * target);
	UFUNCTION(BlueprintCallable, Category = "Order")
	void OrderAttack(AActor * target);
	//UFUNCTION(BlueprintCallable, Category = "Setup")
	//void Initialise(UAttackComponent* _AttackComponent);
	UFUNCTION(BlueprintCallable, Category = "Order")
	void SetOccupied(bool _occupied);

protected:


	/** Begin State machine  */
	bool isOccupied;
	typedef void (AHackAndSlashProjectPlayerController::*FunctionPtrType)(float deltaTime);
	FunctionPtrType CurAction;



	void Goto(float deltaTime);
	void GotoAttack(float deltaTime);
	void Attack(float deltaTime);
	void Activate(float deltaTime);
	void FaceTarget(float deltaTime);

	/** End State machine  */
	AActor * actionTarget;
	FVector targetLocation;
	/** True if the controlled character should navigate to the mouse cursor. */
	bool bMousePressed;
	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	// COmponent : 
	//UAttackComponent * AttackComponent_BP =nullptr;

	
	/** Navigate player to the given world location. */
	bool SetNewMoveDestination(const FVector DestLocation);
	void RotateToward();
	void StopMovement();

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};


