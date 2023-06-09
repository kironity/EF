// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Types/FWorldSaveData.h"
#include "UObject/Interface.h"
#include "EFSaveLoadInterface.generated.h"

UINTERFACE(MinimalAPI)
class UEFSaveLoadInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ENGINEFEAUTRES_API IEFSaveLoadInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void GetSaveData(FWorldSaveData& SaveData);
	virtual void LoadSaveData(const FWorldSaveData& LoadData);
};
