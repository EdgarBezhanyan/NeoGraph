// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "RocketSpawnSocket.generated.h"



UCLASS()
class ROCKET_API ARocketSpawnSocket : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARocketSpawnSocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	// functions
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Fire(FVector start, FVector normal);
private: // functions
	void Init();


public: // members
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* m_mesh;
};
