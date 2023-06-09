#pragma once
#include "FDynamicDroppedItems.generated.h"
USTRUCT()
struct FDynamicDroppedItems
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TSubclassOf<AActor> ActorClass;

	UPROPERTY()
	FTransform ActorTransform;
	
	UPROPERTY()
	TArray<uint8> ByteArray;

	FDynamicDroppedItems() : ActorClass(nullptr), ActorTransform(FTransform())
	{
	}
};
