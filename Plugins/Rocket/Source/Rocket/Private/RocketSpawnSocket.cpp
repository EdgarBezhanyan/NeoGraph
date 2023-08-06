// Fill out your copyright notice in the Description page of Project Settings.


#include "RocketSpawnSocket.h"

// Sets default values
ARocketSpawnSocket::ARocketSpawnSocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

void ARocketSpawnSocket::Fire(FVector start, FVector normal)
{

}

