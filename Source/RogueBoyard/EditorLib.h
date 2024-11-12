// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EditorLib.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorSelectionChanged, AActor*, SelectedActor);
/**
 * 
 */
UCLASS()
class ROGUEBOYARD_API AEditorLib : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Editor)
	float SnapDistance;
	
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnActorSelectionChanged OnActorSelectionChanged;

	UFUNCTION(BlueprintCallable, Category="Editor")
	void StartListening();

	UFUNCTION(BlueprintCallable, Category="Editor")
	void StopListening();

	UFUNCTION(BlueprintCallable, Category="Editor")
	void ProceduralWall(FVector Start, FVector End);
	
	UFUNCTION(BlueprintCallable, Category="Editor")
	void SavePoint(FVector Point);

	UFUNCTION(BlueprintCallable, Category="Editor")
	FVector FindPoint(FVector End);
	
private:
	void HandleActorSelectionChanged(const TArray<UObject*>& NewSelection, bool bForceRefresh);

	UPROPERTY(EditAnywhere, Category="Editor")
	TArray<FVector> Points;
};
