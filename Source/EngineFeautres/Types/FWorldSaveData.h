#pragma once

#include "FDynamicDroppedItems.h"
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

	UPROPERTY()
	TArray<FDynamicDroppedItems> DroppedItems;

	FWorldSaveData() : PlayerSaveData(FPlayerSaveData()), TechSaveData(FTechSaveData())
	{
	}
	FWorldSaveData(const FWorldSaveData& WorldSaveData):
					PlayerSaveData(WorldSaveData.PlayerSaveData),
					TechSaveData(WorldSaveData.TechSaveData),
					DroppedItems(WorldSaveData.DroppedItems)
	{
	}
};
