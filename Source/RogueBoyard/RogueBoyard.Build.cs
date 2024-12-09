// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RogueBoyard : ModuleRules
{
	public RogueBoyard(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "LocalMultiplayer", "DeveloperSettings", "ProceduralMeshComponent",  "AkAudio" });
=======
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "LocalMultiplayer", "DeveloperSettings", "LevelEditor", "ProceduralMeshComponent", "UnrealEd", "AkAudio" });
>>>>>>> parent of 181a4d06 (OUUUUUUUUUUUUUUAIIIIIIIIIIS LE COMMIT QUI FACHE POUR BUILD OUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUAIIIIIIIIIIIIIIIIIIIIIIIIS)
=======
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "LocalMultiplayer", "DeveloperSettings", "LevelEditor", "ProceduralMeshComponent", "UnrealEd", "AkAudio" });
>>>>>>> parent of 181a4d06 (OUUUUUUUUUUUUUUAIIIIIIIIIIS LE COMMIT QUI FACHE POUR BUILD OUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUAIIIIIIIIIIIIIIIIIIIIIIIIS)
=======
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "LocalMultiplayer", "DeveloperSettings", "LevelEditor", "ProceduralMeshComponent", "UnrealEd", "AkAudio" });
>>>>>>> parent of 181a4d06 (OUUUUUUUUUUUUUUAIIIIIIIIIIS LE COMMIT QUI FACHE POUR BUILD OUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUAIIIIIIIIIIIIIIIIIIIIIIIIS)

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
