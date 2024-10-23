// Fill out your copyright notice in the Description page of Project Settings.


#include "PushableComponent.h"


// Sets default values for this component's properties
UPushableComponent::UPushableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UPushableComponent::Push(FVector Dir, float Force) const
{
	if(MyOwner)
	{
		UPrimitiveComponent* PrimitiveComponent = MyOwner->FindComponentByClass<UPrimitiveComponent>();
		if(PrimitiveComponent != nullptr)
		{
			if(!PrimitiveComponent->IsSimulatingPhysics()) PrimitiveComponent->SetSimulatePhysics(true);
			
			ECollisionEnabled::Type CollisionEnabled = PrimitiveComponent->GetCollisionEnabled();
			
			if(PrimitiveComponent->GetCollisionEnabled() != ECollisionEnabled::QueryAndPhysics)
			{
				PrimitiveComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			}
			FVector Impulse = Dir * Force;
			Impulse.Z = 100.f;
			PrimitiveComponent->AddImpulse(Impulse, NAME_None, true);
			PrimitiveComponent->SetCollisionEnabled(CollisionEnabled);
		}
	}

}

// Called when the game starts
void UPushableComponent::BeginPlay()
{
	Super::BeginPlay();
	MyOwner = GetOwner();
	// ...
	
}

