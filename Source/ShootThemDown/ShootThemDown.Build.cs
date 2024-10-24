// ShootThemDown game. All rights reserved.

using UnrealBuildTool;

public class ShootThemDown : ModuleRules
{
	public ShootThemDown(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[]
		{
			"ShootThemDown/Public/Player",
			"ShootThemDown/Public/Components",
			"ShootThemDown/Public/Dev",
			"ShootThemDown/Public/Weapon",
            "ShootThemDown/Public/UI",
            "ShootThemDown/Public/Animations"
        });
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
