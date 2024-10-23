// Fill out your copyright notice in the Description page of Project Settings.


#include "PushableComponent.h"

#include "Characters/RogueCharacter.h"
#include "Characters/RogueCharacterStateID.h"
#include "Characters/RogueCharacterStateMachine.h"


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
		ARogueCharacter* Character = Cast<ARogueCharacter>(MyOwner);
		FVector Impulse = Dir * Force;
		Impulse.Z = 100.f;
		if(Character == nullptr)
		{
			UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(MyOwner->GetRootComponent());
			if(PrimitiveComponent != nullptr)
			{
				if(!PrimitiveComponent->IsSimulatingPhysics()) PrimitiveComponent->SetSimulatePhysics(true);
				
				ECollisionEnabled::Type CollisionEnabled = PrimitiveComponent->GetCollisionEnabled();
				
				if(PrimitiveComponent->GetCollisionEnabled() != ECollisionEnabled::QueryAndPhysics)
				{
					PrimitiveComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
				}
				
				PrimitiveComponent->AddImpulse(Impulse, NAME_None, true);
				PrimitiveComponent->SetCollisionEnabled(CollisionEnabled);
			}
		}
		else
		{
			Character->StateMachine->ChangeState(ERogueCharacterStateID::Pushed);
			Character->LaunchCharacter(Impulse, false, false);
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

