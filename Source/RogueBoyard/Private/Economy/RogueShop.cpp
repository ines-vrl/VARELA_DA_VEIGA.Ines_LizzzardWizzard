#include "Economy/RogueShop.h"

#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Economy/Items/RogueItem.h"

ARogueShop::ARogueShop()
{
	PrimaryActorTick.bCanEverTick = false;
	Collider = CreateDefaultSubobject<UCapsuleComponent>("RootCollider");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Collider);
}


FShopItemData ARogueShop::BuyItem()
{
	OnItemBoughtEvent.Broadcast();
	return Item;
}

void ARogueShop::BeginPlay()
{
	Super::BeginPlay();
}
