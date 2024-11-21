// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Wall_P.generated.h"

struct FProcMeshTangent;

USTRUCT()
struct FMeshStruct
{
	GENERATED_BODY()
	TArray<FVector> Vertices;
	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector2D> UVs;
	TArray<int32> Triangles;
};

USTRUCT(Blueprintable)
struct FTileBrush
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector TileCoords = FVector(0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bNorth = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSouth = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bWest = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEast = false;
	
};

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
	void ProceduralPlatform(TArray<FTileBrush> Tiles, float GridSize, float Height, float Thickness);

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UProceduralMeshComponent* ProceduralMesh;
	

private:
	TArray<FVector> CalculateCoordinates(FVector Start, FVector End, float Height, float Thickness);
	void CalculateCoordinatesForPlatforms(TArray<FTileBrush> Tiles, float GridSize, FMeshStruct& Mesh, float Height, int32& VertexOffset, float Thickness);
	void CalculateVerticesCoords(TArray<FVector> Coordinates, FMeshStruct& Mesh, float Height, float GridSize, int32 &VertexOffset,
		bool bNorth = false,
		bool bSouth = false,
		bool bWest = false,
		bool bEst = false);
	void CalculateFace(FMeshStruct& Mesh, FVector P0, FVector P1,FVector P2,FVector P3, FVector Normal, FVector Tangent, int32 &VertexOffset);
	TArray<int> MakeTriangles(); 
	TArray<FVector> CalculateNormals(FVector Start, FVector End);
	TArray<FVector> CalculateTangents(FVector Start, FVector End);
	
};
