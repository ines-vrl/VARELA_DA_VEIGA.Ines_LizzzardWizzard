// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RogueCharacterState.h"
#include "RogueCharacterStatePush.generated.h"


class UBoxComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROGUEBOYARD_API URogueCharacterStatePush : public URogueCharacterState
{
	GENERATED_BODY()

public:
	virtual ERogueCharacterStateID GetStateID() override;
	virtual void StateEnter(ERogueCharacterStateID PreviousStateID) override;
	virtual void StateExit(ERogueCharacterStateID NextStateID) override;
	virtual void StateTick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Push(TArray<AActor*> Actors);

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimationAsset> PushMontage;

	UPROPERTY(EditAnywhere)
	float PushForce;
	
private:
	float PushAnimTimeRemaining;
};
