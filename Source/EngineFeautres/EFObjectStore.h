// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EFObjectStore.generated.h"

class AEFWorldStateManager;
class AEFTechManager;
class UEFBasicObject;
class AActor;
class FEFNativeObject;

UCLASS()
class ENGINEFEAUTRES_API UEFObjectStore : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	TSharedPtr<FEFNativeObject> ReferenceToSmartObject;
	
	UFUNCTION()
	void OnWeakGunEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);
	
	TSharedPtr<UEFBasicObject> WeakObjectPtr;
	
	TWeakObjectPtr<AEFTechManager> TechManagerClass;
	TWeakObjectPtr<AEFWorldStateManager> WorldStateManager;
};
