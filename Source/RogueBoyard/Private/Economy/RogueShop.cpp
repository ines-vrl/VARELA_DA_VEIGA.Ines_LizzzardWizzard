#include "Economy/RogueShop.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

ARogueShop::ARogueShop()
{
	PrimaryActorTick.bCanEverTick = false;
	Collider = CreateDefaultSubobject<UCapsuleComponent>("RootCollider");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Collider);
}


int ARogueShop::BuyItem() {
	OnItemBoughtEvent.Broadcast();
	Destroy(); //TODO Trouver un truc mieux
	return Item.Price;
}

void ARogueShop::BeginPlay()
{
	Super::BeginPlay();
}
