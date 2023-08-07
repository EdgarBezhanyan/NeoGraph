// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RocketProjectile.generated.h"

UCLASS()
class ROCKET_API ARocketProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARocketProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ExposeOnSpawnHitComponent(UPrimitiveComponent* ExposeHitComponent, USceneComponent* ExposeStartHomingTargetComponent);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* m_mesh;

private:
	UPROPERTY(EditAnywhere)
		UPrimitiveComponent* HitComponent;
	UPROPERTY(EditAnywhere)
		USceneComponent* StartHomingTargetComponent;



};
