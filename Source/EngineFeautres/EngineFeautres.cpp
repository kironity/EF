// Copyright Epic Games, Inc. All Rights Reserved.

#include "EngineFeautres.h"

#include "GameplayDebugger.h"
#include "Debug/EFGameplayDebuggerReplicator.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, EngineFeautres, "EngineFeautres");


DEFINE_LOG_CATEGORY(LogEngineFeatures);

//
// void FEngineFeautres::ShutdownModule()
// {
// 	FDefaultGameModuleImpl::ShutdownModule();
// #if WITH_GAMEPLAY_DEBUGGER
// 	IGameplayDebugger& GameplayDebuggerModule = IGameplayDebugger::Get();
// 	GameplayDebuggerModule.UnregisterCategory("Player");
// #endif
// }
