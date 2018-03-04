// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "HackAndSlashProjectPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "HackAndSlashProjectCharacter.h"
#include "Interactable.h"
#include "AttackComponent.h"

AHackAndSlashProjectPlayerController::AHackAndSlashProjectPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	isOccupied = false;
	CurAction = nullptr;
	actionTarget = nullptr;
	bMousePressed = false;
	//AttackComponent_BP = FindComponentByClass<UAttackComponent>();
}


void AHackAndSlashProjectPlayerController::OrderActivate(AActor * target)
{
	CurAction = &AHackAndSlashProjectPlayerController::Goto;
}
void AHackAndSlashProjectPlayerController::OrderAttack(AActor * target)
{
	CurAction = &AHackAndSlashProjectPlayerController::GotoAttack;
}

void AHackAndSlashProjectPlayerController::Goto(float deltaTime)
{
	// If distance < 100

	if (SetNewMoveDestination(targetLocation))
		CurAction = nullptr;
}

void AHackAndSlashProjectPlayerController::GotoAttack(float deltaTime)
{
	// get Attrack machin. Dist < ? 
	if (SetNewMoveDestination(targetLocation))
		CurAction = nullptr;

		// check the distance to the target : 
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(actionTarget->GetActorLocation(), MyPawn->GetActorLocation());
		if (Distance < 200.0f)
		{
			CurAction = &AHackAndSlashProjectPlayerController::Attack;
			StopMovement();
			auto AttackComponent_BP = MyPawn->FindComponentByClass<UAttackComponent>();
			if (ensure(AttackComponent_BP))
			{
				UE_LOG(LogTemp, Warning, TEXT("LaunchAttackC++"));
				AttackComponent_BP->LaunchAttack();
			}
			UE_LOG(LogTemp, Warning, TEXT("EndGotoAttack"));
		}
	}
	
}

void AHackAndSlashProjectPlayerController::Attack(float deltaTime)
{
	//  
}

void AHackAndSlashProjectPlayerController::Activate(float deltaTime)
{
	// lauch Anim
}

void AHackAndSlashProjectPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	
		// Execute current phase of FSM
	if (CurAction != nullptr)
	{
		(this->*CurAction)(DeltaTime);
	}
		// takes order from player. 
	if (isOccupied)
		return;
	if (bMousePressed)
	{
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);
		if (Hit.Actor != nullptr)
		{
			IInteractable * interactable = Cast<IInteractable>(Hit.Actor->GetClass());
			//UE_LOG(LogTemp, Warning, TEXT("actor : %s"), *GetNameSafe(Hit.Actor->GetClass()));
			targetLocation = Hit.ImpactPoint;
				// If it's an Interactable it'll will tell us what to do. 
			if (Hit.GetActor()->Implements<UInteractable>())
			{
				IInteractable::Execute_OnSelected(Hit.GetActor(), this);
				actionTarget = Hit.GetActor();
			} 
			else
			{
				actionTarget = nullptr;
				CurAction = &AHackAndSlashProjectPlayerController::Goto;
			}
		}
	}
}

void AHackAndSlashProjectPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AHackAndSlashProjectPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AHackAndSlashProjectPlayerController::OnSetDestinationReleased);
}


bool AHackAndSlashProjectPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
		}
		else
		{
			return true;
		}
	}
	return false;
}
void AHackAndSlashProjectPlayerController::StopMovement()
{
	APawn* const MyPawn = GetPawn();
	UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
	if (MyPawn)
	{
		NavSys->SimpleMoveToLocation(this, GetPawn()->GetActorLocation());
	}
}

void AHackAndSlashProjectPlayerController::OnSetDestinationPressed()
{
	bMousePressed = true;
}

void AHackAndSlashProjectPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMousePressed = false;
}
