// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Rocket/Public/RocketSpawnSocket.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRocketSpawnSocket() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ROCKET_API UClass* Z_Construct_UClass_ARocketSpawnSocket();
	ROCKET_API UClass* Z_Construct_UClass_ARocketSpawnSocket_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Rocket();
// End Cross Module References
	void ARocketSpawnSocket::StaticRegisterNativesARocketSpawnSocket()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARocketSpawnSocket);
	UClass* Z_Construct_UClass_ARocketSpawnSocket_NoRegister()
	{
		return ARocketSpawnSocket::StaticClass();
	}
	struct Z_Construct_UClass_ARocketSpawnSocket_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARocketSpawnSocket_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Rocket,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARocketSpawnSocket_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RocketSpawnSocket.h" },
		{ "ModuleRelativePath", "Public/RocketSpawnSocket.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARocketSpawnSocket_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARocketSpawnSocket>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ARocketSpawnSocket_Statics::ClassParams = {
		&ARocketSpawnSocket::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ARocketSpawnSocket_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARocketSpawnSocket_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARocketSpawnSocket()
	{
		if (!Z_Registration_Info_UClass_ARocketSpawnSocket.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARocketSpawnSocket.OuterSingleton, Z_Construct_UClass_ARocketSpawnSocket_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ARocketSpawnSocket.OuterSingleton;
	}
	template<> ROCKET_API UClass* StaticClass<ARocketSpawnSocket>()
	{
		return ARocketSpawnSocket::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARocketSpawnSocket);
	ARocketSpawnSocket::~ARocketSpawnSocket() {}
	struct Z_CompiledInDeferFile_FID_User_Documents_Unreal_Projects_MyProject2_Plugins_Rocket_Source_Rocket_Public_RocketSpawnSocket_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_User_Documents_Unreal_Projects_MyProject2_Plugins_Rocket_Source_Rocket_Public_RocketSpawnSocket_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ARocketSpawnSocket, ARocketSpawnSocket::StaticClass, TEXT("ARocketSpawnSocket"), &Z_Registration_Info_UClass_ARocketSpawnSocket, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARocketSpawnSocket), 1688613028U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_User_Documents_Unreal_Projects_MyProject2_Plugins_Rocket_Source_Rocket_Public_RocketSpawnSocket_h_365096312(TEXT("/Script/Rocket"),
		Z_CompiledInDeferFile_FID_User_Documents_Unreal_Projects_MyProject2_Plugins_Rocket_Source_Rocket_Public_RocketSpawnSocket_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_User_Documents_Unreal_Projects_MyProject2_Plugins_Rocket_Source_Rocket_Public_RocketSpawnSocket_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
