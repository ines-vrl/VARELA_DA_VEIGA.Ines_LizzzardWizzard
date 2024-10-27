// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/RogueCharacterStateDead.h"

#include "Characters/RogueCharacter.h"
#include "Characters/RogueCharacterStateMachine.h"


ERogueCharacterStateID URogueCharacterStateDead::GetStateID()
{
	return ERogueCharacterStateID::Dead;
}

void URogueCharacterStateDead::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->GetMesh()->PlayAnimation(DeadMontage, false);
	if(ResurectMontage) ResurectAnimTimeRemaining = ResurectMontage->GetPlayLength();
}

void URogueCharacterStateDead::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	Character->CurrentLives = Character->LivesMAX;
	bRespawned = false;
}

void URogueCharacterStateDead::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	if(Character->GetMesh()->GetAnimInstance()->Montage_IsPlaying(ResurectMontage))
	{
		if(!bRespawned)
		{
			Character->SetActorLocation(RespawnTransform.GetLocation(), false);
			bRespawned = true;
		}

		ResurectAnimTimeRemaining -= DeltaTime;
		if(ResurectAnimTimeRemaining <= 0)
		{
			StateMachine->ChangeState(ERogueCharacterStateID::Idle);
		}
	}
}

void URogueCharacterStateDead::Resurrect()
{
	Super::Resurrect();
	Character->GetMesh()->PlayAnimation(DeadMontage, false);
}
