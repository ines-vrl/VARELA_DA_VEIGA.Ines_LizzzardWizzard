// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RogueBoyard/Private/Characters/RogueCharacterState.h"
#include "RogueCharacterStateDash.generated.h"


UCLASS(ClassGroup=(RogueCharacterState), meta=(BlueprintSpawnableComponent))
class ROGUEBOYARD_API URogueCharacterStateDash : public URogueCharacterState
{
	GENERATED_BODY()

public:

	virtual ERogueCharacterStateID GetStateID() override;
	virtual void StateEnter(ERogueCharacterStateID PreviousStateID) override;
	virtual void StateExit(ERogueCharacterStateID NextStateID) override;
	virtual void StateTick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimationAsset> DashMontage;
	
	UPROPERTY(EditAnywhere)
	float ForceImpulse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DashCoolDown;
	
private:
	FVector Sticks;
	float DashAnimTimeRemaining;
};
