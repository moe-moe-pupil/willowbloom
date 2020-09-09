// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class watchersTarget : TargetRules
{
	public watchersTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		//bUsePCHFiles = false;
		ExtraModuleNames.AddRange( new string[] { "watchers" } );
	}
}
