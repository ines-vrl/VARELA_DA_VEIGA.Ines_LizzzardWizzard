#include "Room/RogueDoor.h"

ARogueDoor::ARogueDoor()
{
	PrimaryActorTick.bCanEverTick = true;
	CreateDefaultSubobject<UStaticMesh>("Door");
}


void ARogueDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARogueDoor::Open_Implementation()
{
	if (bIsOpen)
	{
		return;
	}
	bIsOpen = true;
}

void ARogueDoor::Close_Implementation()
{
	if(!bIsOpen)
	{
		return;
	}
	bIsOpen = false;
}
