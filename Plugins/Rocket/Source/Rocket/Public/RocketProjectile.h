// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"

#include "RocketProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;



UCLASS()
class ROCKET_API ARocketProjectile : public AActor
{
	GENERATED_BODY()


private:
	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;




	
public:	
	// Sets default values for this actor's properties
	ARocketProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	/** called when projectile hits something */
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }


	void ExposeOnSpawnHitComponent(UPrimitiveComponent* ExposeHitComponent, USceneComponent* ExposeStartHomingTargetComponent);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* m_mesh;
	UPROPERTY(EditAnywhere, Category = "Timeline")
		UCurveFloat* CurveFloat;
	FTimeline CurveTimeline;

	UPROPERTY(EditAnywhere)
		float minSpeed;
	UPROPERTY(EditAnywhere)
		float speedBoost;
	UPROPERTY(EditAnywhere)
		float InitSpeedBoost;
	UPROPERTY(EditAnywhere)
		float MaxSpeedBoost;


private:
	UPROPERTY(EditAnywhere)
		UPrimitiveComponent* HitComponent;
	UPROPERTY(EditAnywhere)
		USceneComponent* StartHomingTargetComponent;
	AActor* OwnerPawn;

private:
	void init();
	void timeLineInit();
	void BeginPlayFire();
	bool checkIfHomingStart();
	void setHitObjectComponent();
	void setSpeed(float initSpeedBoost, float maxSpeedBoost, float velocity);

public:
	UFUNCTION()
		void TimelineCallback(float Value);
	UFUNCTION()
		void TimelineFinishedCallback();




};
