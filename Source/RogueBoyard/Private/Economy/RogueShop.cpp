#include "Economy/RogueShop.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

ARogueShop::ARogueShop()
{
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<UCapsuleComponent>("RootCollider");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Collider);
}

void ARogueShop::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARogueShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

