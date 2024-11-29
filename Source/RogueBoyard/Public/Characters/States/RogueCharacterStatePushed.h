// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RogueCharacterState.h"
#include "RogueCharacterStatePushed.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROGUEBOYARD_API URogueCharacterStatePushed : public URogueCharacterState
{
	GENERATED_BODY()
public:
	virtual ERogueCharacterStateID GetStateID() override;
	virtual void StateEnter(ERogueCharacterStateID PreviousStateID) override;
	virtual void StateExit(ERogueCharacterStateID NextStateID) override;
	virtual void StateTick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimationAsset> PushedMontage;

private:
	FHitResult HitResult;
};
