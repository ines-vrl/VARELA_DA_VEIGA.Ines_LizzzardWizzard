// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RogueCharacterState.h"
#include "RogueCharacterStatePushing.generated.h"


class UBoxComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROGUEBOYARD_API URogueCharacterStatePushing : public URogueCharacterState
{
	GENERATED_BODY()

public:
	virtual ERogueCharacterStateID GetStateID() override;
	virtual void StateEnter(ERogueCharacterStateID PreviousStateID) override;
	virtual void StateExit(ERogueCharacterStateID NextStateID) override;
	virtual void StateTick(float DeltaTime) override;

	
	
	virtual void Push(TArray<AActor*> Actors) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimationAsset> PushingMontage;

	UPROPERTY(EditAnywhere)
	float PushForce;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float PushingCoolDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bPushing;
	
private:
	float PushAnimTimeRemaining;
};
