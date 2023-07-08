// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "EFGameViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class ENGINEFEAUTRES_API UEFGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

public:
	UEFGameViewportClient(const FObjectInitializer& ObjectInitializer);
	virtual void Tick(float DeltaTime) override;
};
