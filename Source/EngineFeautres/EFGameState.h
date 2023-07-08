// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EFGameState.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEFEAUTRES_API AEFGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	virtual void AsyncPackageLoaded(UObject* Package) override;
	virtual void HandleBeginPlay() override;
};
