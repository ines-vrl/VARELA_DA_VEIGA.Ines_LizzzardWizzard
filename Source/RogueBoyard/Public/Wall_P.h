// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wall_P.generated.h"

struct FProcMeshTangent;
class UProceduralMeshComponent;

UCLASS()
class ROGUEBOYARD_API AWall_P : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWall_P();

	UFUNCTION(BlueprintCallable)
	void ProceduralWall(FVector Start, FVector End, float Height, float Thickness);
	UFUNCTION(BlueprintCallable)
	void ProceduralPlatform(FVector Center, FVector GridSize, float Height, float Thickness);

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UProceduralMeshComponent* ProceduralMesh;
	

private:
	TArray<FVector> CalculateCoordinates(FVector Start, FVector End, float Height, float Thickness);
	TArray<FVector> CalculateCoordinatesForPlatforms(FVector Center, FVector GridSize, float Height, float Thickness);
	void CalculateFace(TArray<FVector> &OutVertices, TArray<FVector> &OutNormals, TArray<FVector2D> &OutUVs, TArray<FProcMeshTangent> &OutTangents, TArray<int32> &Triangles,
		FVector P0, FVector P1,FVector P2,FVector P3, FVector Normal, FVector Tangent, int32 &VertexOffset);
	TArray<int> MakeTriangles(); 
	TArray<FVector> CalculateNormals(FVector Start, FVector End);
	TArray<FVector> CalculateTangents(FVector Start, FVector End);
	
};
