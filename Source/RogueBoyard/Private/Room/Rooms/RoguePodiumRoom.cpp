// Fill out your copyright notice in the Description page of Project Settings.


#include "Room/Rooms/RoguePodiumRoom.h"


// Sets default values
ARoguePodiumRoom::ARoguePodiumRoom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bBeginThePlay = false;
}

// Called when the game starts or when spawned
void ARoguePodiumRoom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoguePodiumRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

