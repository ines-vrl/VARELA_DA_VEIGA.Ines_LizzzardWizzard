#include "Economy/RogueCoin.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"


ARogueCoin::ARogueCoin() {
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<USphereComponent>("Collider");
	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("CoinMesh");
	CoinMesh->SetupAttachment(Collider);
}

void ARogueCoin::BeginPlay() {
	Super::BeginPlay();
	
}

void ARogueCoin::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

