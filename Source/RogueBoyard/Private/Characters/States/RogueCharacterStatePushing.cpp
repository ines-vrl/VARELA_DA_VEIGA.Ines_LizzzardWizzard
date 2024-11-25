// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/RogueCharacterStatePushing.h"

#include "PushableComponent.h"
#include "Characters/RogueCharacter.h"
#include "Characters/RogueCharacterStateMachine.h"


ERogueCharacterStateID URogueCharacterStatePushing::GetStateID()
{
	return ERogueCharacterStateID::Pushing;
}

void URogueCharacterStatePushing::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	bPushing = true;
	Character->GetMesh()->PlayAnimation(StartAttack, false);
	if(StartAttack) StartAnimTimeRemaining = StartAttack->GetPlayLength();
}

void URogueCharacterStatePushing::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	bPushing = false;
}

void URogueCharacterStatePushing::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	StartAnimTimeRemaining -= DeltaTime;
	if(StartAnimTimeRemaining <= 0)
	{
		Character->GetMesh()->PlayAnimation(ChargingAttack, true);
		//if(StateMachine->Sticks.Length() != 0)
		//{
		//	StateMachine->ChangeState(ERogueCharacterStateID::Run);
		//}
		//else
		//{
		//	StateMachine->ChangeState(ERogueCharacterStateID::Idle);
		//}
	}
}

bool URogueCharacterStatePushing::Push(TArray<AActor*> Actors , float PushForce)
{
	for (AActor* Actor : Actors)
	{
		FVector Dir = Actor->GetActorLocation() - Character->GetActorLocation();
		Dir.Normalize();
		UPushableComponent* pushComp = Cast<UPushableComponent>(Actor->GetComponentByClass(UPushableComponent::StaticClass()));
		if(pushComp != nullptr) pushComp->Push(Dir, PushForce);
	}
	Character->GetMesh()->PlayAnimation(Attacking, false);
	return true;
}

