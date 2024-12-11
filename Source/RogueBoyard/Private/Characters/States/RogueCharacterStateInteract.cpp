// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/RogueCharacterStateInteract.h"

#include "Characters/RogueCharacter.h"
#include "Characters/RogueCharacterStateMachine.h"
#include "Components/BoxComponent.h"


ERogueCharacterStateID URogueCharacterStateInteract::GetStateID()
{
	return ERogueCharacterStateID::Interact;
}

void URogueCharacterStateInteract::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	UE_LOG(LogTemp, Warning, TEXT("Interact state entered"));
}

void URogueCharacterStateInteract::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	bInteracted = false;
	UE_LOG(LogTemp, Warning, TEXT("Interact state exit"));
}

void URogueCharacterStateInteract::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	if(bInteracted)
	{
		InteractAnimTime -= DeltaTime;
		if(InteractAnimTime <= 0)
		{
			if(StateMachine->Sticks.Length() != 0)
			{
				StateMachine->ChangeState(ERogueCharacterStateID::Run);
			}
			else
			{
				StateMachine->ChangeState(ERogueCharacterStateID::Idle);
			}
		}
	}
}

TArray<AActor*> URogueCharacterStateInteract::Interact()
{
	Super::Interact();
	if(bInteracted) return TArray<AActor*>();
	InteractAnimTime = InteractMontage->GetPlayLength();
	Character->PlayAnimMontage(InteractMontage);
	TArray<AActor*> OverlappingActors;
	Character->Box->GetOverlappingActors(OverlappingActors);
	GEngine->AddOnScreenDebugMessage(
	-1,
	2.f,
	FColor::Cyan,
	TEXT("InteractC++")
	);
	bInteracted = true;
	return OverlappingActors;
}
