// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class ENGINEFEAUTRES_API FEFNativeObject
{
public:
	FEFNativeObject();
	~FEFNativeObject();
	
	FName GenerateRandomName();
	
	FName GetObjectName() const
	{
		return ObjectName;
	}
private:
    TArray<FName> CharacterNames;
	FName ObjectName;
};
