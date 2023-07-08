// Fill out your copyright notice in the Description page of Project Settings.
#include "CoreMinimal.h"
#include "Automation/EFFirstTest.h"

#include "Tests/AutomationCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFirstTest, "EFTests.OpenMapTest", EAutomationTestFlags::ApplicationContextMask
                                 | EAutomationTestFlags::ProductFilter);

namespace
{
	UWorld* GetAnyGameWorld()
	{
		UWorld* TestWorld = nullptr;
		const TIndirectArray<FWorldContext>& WorldContexts = GEngine->GetWorldContexts();
		for (const FWorldContext& Context : WorldContexts)
		{
			if (((Context.WorldType == EWorldType::PIE) || (Context.WorldType == EWorldType::Game)) && (Context.World()
				!=
				NULL))
			{
				TestWorld = Context.World();
				break;
			}
		}

		return TestWorld;
	}

	const FName BlueprintName = FName(
		"/Script/Engine.Blueprint'/Game/FirstPerson/Blueprints/BP_PickUp_Rifle.BP_PickUp_Rifle'");
}

bool FFirstTest::RunTest(const FString& Parameters)
{
	if (!TestTrueExpr(AutomationOpenMap("/Game/FirstPerson/Maps/FirstPersonMap"))) return false;
	ADD_LATENT_AUTOMATION_COMMAND(FExitGameCommand);

	UWorld* World = GetAnyGameWorld();
	if (!TestNotNull("Test world on nullptr", World)) return false;

	UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, *BlueprintName.ToString());
	if (!TestNotNull("Test Blueprint on nullptr", Blueprint)) return false;

	AActor* Actor = World->SpawnActor<AActor>(Blueprint->GeneratedClass);
	if (!TestNotNull("Test Actor on nullptr", Actor)) return false;

	if (!TestTrue("Actor can be damaged", Actor->CanBeDamaged())) return false;

	return true;
}
