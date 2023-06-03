// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EFObjectStore.generated.h"

class FEFNativeObject;
UCLASS()
class ENGINEFEAUTRES_API UEFObjectStore : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:
	TSharedPtr<FEFNativeObject> ReferenceToSmartObject;
};
