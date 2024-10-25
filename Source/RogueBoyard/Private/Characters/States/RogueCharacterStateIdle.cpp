// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Characters/States/RogueCharacterStateIdle.h"

#include "Characters/RogueCharacterStateMachine.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "RogueBoyard/Public/Characters/RogueCharacter.h"


ERogueCharacterStateID URogueCharacterStateIdle::GetStateID()
{
	return ERogueCharacterStateID::Idle;
}

void URogueCharacterStateIdle::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->GetMesh()->PlayAnimation(IdleMontage, true);
}

void URogueCharacterStateIdle::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	GEngine->AddOnScreenDebugMessage(
	-1,
	0.1f,
	FColor::Red,
	TEXT("Exit idle")
	);
}

void URogueCharacterStateIdle::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
}

void URogueCharacterStateIdle::Movement(float X, float Y)
{
	Super::Movement(X, Y);
	GEngine->AddOnScreenDebugMessage(
	-1,
	2.f,
	FColor::Cyan,
	TEXT("Moving")
	);
	StateMachine->ChangeState(ERogueCharacterStateID::Run);
}

void URogueCharacterStateIdle::Dash(float X, float Y)
{
	Super::Dash(X, Y);
	if(StateMachine->Sticks.X > 0.f || StateMachine->Sticks.Y > 0.f)
	{
		StateMachine->ChangeState(ERogueCharacterStateID::Dash);
	}
}

TArray<AActor*> URogueCharacterStateIdle::Interact()
{
	Super::Interact();
	TArray<AActor*> OverlappingActors;
	Character->GetOverlappingActors(OverlappingActors);
	return OverlappingActors;
}

void URogueCharacterStateIdle::Push(TArray<AActor*> Actors)
{
	Super::Push(Actors);
	StateMachine->ChangeState(ERogueCharacterStateID::Pushing);
}


