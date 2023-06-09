#pragma once
#include "FTechSaveData.generated.h"

UENUM()
enum class EVoidTechTypes : uint8
{
	FastWaking,
};

USTRUCT()
struct FTechSaveData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSet<EVoidTechTypes> LearnedVoidTechTypes;

	FTechSaveData() : LearnedVoidTechTypes(TSet<EVoidTechTypes>())
	{
	}
};
