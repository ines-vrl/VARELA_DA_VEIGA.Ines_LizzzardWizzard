// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RogueCharacter.generated.h"

class URogueCharacterStateMachine;
UCLASS()
class ROGUEBOYARD_API ARogueCharacter : public ACharacter
{
	GENERATED_BODY()
#pragma region Unreal Default
public:
	// Sets default values for this character's properties
	ARogueCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
#pragma endregion
#pragma region State Machine

public:
	void CreateStateMachine();
	void InitStateMachine();
	void TickStateMachine(float DeltaTime) const;
	
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<URogueCharacterStateMachine> StateMachine;
#pragma endregion
#pragma region Life
public:
	UFUNCTION(BlueprintCallable)
	bool TakeDamage(int Damage);
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int LivesMAX = 3;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int CurrentLives;

private:
	void Die();
	
#pragma endregion
};
