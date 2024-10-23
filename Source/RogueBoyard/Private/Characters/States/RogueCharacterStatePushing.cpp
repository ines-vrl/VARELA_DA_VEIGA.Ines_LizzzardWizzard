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
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(
			TEXT("Enter Pushing")));
	bPushing = true;
	Character->GetMesh()->PlayAnimation(PushingMontage, false);
	if(PushingMontage) PushAnimTimeRemaining = PushingMontage->GetPlayLength();
}

void URogueCharacterStatePushing::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	bPushing = false;
}

void URogueCharacterStatePushing::StateTick(float DeltaTime)
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

void URogueCharacterStatePushing::Push(TArray<AActor*> Actors)
{
	for (AActor* Actor : Actors)
	{
		FVector Dir = Actor->GetActorLocation() - Character->GetActorLocation();
		Dir.Normalize();
		UPushableComponent* pushComp = Cast<UPushableComponent>(Actor->GetComponentByClass(UPushableComponent::StaticClass()));
		if(pushComp != nullptr) pushComp->Push(Dir, PushForce);
	}
}

