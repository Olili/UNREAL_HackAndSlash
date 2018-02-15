// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "HackAndSlashProjectPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "HackAndSlashProjectCharacter.h"

AHackAndSlashProjectPlayerController::AHackAndSlashProjectPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AHackAndSlashProjectPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void AHackAndSlashProjectPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AHackAndSlashProjectPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AHackAndSlashProjectPlayerController::OnSetDestinationReleased);
}

void AHackAndSlashProjectPlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (AHackAndSlashProjectCharacter* MyPawn = Cast<AHackAndSlashProjectCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UNavigationSystem::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}


void AHackAndSlashProjectPlayerController::SetNewMoveDestination(const FVector DestLocation)
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
	}
}

void AHackAndSlashProjectPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AHackAndSlashProjectPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
