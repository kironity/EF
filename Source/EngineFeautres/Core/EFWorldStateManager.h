// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EFWorldStateManager.generated.h"

class USaveGame;
class AEFTechManager;
UCLASS()
class ENGINEFEAUTRES_API AEFWorldStateManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AEFWorldStateManager();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AEFTechManager> TechManagerClass;

	virtual void PostInitializeComponents() override;

	virtual void SaveWorld();

	virtual void LoadWorld(); 

protected:
	virtual void BeginPlay() override;
	
};
