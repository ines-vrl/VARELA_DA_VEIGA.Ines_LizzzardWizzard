// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Characters/States/RogueCharacterStateIdle.h"

#include "Characters/RogueCharacterStateMachine.h"
#include "Characters/States/RogueCharacterStateDash.h"
#include "Components/BoxComponent.h"
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

bool URogueCharacterStateIdle::Dash(float X, float Y)
{
	Super::Dash(X, Y);
	StateMachine->ChangeState(ERogueCharacterStateID::Dash);
	FVector Direction = FVector(X, Y, 0.0f);
	/*URogueCharacterStateDash* DashState = Cast<URogueCharacterStateDash>(StateMachine->CurrentState);
	if(Direction.IsZero())
	{
		Direction = Character->GetMesh()->GetRightVector() * DashState->ForceImpulse;
		Character->LaunchCharacter(Direction, true, false);
	}
	else
	{
		Character->LaunchCharacter(Direction * DashState->ForceImpulse,	 true, false);
	}*/
	return true;
}

TArray<AActor*> URogueCharacterStateIdle::Interact()
{
	Super::Interact();
	TArray<AActor*> OverlappingActors;
	Character->Box->GetOverlappingActors(OverlappingActors);
	GEngine->AddOnScreenDebugMessage(
	-1,
	2.f,
	FColor::Cyan,
	TEXT("InteractC++")
	);
	return OverlappingActors;
}

bool URogueCharacterStateIdle::Push(TArray<AActor*> Actors, float PushForce)
{
	Super::Push(Actors, PushForce);
	StateMachine->ChangeState(ERogueCharacterStateID::Pushing);
	return StateMachine->CurrentState->Push(Actors, PushForce);
}


