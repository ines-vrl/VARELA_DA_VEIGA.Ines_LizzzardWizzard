﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RogueCharacter.generated.h"

enum class ERogueCharacterStateID : uint8;
class URoguePurse;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterPushed);
class UBoxComponent;
class ARogueRoomPawn;
class URogueCharacterStateMachine;
UCLASS()
class ROGUEBOYARD_API ARogueCharacter : public ACharacter
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBoxComponent* Box;
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnCharacterDeath OnCharacterDeathEvent;
	UPROPERTY(BlueprintReadOnly)
	FVector ForwardVector;
	
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpeedNerf;

	UPROPERTY(BlueprintReadWrite)
	float speedNerfPrivate;
#pragma endregion
#pragma region Life
public:
	UFUNCTION(BlueprintCallable)
	void TakeDamage(int Damage);
	
	UFUNCTION(BlueprintCallable)
	void Resurrect();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Resurrect"))
	void ReceiveResurrect();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int LivesMAX = 3;
	
	UPROPERTY(BlueprintReadWrite)
	int CurrentLives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeInvincibleDash = 0.0f;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsInvincible = false;

private:
	void Die();
	
#pragma endregion
#pragma region Camera
public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="InvincibilityAfterParalysis"))
	void ReceiveInvincibilityAfterParalysis();
	UFUNCTION(BlueprintCallable)
	ACameraActor* GetCamera();
	UFUNCTION(BlueprintCallable)
	void SetCamera();

	UFUNCTION(BlueprintCallable)
	void SetCameraByParam(ACameraActor* cam);
private:
	UPROPERTY()
	ACameraActor* Camera;
#pragma endregion
#pragma region Economy
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	URoguePurse* Purse;
#pragma endregion
	
	UFUNCTION(BlueprintCallable)
	void UnPossessCharacter(ARogueRoomPawn* Room);

	UFUNCTION(BlueprintImplementableEvent, Category = "OnPushedWhenPushing")
	void CancelPushing_Implementation(ERogueCharacterStateID StateID);

	UFUNCTION(BlueprintImplementableEvent, Category= "Pushed")
	void OnPushed();

	UFUNCTION(BlueprintImplementableEvent)
	void TriggerFinishPushed();

	UPROPERTY(BlueprintAssignable)
	FOnCharacterPushed OnCharacterPushedEvent;
	
	UPROPERTY(BlueprintReadOnly)
	int PlayerIndex = -1;

	UPROPERTY(BlueprintReadWrite)
	bool bIsInBlackHole = false;

	UPROPERTY(BlueprintReadWrite)
	bool bDashed = false;
	UPROPERTY(BlueprintReadWrite)
	float buffInBlackHole;

	bool operator==(const ARogueCharacter& other) const
	{
		return other.PlayerIndex == PlayerIndex;
	}
};
