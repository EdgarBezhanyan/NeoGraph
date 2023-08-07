// Fill out your copyright notice in the Description page of Project Settings.


#include "RocketProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include <Kismet/GameplayStatics.h>



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
	PlayerPawn = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	timeLineInit();
	BeginPlayFire();
}

// Called every frame
void ARocketProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SpeedTimeline != NULL)
	{
		SpeedTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
	}
}

void ARocketProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
{
	OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
	Destroy();
}
}

void ARocketProjectile::ExposeOnSpawnHitComponent(UPrimitiveComponent* ExposeHitComponent, USceneComponent* ExposeStartHomingTargetComponent)
{
	HitComponent = ExposeHitComponent;
	StartHomingTargetComponent = ExposeStartHomingTargetComponent;
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

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

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
		SpeedTimeline->AddInterpFloat(CurveFloat, TimelineCallback);
		SpeedTimeline->SetTimelineFinishedFunc(TimelineFinishedCallback);

		SpeedTimeline->RegisterComponent();
	}
}

void ARocketProjectile::BeginPlayFire()
{
	if (checkIfHomingStart()) {
		ProjectileMovement->HomingTargetComponent = StartHomingTargetComponent;
		SpeedTimeline->PlayFromStart();
	}
	else {
		setHitObjectComponent();
	}
}

bool ARocketProjectile::checkIfHomingStart()
{
	if (PlayerPawn->GetVelocity().Length() > minSpeed) {
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


void ARocketProjectile::TimelineCallback(float Value)
{
	if(checkIfHomingStart()){
		setSpeed(InitSpeedBoost, MaxSpeedBoost, PlayerPawn->GetVelocity().Length());
	}
	else {
		setHitObjectComponent();
	}
}

void ARocketProjectile::TimelineFinishedCallback()
{
	setHitObjectComponent();
}

