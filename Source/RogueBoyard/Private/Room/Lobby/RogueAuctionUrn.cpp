#include "Room/Lobby/RogueAuctionUrn.h"

#include "Components/BoxComponent.h"


ARogueAuctionUrn::ARogueAuctionUrn()
{
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<UBoxComponent>("Root");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Collider);
}

int ARogueAuctionUrn::GetBids() const
{
	return Bids;
}

void ARogueAuctionUrn::AddBid()
{
	Bids += 1;
}

void ARogueAuctionUrn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARogueAuctionUrn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

