// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/RogueCharacterStatePushing.h"

#include <filesystem>

#include "PushableComponent.h"
#include "Characters/RogueCharacter.h"
#include "Characters/RogueCharacterStateMachine.h"
#include "Camera/CameraActor.h"
#include "Traps/Enemy.h"


ERogueCharacterStateID URogueCharacterStatePushing::GetStateID()
{
	return ERogueCharacterStateID::Pushing;
}

void URogueCharacterStatePushing::StateEnter(ERogueCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	UE_LOG(LogTemp, Warning, TEXT("Enter Pushing"));
	bPushing = true;
	if(Character->StateMachine->Sticks.Length() != 0)
	{
		Character->PlayAnimMontage(RunStartAttack);
		float Rate = RunStartAttack->RateScale;
		if( Rate == 0) Rate = 1;
		StartAnimTimeRemaining = RunStartAttack->GetPlayLength() / Rate;
	}
	else
	{
		Character->PlayAnimMontage(StartAttack);
		float Rate = StartAttack->RateScale;
		if( Rate == 0) Rate = 1;
		StartAnimTimeRemaining = StartAttack->GetPlayLength() / Rate;
	}


}

void URogueCharacterStatePushing::StateExit(ERogueCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	bPushing = false;
	bCharging = false;
	bPushed = false;
	bCanpush = true;
	UE_LOG(LogTemp, Warning, TEXT("Exit Pushing"));
	if(Character->GetMesh()->GetAnimInstance()->Montage_IsPlaying(Attacking))
	{
		Character->StopAnimMontage(Attacking);
	}
	else if (Character->GetMesh()->GetAnimInstance()->Montage_IsPlaying(RunAttacking))
	{
		Character->StopAnimMontage(RunAttacking);
	}
	ActorsToApplyForce.Empty();
	//Character->CancelPushing_Implementation(NextStateID);
	
}

void URogueCharacterStatePushing::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	StartAnimTimeRemaining -= DeltaTime;
	if( !bPushed &&StartAnimTimeRemaining <= 0.5f && !bCharging && StateMachine->Sticks.Length() != 0)
	{
		Character->PlayAnimMontage(RunChargingAttack);
		bCharging = true;
	}
	else if(!bPushed &&StartAnimTimeRemaining <= 0.5f && !bCharging && StateMachine->Sticks.Length() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("IdleCHarging"));
		Character->PlayAnimMontage(ChargingAttack);
		bCharging = true;
	}
	else if(!bPushed && Character->GetMesh()->GetAnimInstance()->Montage_IsPlaying(ChargingAttack) && bCharging && StateMachine->Sticks.Length() != 0)
	{
		Character->PlayAnimMontage(RunChargingAttack);
	}
	else if(!bPushed && Character->GetMesh()->GetAnimInstance()->Montage_IsPlaying(RunChargingAttack) && bCharging && StateMachine->Sticks.Length() == 0)
	{
		Character->PlayAnimMontage(ChargingAttack);
	}
	else if (bPushed)
	{
		StartAnimTimeRemaining -= DeltaTime;
		if(StartAnimTimeRemaining <= 0)
		{
			bPushed = false;
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

void URogueCharacterStatePushing::Push()
{
	Super::Push();
}

void URogueCharacterStatePushing::Movement(float X, float Y)
{
	Super::Movement(X, Y);
	const FVector XAxisRelativeToCamera = Character->GetCamera()->GetActorRightVector();
	const FVector YAxisRelativeToCamera = Character->GetCamera()->GetActorForwardVector().RotateAngleAxis(Character->GetCamera()->GetActorRotation().Pitch , XAxisRelativeToCamera);
	Character->ForwardVector = YAxisRelativeToCamera * Y + XAxisRelativeToCamera * X;
	Character->AddMovementInput(Character->GetCamera()->GetActorRightVector(), X);
	Character->AddMovementInput(YAxisRelativeToCamera, Y);
}

bool URogueCharacterStatePushing::Pushing(TArray<AActor*> Actors , float PushForce)
{
	if(bCanpush)
	{
		bCharging = false;
		int i = 0;
		//UE_LOG(LogTemp, Warning, TEXT("Attacking"));
		if(Character->StateMachine->Sticks.Length() != 0)
		{
			Character->PlayAnimMontage(RunAttacking);
			float Rate = RunAttacking->RateScale;
			if( Rate == 0) Rate = 1;
			StartAnimTimeRemaining = RunAttacking->GetPlayLength() / Rate;
		}
		else
		{
			Character->PlayAnimMontage(Attacking);
			float Rate = Attacking->RateScale;
			if( Rate == 0) Rate = 1;
			StartAnimTimeRemaining = Attacking->GetPlayLength() / Rate;
			UE_LOG(LogTemp, Warning, TEXT("Idle Attack"));
		}
		ForceToApply = PushForce;
		ActorsToApplyForce.Empty();
		for (AActor* Actor : Actors)
		{
			ActorsToApplyForce.Add(Actor);
			i++;
		}
		bCanpush = false;
		bPushed = true;
		return i > 0;
	}
	return false;

}

void URogueCharacterStatePushing::ApplyPushing(TArray<AActor*> Actors)
{
	for (AActor* Actor : Actors)
	{
		AEnemy* Enemy = Cast<AEnemy>(Actor);
		if(Enemy)
		{
			Enemy->ReceiveDie();
		}
		if(Cast<ARogueCharacter>(Actor) == this->Character) continue;
		FVector Dir = Actor->GetActorLocation() - Character->GetActorLocation();
		Dir.Normalize();
		UPushableComponent* pushComp = Cast<UPushableComponent>(Actor->GetComponentByClass(UPushableComponent::StaticClass()));
		if(pushComp != nullptr)
		{
			pushComp->Push(Dir, ForceToApply);
		}
	}
}	

