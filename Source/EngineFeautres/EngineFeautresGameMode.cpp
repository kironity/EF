// Copyright Epic Games, Inc. All Rights Reserved.

#include "EngineFeautresGameMode.h"
#include "EngineFeautresCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEngineFeautresGameMode::AEngineFeautresGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
