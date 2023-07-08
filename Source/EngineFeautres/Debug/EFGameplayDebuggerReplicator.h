// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#if WITH_GAMEPLAY_DEBUGGER_MENU

#include "GameplayDebuggerCategory.h"
#include "EFGameplayDebuggerReplicator.h"

/**
 * 
 */
class FEFGameplayDebuggerReplicator : public FGameplayDebuggerCategory
{
public:
	FEFGameplayDebuggerReplicator();

	virtual void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;
	virtual void DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext) override;

	ENGINEFEAUTRES_API static TSharedRef<FEFGameplayDebuggerReplicator> MakeInstance();
protected:
	struct FRepData
	{
		// Put all data you want to display here
		FString ActorName;
		FString HasRifle;
        
		void Serialize(FArchive& Ar);
	};
    
	FRepData DataPack;
};

#endif 