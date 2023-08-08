// Fill out your copyright notice in the Description page of Project Settings.


#include "RocketProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include <Kismet/GameplayStatics.h>
#include "Components/TimelineComponent.h"

// Sets default values
ARocketProjectile::ARocketProjectile()
{
	init();
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARocketProjectile::BeginPlay()
{
	Super::BeginPlay();
	OwnerPawn = GetOwner();
	timeLineInit();
	BeginPlayFire();
	spawnEffect(FireEffectMuzzle);
}

// Called every frame
void ARocketProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurveTimeline.TickTimeline(DeltaTime);

}

void ARocketProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
{
	if (OtherComp->IsSimulatingPhysics()) {
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
	}
	UGameplayStatics* SpawnEmmitter;
	UParticleSystemComponent* particles = SpawnEmmitter->SpawnEmitterAtLocation(GetWorld(), DestroyEffect, GetActorTransform());
	Destroy();
}
}

void ARocketProjectile::ExposeOnSpawnHitComponent(UPrimitiveComponent* ExposeHitComponent, USceneComponent* ExposeStartHomingTargetComponent)
{
	HitComponent = ExposeHitComponent;
	StartHomingTargetComponent = ExposeStartHomingTargetComponent;
	FVector Location = HitComponent->GetComponentLocation();
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("Normal Point: %s"), *HitComponent->GetName()));
}

void ARocketProjectile::init()
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(15.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ARocketProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->bIsHomingProjectile = 1;
	// Die after 3 seconds by default
	InitialLifeSpan = 20.0f;

}

void ARocketProjectile::timeLineInit()
{
	//Checking if the curvefloat that was entered in the blueprint was valid
	if (CurveFloat)
	{
		/*The ProgressFunction contains the signature of the function that is
		going to execute every time we tick our timeline.
		Think of the progressfunction as a delegate!*/
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;
		TimelineCallback.BindUFunction(this, FName{ TEXT("TimelineCallback") });
		TimelineFinishedCallback.BindUFunction(this, FName{ TEXT("TimelineFinishedCallback") });
		CurveTimeline.AddInterpFloat(CurveFloat, TimelineCallback);
		CurveTimeline.SetTimelineFinishedFunc(TimelineFinishedCallback);
		CurveTimeline.SetLooping(0);
		CurveTimeline.PlayFromStart();
	}
}

void ARocketProjectile::BeginPlayFire()
{
	if (checkIfHomingStart()) {
		ProjectileMovement->HomingTargetComponent = StartHomingTargetComponent;
		timeLineInit();
	}
	else {
		setHitObjectComponent();
	}
}

bool ARocketProjectile::checkIfHomingStart()
{

	if (OwnerPawn->GetVelocity().Length() > minSpeed) {
		return 1;
	}
	return 0;
}

void ARocketProjectile::setHitObjectComponent()
{
	if (IsValid(HitComponent)) {
		ProjectileMovement->MaxSpeed = HitComponent->GetComponentVelocity().Length() + speedBoost;
	}
	else {
		ProjectileMovement->MaxSpeed = speedBoost;
	}
	ProjectileMovement->HomingTargetComponent = HitComponent;
}

void ARocketProjectile::setSpeed(float initSpeedBoost, float maxSpeedBoost, float velocity)
{
	ProjectileMovement->InitialSpeed = initSpeedBoost + velocity;
	ProjectileMovement->MaxSpeed = maxSpeedBoost + velocity;



}

void ARocketProjectile::spawnEffect(UNiagaraSystem* Effect)
{
	if (Effect) {
		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(Effect, CollisionComp, NAME_None, FVector(0.f), FRotator(0.f), EAttachLocation::Type::KeepRelativeOffset, true);
	}
}


void ARocketProjectile::TimelineCallback(float Value)
{
	if(checkIfHomingStart()){
		setSpeed(InitSpeedBoost, MaxSpeedBoost, OwnerPawn->GetVelocity().Length());
	}
	else {
		setHitObjectComponent();
	}

}

void ARocketProjectile::TimelineFinishedCallback()
{
	setHitObjectComponent();
}

