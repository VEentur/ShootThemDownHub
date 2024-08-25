// ShootThemDown game. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShootThemDownEditorTarget : TargetRules
{
	public ShootThemDownEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ShootThemDown" } );
	}
}
