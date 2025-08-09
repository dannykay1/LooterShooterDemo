// Copyright Danny Kay

using UnrealBuildTool;
using System.Collections.Generic;

public class LooterShooterDemoTarget : TargetRules
{
	public LooterShooterDemoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "LooterShooterDemo" } );
	}
}
