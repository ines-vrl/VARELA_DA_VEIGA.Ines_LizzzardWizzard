// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBoyard/Public/Characters/States/RogueCharacterStateRun.h"

#include "Camera/CameraActor.h"
#include "Characters/RogueCharacterStateMachine.h"
#include "Characters/States/RogueCharacterStateDash.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "RogueBoyard/Public/Characters/RogueCharacter.h"


ERogueCharacterStateID URogueCharacterStateRun::GetStateID()
{
	return ERogueCharacterStateID::Run;
}

void URogueCharacterStateRun::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->GetMesh()->PlayAnimation(RunMontage, true);
}

void URogueCharacterStateRun::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
}

void URogueCharacterStateRun::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	if(StateMachine->Sticks.X == 0 && StateMachine->Sticks.Y == 0)
	{
		StateMachine->ChangeState(ERogueCharacterStateID::Idle);
	}
}

void URogueCharacterStateRun::Movement(float X, float Y)
{
	Super::Movement(X, Y);
	Character->AddMovementInput(Character->GetCamera()->GetActorRightVector(), X);
	Character->AddMovementInput(Character->GetCamera()->GetActorForwardVector(), Y);
	
}

bool URogueCharacterStateRun::Dash(float X, float Y)
{
	Super::Dash(X, Y);
	StateMachine->ChangeState(ERogueCharacterStateID::Dash);
	/*FVector Direction = FVector(X, Y, 0.0f);
	URogueCharacterStateDash* DashState = Cast<URogueCharacterStateDash>(StateMachine->CurrentState);
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

TArray<AActor*> URogueCharacterStateRun::Interact()
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

bool URogueCharacterStateRun::Push(TArray<AActor*> Actors)
{
	Super::Push(Actors);
	StateMachine->ChangeState(ERogueCharacterStateID::Pushing);
	return StateMachine->CurrentState->Push(Actors);
}
