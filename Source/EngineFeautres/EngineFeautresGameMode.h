// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EngineFeautresGameMode.generated.h"

class UEFSignificanceManager;
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
	
	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category=Classes)
	TSubclassOf<UEFSignificanceManager> SignificanceManager;
	
	virtual void PostInitializeComponents() override;

	virtual void StartPlay() override;
	virtual void BeginPlay() override;

	void InitWorldLoader();

	void LoadWorld();
};



