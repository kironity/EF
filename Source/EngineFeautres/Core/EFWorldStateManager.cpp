// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/EFWorldStateManager.h"

#include "EFObjectStore.h"
#include "EFSaveGame.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Types/FWorldSaveData.h"
#include "EFSaveLoadInterface.h"
#include "EFTechManager.h"
#include "EngineUtils.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"

AEFWorldStateManager::AEFWorldStateManager()
{
	PrimaryActorTick.bCanEverTick = true;
	TechManagerClass = AEFTechManager::StaticClass();
}

void AEFWorldStateManager::BeginPlay()
{
	Super::BeginPlay();
	GetGameInstance()->GetSubsystem<UEFObjectStore>()->WorldStateManager = this;
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay in world state called ")); 
}

void AEFWorldStateManager::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UE_LOG(LogTemp, Warning, TEXT("Pre initiazlie Components called in world state "));
	GetWorld()->SpawnActor<AEFTechManager>(TechManagerClass, FTransform(), FActorSpawnParameters());
}

void AEFWorldStateManager::SaveWorld()
{
	FWorldSaveData WorldSaveData;
	UEFSaveGame* SaveGameSlot = NewObject<UEFSaveGame>(GetTransientPackage(), UEFSaveGame::StaticClass());
	if (!SaveGameSlot) return;
	const TWeakObjectPtr<AEFTechManager> TechManager = GetGameInstance()->GetSubsystem<UEFObjectStore>()->TechManagerClass;
	if (TechManager.Get())
	{
		if (IEFSaveLoadInterface* LoadInterface = Cast<IEFSaveLoadInterface>(TechManager))
		{
			LoadInterface->GetSaveData(WorldSaveData);
		}
	}

	if (ACharacter* Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		if (IEFSaveLoadInterface* SaveLoadInterface = Cast<IEFSaveLoadInterface>(Character))
		{
			SaveLoadInterface->GetSaveData(WorldSaveData);
		}
	}

	for (auto It = RegisteredActors.CreateIterator(); It; ++It)
	{
		if (AActor* Actor = *It)
		{
			FDynamicDroppedItems DroppedItem;
			DroppedItem.ActorClass = Actor->GetClass();
			DroppedItem.ActorTransform = Actor->GetActorTransform();
			FMemoryWriter MemoryWriter(DroppedItem.ByteArray);
			FObjectAndNameAsStringProxyArchive ProxyArchive(MemoryWriter, true);

			ProxyArchive.ArIsSaveGame = true;
			Actor->Serialize(ProxyArchive);
			WorldSaveData.DroppedItems.Add(DroppedItem);
		}
	}
	SaveGameSlot->WorldSaveData = WorldSaveData;
	UGameplayStatics::SaveGameToSlot(SaveGameSlot, "FirstSave", 0);
}

void AEFWorldStateManager::LoadWorld()
{
	if (!UGameplayStatics::DoesSaveGameExist("FirstSave", 0))
	{
		UE_LOG(LogTemp, Warning, TEXT("Load game doesn't not exist is save slot "));
		return;
	}
	const UEFSaveGame* SaveSlot = Cast<UEFSaveGame>(UGameplayStatics::LoadGameFromSlot("FirstSave", 0));
	if (!SaveSlot) return;
	
	const FWorldSaveData WorldSaveData = FWorldSaveData(SaveSlot->WorldSaveData);

	if (AActor* LoadTechManager = GetWorld()->SpawnActor<AActor>(
		TechManagerClass, FTransform(), FActorSpawnParameters()))
	{
		if (IEFSaveLoadInterface* LoadInterface = Cast<IEFSaveLoadInterface>(LoadTechManager))
		{
			LoadInterface->LoadSaveData(WorldSaveData);
		}
	}
	//GetWorld()->GetGameState();

	if (ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		if (IEFSaveLoadInterface* LoadInterface = Cast<IEFSaveLoadInterface>(PlayerCharacter))
		{
			LoadInterface->LoadSaveData(WorldSaveData);
		}
	}

	for (auto& DroppedItem : WorldSaveData.DroppedItems)
	{
		if (DroppedItem.ActorClass)
		{
			FActorSpawnParameters SpawnParameters;
			if (AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(DroppedItem.ActorClass, DroppedItem.ActorTransform, SpawnParameters))
			{
				FMemoryReader MemoryReader(DroppedItem.ByteArray);

				FObjectAndNameAsStringProxyArchive ProxyArchive(MemoryReader, true);
				ProxyArchive.ArIsSaveGame = true;
				ProxyArchive.Seek(0);
				
				if (ProxyArchive.IsLoading())
				{
					UE_LOG(LogTemp, Warning, TEXT("Loading "))
				}
				else if (ProxyArchive.IsSaving())
				{
					UE_LOG(LogTemp, Warning, TEXT("Saving"))
				}
				SpawnedActor->Serialize(ProxyArchive);
			}
		}
	}
}

void AEFWorldStateManager::RegisterItem(AActor* Item)
{
	RegisteredActors.Add(Item);
}

void AEFWorldStateManager::UnRegisterItem(AActor* Item)
{
	RegisteredActors.Remove(Item);
}
