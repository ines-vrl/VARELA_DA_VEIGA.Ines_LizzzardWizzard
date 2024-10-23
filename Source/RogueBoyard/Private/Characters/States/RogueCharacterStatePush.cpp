// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/RogueCharacterStatePush.h"

#include "Characters/RogueCharacter.h"
#include "Characters/RogueCharacterStateMachine.h"
#include "Components/BoxComponent.h"


ERogueCharacterStateID URogueCharacterStatePush::GetStateID()
{
	return ERogueCharacterStateID::Push;
}

void URogueCharacterStatePush::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->GetMesh()->PlayAnimation(PushMontage, false);
	if(PushMontage) PushAnimTimeRemaining = PushMontage->GetPlayLength();
}

void URogueCharacterStatePush::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
}

void URogueCharacterStatePush::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	PushAnimTimeRemaining -= DeltaTime;
	if(PushAnimTimeRemaining <= 0)
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

void URogueCharacterStatePush::Push(TArray<AActor*> Actors)
{
	for (AActor* Actor : Actors)
	{
		//Actor->GetComponentByClass(UPrimitiveComponent*)->
		//TODO Pushactors
	}
}

