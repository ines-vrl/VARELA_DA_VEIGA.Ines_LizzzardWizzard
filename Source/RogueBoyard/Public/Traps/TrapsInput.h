// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TrapsInput.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UTrapsInput : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

class ROGUEBOYARD_API ITrapsInput
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Started();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Stopped();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Trigger(const FVector& InputAxis);
};
