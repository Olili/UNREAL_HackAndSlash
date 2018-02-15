// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "HackAndSlashProjectGameMode.h"
#include "HackAndSlashProjectPlayerController.h"
#include "HackAndSlashProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHackAndSlashProjectGameMode::AHackAndSlashProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHackAndSlashProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}