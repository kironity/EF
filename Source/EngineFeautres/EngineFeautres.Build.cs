// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EngineFeautres : ModuleRules
{
	public EngineFeautres(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
			{ "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "StatSystem", "GameplayDebugger", "SignificanceManager" });
		PublicIncludePaths.AddRange(new string[]
			{ "EngineFeautres" });
	}
}