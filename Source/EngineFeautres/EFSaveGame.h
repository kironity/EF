// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Types/FWorldSaveData.h"
#include "EFSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEFEAUTRES_API UEFSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	FWorldSaveData WorldSaveData;
};
