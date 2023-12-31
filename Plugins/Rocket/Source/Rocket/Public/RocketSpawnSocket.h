// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "RocketProjectile.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/ArrowComponent.h"
#include "InteractInterface.h"

#include "RocketSpawnSocket.generated.h"



UCLASS()
class ROCKET_API ARocketSpawnSocket : public AActor, public IInteractInterface 
{
	GENERATED_BODY()

public:
	virtual void Fire_Implementation(FVector start, FRotator rot) override;
	// Sets default values for this actor's properties
	ARocketSpawnSocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	// functions
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private: // functions
	UFUNCTION()
		void Init();
	UFUNCTION()
		FHitResult LineTrace(FVector start, FVector forwardVector);
	UFUNCTION()
		void SpawnARocketProjectile(UPrimitiveComponent* HitComponent);
		
public: // members
	UPROPERTY(EditAnywhere)
		USceneComponent* _RootComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* m_mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		TSubclassOf<ARocketProjectile> ActorToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		UArrowComponent* Arrow;
};
