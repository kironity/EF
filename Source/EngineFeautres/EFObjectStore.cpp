// Fill out your copyright notice in the Description page of Project Settings.


#include "EFObjectStore.h"

void UEFObjectStore::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
}


void UEFObjectStore::OnWeakGunEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
	if (EndPlayReason == EEndPlayReason::Destroyed)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weak object has been destroyed "));
	}
}