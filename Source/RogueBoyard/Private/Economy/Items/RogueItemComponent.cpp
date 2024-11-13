#include "Economy/Items/RogueItemComponent.h"

#include "Economy/Items/RogueItem.h"

URogueItemComponent::URogueItemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void URogueItemComponent::BeginPlay()
{
	Super::BeginPlay();
}

void URogueItemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void URogueItemComponent::UseItem() const
{
	if(!CurrentItem)
	{
		return;
	}
	
	CurrentItem->Use(GetOwner());
	OnItemUsedEvent.Broadcast();
}

