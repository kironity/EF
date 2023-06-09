// Fill out your copyright notice in the Description page of Project Settings.


#include "EFBasicObject.h"

UEFBasicObject::UEFBasicObject()
{
	UE_LOG(LogTemp, Warning, TEXT("Object created "));
}

UEFBasicObject::~UEFBasicObject()
{
	UE_LOG(LogTemp, Warning, TEXT("Object destrouyed"));
}
