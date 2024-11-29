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
	virtual void Push() override;
	virtual void Movement(float X, float Y) override;

	
	UFUNCTION(BlueprintCallable)
	bool Pushing(TArray<AActor*> Actors, float PushForce);

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimSequenceBase> StartAttack;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimSequenceBase> ChargingAttack;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimSequenceBase> Attacking;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MinForce;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TimeMax;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TimeMin;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float PushingCoolDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bPushing;
	
private:
	float StartAnimTimeRemaining;
	bool bCharging = false;
	bool bPushed = false;
};
