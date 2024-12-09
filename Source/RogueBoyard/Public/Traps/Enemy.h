// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PushableComponent.h"
#include "Characters/States/RogueCharacterStatePushed.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UENUM(BlueprintType, Blueprintable)
enum class EEnemyType : uint8
{
	None = 0,
	Kill,
	Stun,
	Push
};
UCLASS()
class ROGUEBOYARD_API AEnemy : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Blueprintable, Category="Enemy|SearchMovement")
	float MoveAmplitudeX = 500.0f;

	UPROPERTY(EditAnywhere,Blueprintable, Category="Enemy|SearchMovement")
	float MoveAmplitudeY = 300.0f;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Enemy|SearchMovement")
	EEnemyType EnemyType = EEnemyType::Kill;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Enemy|SearchMovement")
	float SearchMoveSpeed = 2.0f;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Enemy")
	float PushForce;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Enemy")
	int LifeSpan;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Enemy")
	float MoveSpeed = 1;
	

private :
	UFUNCTION(BlueprintCallable)
	void Push(TArray<AActor*> Players);
	
	UFUNCTION(BlueprintCallable)
	void Kill(ARogueCharacter* Character);

	UFUNCTION(BlueprintCallable)
	void SearchMovement(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void MoveToPlayer(AActor* Player,float DeltaTime);

	FVector InitialPosition;
	float CurrentTime;
};
