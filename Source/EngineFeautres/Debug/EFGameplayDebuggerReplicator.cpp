// Fill out your copyright notice in the Description page of Project Settings.


#include "Debug/EFGameplayDebuggerReplicator.h"

#include "EngineFeautresCharacter.h"
#if WITH_GAMEPLAY_DEBUGGER_MENU

FEFGameplayDebuggerReplicator::FEFGameplayDebuggerReplicator()
{
	SetDataPackReplication<FRepData>(&DataPack);
}

void FEFGameplayDebuggerReplicator::CollectData(APlayerController* OwnerPC, AActor* DebugActor)
{
	FGameplayDebuggerCategory::CollectData(OwnerPC, DebugActor);
	check(OwnerPC);
	const AEngineFeautresCharacter* Character = OwnerPC->GetPawn<AEngineFeautresCharacter>();
	if (!Character) return;
	DataPack.ActorName = Character->GetName();
	DataPack.HasRifle =  Character->bHasRifle ? FString("true") : FString("false");
}

void FEFGameplayDebuggerReplicator::DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext)
{
	FGameplayDebuggerCategory::DrawData(OwnerPC, CanvasContext);
	if (!DataPack.ActorName.IsEmpty())
	{
		CanvasContext.Printf(TEXT("{yellow}Actor name: {white}%s"), *DataPack.ActorName);
	}
	if (!DataPack.HasRifle.IsEmpty())
	{
		CanvasContext.Printf(TEXT("{yellow} Has rifle: {white}%s"), *DataPack.HasRifle);
	}
}

TSharedRef<FEFGameplayDebuggerReplicator> FEFGameplayDebuggerReplicator::MakeInstance()
{
	return MakeShareable(new FEFGameplayDebuggerReplicator());
}

void FEFGameplayDebuggerReplicator::FRepData::Serialize(FArchive& Ar)
{
	Ar << ActorName;
	Ar << HasRifle;
}

#endif