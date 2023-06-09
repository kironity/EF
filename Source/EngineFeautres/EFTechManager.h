// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EFSaveLoadInterface.h"
#include "GameFramework/Actor.h"
#include "EFTechManager.generated.h"

UCLASS()
class ENGINEFEAUTRES_API AEFTechManager : public AActor, public IEFSaveLoadInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEFTechManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetSaveData(FWorldSaveData& SaveData) override;
	virtual void LoadSaveData(const FWorldSaveData& LoadData) override;


	void Learn(EVoidTechTypes LearnTech);

	UPROPERTY()
	TSet<EVoidTechTypes> LearnedTech;
};
