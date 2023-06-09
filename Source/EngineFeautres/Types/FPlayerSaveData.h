#pragma once
#include "FPlayerSaveData.generated.h"

USTRUCT()
struct FPlayerSaveData
{
	GENERATED_BODY()
public:
	
	UPROPERTY()
	FVector PlayerLocation;
	
	UPROPERTY()
	float Healths;

	FPlayerSaveData() : PlayerLocation(FVector()), Healths(0.f)
	{
	}
	FPlayerSaveData(const FPlayerSaveData& PlayerSaveData) : PlayerLocation(PlayerSaveData.PlayerLocation), Healths(PlayerSaveData.Healths)
	{
	}
};
