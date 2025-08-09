// Copyright Danny Kay

using UnrealBuildTool;
using System.Collections.Generic;

public class LooterShooterDemoEditorTarget : TargetRules
{
	public LooterShooterDemoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "LooterShooterDemo" } );
	}
}
