#pragma once

#include "FPlayerSaveData.h"
#include "FTechSaveData.h"
#include "FWorldSaveData.generated.h"

USTRUCT()
struct FWorldSaveData
{
	GENERATED_BODY()
public:
	
	UPROPERTY()
	FPlayerSaveData PlayerSaveData;
	
	UPROPERTY()
	FTechSaveData TechSaveData;

	FWorldSaveData() : PlayerSaveData(FPlayerSaveData()), TechSaveData(FTechSaveData())
	{
	}
	FWorldSaveData(const FWorldSaveData& WorldSaveData): PlayerSaveData(WorldSaveData.PlayerSaveData), TechSaveData(WorldSaveData.TechSaveData)
	{
	}
};
