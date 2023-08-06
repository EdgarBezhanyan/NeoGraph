// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRocket_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Rocket;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Rocket()
	{
		if (!Z_Registration_Info_UPackage__Script_Rocket.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Rocket",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xBE68683E,
				0x7AE7B147,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Rocket.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Rocket.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Rocket(Z_Construct_UPackage__Script_Rocket, TEXT("/Script/Rocket"), Z_Registration_Info_UPackage__Script_Rocket, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xBE68683E, 0x7AE7B147));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
