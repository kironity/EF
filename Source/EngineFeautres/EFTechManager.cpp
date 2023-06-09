// Fill out your copyright notice in the Description page of Project Settings.


#include "EFTechManager.h"

#include "EFObjectStore.h"
#include "Types/FWorldSaveData.h"

// Sets default values
AEFTechManager::AEFTechManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEFTechManager::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin play called in Tech manager"));
	GetGameInstance()->GetSubsystem<UEFObjectStore>()->TechManagerClass = this;
}

// Called every frame
void AEFTechManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEFTechManager::GetSaveData(FWorldSaveData& SaveData)
{
	SaveData.TechSaveData.LearnedVoidTechTypes = LearnedTech;
}

void AEFTechManager::LoadSaveData(const FWorldSaveData& LoadData)
{
	LearnedTech = LoadData.TechSaveData.LearnedVoidTechTypes;
}

void AEFTechManager::Learn(EVoidTechTypes LearnTech)
{
	LearnedTech.Add(LearnTech);
}

