#include "Room/Rooms/RogueFinalRoom.h"


ARogueFinalRoom::ARogueFinalRoom() {
	PrimaryActorTick.bCanEverTick = true;
	bBeginThePlay = false;
}

void ARogueFinalRoom::BeginPlay() {
	Super::BeginPlay();
}

void ARogueFinalRoom::EndRoom() {
	Super::EndRoom();
}

void ARogueFinalRoom::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

