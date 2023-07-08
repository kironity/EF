// Fill out your copyright notice in the Description page of Project Settings.


#include "Optimizitaion/EFGameViewportClient.h"

#include "SignificanceManager.h"
#include "Kismet/GameplayStatics.h"

UEFGameViewportClient::UEFGameViewportClient(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	
}

void UEFGameViewportClient::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Ensure that we have a valid World and Significance Manager instance.
	if (World)
	{
		if (USignificanceManager* SignificanceManager = USignificanceManager::Get(World))
		{
			// Update once per frame, using only Player 0's world transform.
			if (APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(World, 0))
			{
				// The Significance Manager uses an ArrayView. Construct a one-element Array to hold the Transform.
				TArray<FTransform> TransformArray;
				TransformArray.Add(PlayerPawn->GetTransform());
				// Update the Significance Manager with our one-element Array passed in through an ArrayView.
				SignificanceManager->Update(TArrayView<FTransform>(TransformArray));
			}
		}
	}
}
