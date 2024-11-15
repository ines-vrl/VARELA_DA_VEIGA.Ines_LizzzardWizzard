// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PushableComponent.h"
#include "Characters/States/RogueCharacterStatePushed.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

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

	UPROPERTY(EditAnywhere,Blueprintable, Category="Enemy")
	float PushForce;
	
	UPROPERTY(EditAnywhere,Blueprintable, Category = "Enemy")
	int LifeSpan;

	UPROPERTY(EditAnywhere,Blueprintable, Category="Enemy|SearchMovement")
	float MoveAmplitudeX = 500.0f;

	UPROPERTY(EditAnywhere,Blueprintable, Category="Enemy|SearchMovement")
	float MoveAmplitudeY = 300.0f;

	UPROPERTY(EditAnywhere,Blueprintable, Category="Enemy|SearchMovement")
	float MoveSpeed;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

private :
	UFUNCTION(BlueprintCallable)
	void Push(TArray<AActor*> Actors);

	UFUNCTION(BlueprintCallable)
	void SearchMovement(float DeltaTime);
	
	FVector NewPosition;

	FVector InitialPosition;

	float CurrentTime;
};
