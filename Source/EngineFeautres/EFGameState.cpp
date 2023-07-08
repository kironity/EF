// Fill out your copyright notice in the Description page of Project Settings.


#include "EFGameState.h"

void AEFGameState::AsyncPackageLoaded(UObject* Package)
{
	Super::AsyncPackageLoaded(Package);
	UE_LOG(LogTemp, Error, TEXT("Package name = :%s"), *GetNameSafe(Package));
}

void AEFGameState::HandleBeginPlay()
{
	Super::HandleBeginPlay();
}
