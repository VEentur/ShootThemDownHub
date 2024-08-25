// ShootThemDown game. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShootThemDownTarget : TargetRules
{
	public ShootThemDownTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ShootThemDown" } );
	}
}
