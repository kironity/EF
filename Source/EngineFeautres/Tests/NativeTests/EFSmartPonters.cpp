// Fill out your copyright notice in the Description page of Project Settings.


#include "EFSmartPonters.h"
#include "EngineFeautres.h"
#include "Containers/UnrealString.h"

FEFNativeObject::FEFNativeObject()
{
	CharacterNames.Add("Dmitriy", "Vladimir", "Valentin"); 
	UE_LOG(LogEngineFeatures, Log, TEXT("Smart pointer created - %s"), *ObjectName.ToString());
}

FEFNativeObject::~FEFNativeObject()
{
	UE_LOG(LogEngineFeatures, Log, TEXT("Smar pointer destroyed - %s"), *ObjectName.ToString());
}

FName FEFNativeObject::GenerateRandomName()
{
	return FName(); 
}
