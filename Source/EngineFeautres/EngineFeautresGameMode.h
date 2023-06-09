// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EngineFeautresGameMode.generated.h"

class AEFWorldStateManager;
UCLASS(minimalapi)
class AEngineFeautresGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEngineFeautresGameMode();
	
	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category=Classes)
	TSubclassOf<AEFWorldStateManager> WorldLoader;
	
	UPROPERTY(Transient)
	TObjectPtr<AEFWorldStateManager> WorldStateManager;
	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	void InitWorldLoader();

	void LoadWorld();

	virtual void RestartPlayer(AController* NewPlayer) override;
	virtual void RestartPlayerAtTransform(AController* NewPlayer, const FTransform& SpawnTransform) override;
};



