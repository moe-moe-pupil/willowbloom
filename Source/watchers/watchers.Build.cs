// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class watchers : ModuleRules
{
	public watchers(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] {  "CoreUObject" ,"InputCore","Sockets", "WebSockets", "JsonUtilities",
		             
				"CoreUObject",
				
				"InputCore",
				"RenderCore",
				"RHI",
				"Slate",
				"SlateCore",
				"UMG",
				"Json",
				"Http",});

		PrivateDependencyModuleNames.AddRange(new string[] {
		"Engine",
		"slua_unreal", "slua_profile", "Networking","Core", "SocketIOClient", "SocketIOLib", "SIOJson"
			// ... add private dependencies that you statically link with here ...
	
		
		//"UnrealHttpServer",

		 }
		);

		PrivateIncludePathModuleNames.AddRange(new string[] { "slua_unreal" });
		PublicIncludePathModuleNames.AddRange(new string[] { "slua_unreal", "slua_profile" });


        PublicDefinitions.Add("ENABLE_PROFILER");

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
