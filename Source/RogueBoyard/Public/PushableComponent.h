// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PushableComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROGUEBOYARD_API UPushableComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPushableComponent();
	UFUNCTION(BlueprintCallable)
	void Push(FVector Dir, float Force);

	UPROPERTY(BlueprintReadWrite)
	bool bIsPushed = false;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<AActor> MyOwner;

};
