// Copyright Epic Games, Inc. All Rights Reserved.

#include "EngineFeautresGameMode.h"
#include "EngineFeautresCharacter.h"
#include "Core/EFWorldStateManager.h"
#include "Optimizitaion/EFSignificanceManager.h"
#include "UObject/ConstructorHelpers.h"

AEngineFeautresGameMode::AEngineFeautresGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	WorldLoader = AEFWorldStateManager::StaticClass();
	SignificanceManager = UEFSignificanceManager::StaticClass();
}

void AEngineFeautresGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	InitWorldLoader();
	UE_LOG(LogTemp, Warning, TEXT("PreInitializeComponents called "));
}

void AEngineFeautresGameMode::StartPlay()
{
	Super::StartPlay();
	WorldStateManager->LoadWorld();
}

void AEngineFeautresGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin Play called "));
}

void AEngineFeautresGameMode::InitWorldLoader()
{
	WorldStateManager = GetWorld()->SpawnActor<AEFWorldStateManager>(WorldLoader, FTransform(), FActorSpawnParameters());
}

void AEngineFeautresGameMode::LoadWorld()
{
	check(WorldStateManager)
	WorldStateManager->LoadWorld();
}
