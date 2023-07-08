// Fill out your copyright notice in the Description page of Project Settings.


#include "Optimizitaion/EFBaseUseSignificanseActor.h"

#include "SignificanceManager.h"

// Sets default values
AEFBaseUseSignificanseActor::AEFBaseUseSignificanseActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEFBaseUseSignificanseActor::BeginPlay()
{
	Super::BeginPlay();
	USignificanceManager* SignificanceManager = USignificanceManager::Get(GetWorld());
	check(SignificanceManager);
	const USignificanceManager::FManagedObjectSignificanceFunction Lambda = [this
		](USignificanceManager::FManagedObjectInfo* Info, const FTransform& Transform)->float
	{
		if (Info->GetObject())
		{
			const float Size = FVector(GetActorTransform().GetLocation() -
				Transform.GetLocation()).Size();
			const float ReturnValue = Size > 2000.f ? 5.f : 0.f;
			return ReturnValue;
		}
		return -1.f;
	};
	SignificanceManager->RegisterObject(this, "SigniActor", Lambda);
}

// Called every frame
void AEFBaseUseSignificanseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
