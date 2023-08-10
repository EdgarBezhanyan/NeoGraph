// Fill out your copyright notice in the Description page of Project Settings.


#include "RocketSpawnSocket.h"

void ARocketSpawnSocket::Fire_Implementation(FVector start, FRotator rot)
{
	FHitResult OutHit = LineTrace(start, UKismetMathLibrary::GetForwardVector(rot));
	if (IsValid(OutHit.GetComponent())) {
		UPrimitiveComponent* HitComponent = OutHit.GetComponent();
		SpawnARocketProjectile(HitComponent);
	}	
}

// Sets default values
ARocketSpawnSocket::ARocketSpawnSocket()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Init();
}

// Called when the game starts or when spawned
void ARocketSpawnSocket::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ARocketSpawnSocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARocketSpawnSocket::Init()
{
	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root component"));
	RootComponent = _RootComponent;
	m_mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	m_mesh->SetupAttachment(RootComponent);
	Arrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	Arrow->SetupAttachment(RootComponent);

}



FHitResult ARocketSpawnSocket::LineTrace(FVector start, FVector forwardVector)
{
	FHitResult OutHit;
	FVector End = ((forwardVector * 100000.f) + start);
	FCollisionQueryParams CollisionParams;

	DrawDebugLine(GetWorld(), start, End, FColor::Green, false, 1, 0, 1);

	if (GetWorld()->LineTraceSingleByChannel(OutHit, start, End, ECC_Visibility, CollisionParams))
	{
		if (OutHit.bBlockingHit)
		{
			return OutHit;
		}
	}

	return OutHit;
}

void ARocketSpawnSocket::SpawnARocketProjectile(UPrimitiveComponent* HitComponent)
{
	FTransform SpawnLocAndRotation = GetActorTransform();
	SpawnLocAndRotation.SetLocation(GetActorLocation() + (UKismetMathLibrary::GetForwardVector(GetActorRotation()) * 200));
	ARocketProjectile* SpawnedActorRef = GetWorld()->SpawnActorDeferred<ARocketProjectile>(ActorToSpawn, SpawnLocAndRotation,GetOwner());
	SpawnedActorRef->ExposeOnSpawnHitComponent(HitComponent,Arrow);
	SpawnedActorRef->FinishSpawning(SpawnLocAndRotation);
	

}

