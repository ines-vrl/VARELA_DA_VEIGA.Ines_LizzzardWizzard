// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall_P.h"
#include "ProceduralMeshComponent.h"

// Sets default values
AWall_P::AWall_P()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMesh");
}

void AWall_P::ProceduralWall(FVector Start, FVector End, float Height, float Thickness)
{
	ProceduralMesh->ClearAllMeshSections();
	
	TArray<FVector> Vertices;
	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector2D> UVs;
	TArray<int32> Triangles;
	int32 VertexOffset = 0;

	TArray<FVector> InputVert = CalculateCoordinates(Start, End, Height, Thickness);
	FVector MainAxis = (End - Start);
	MainAxis.Z = 0;
	MainAxis.Normalize();
	FVector SecondaryAxis = FVector(-MainAxis.Y, MainAxis.X, MainAxis.Z);

	//TopFace //
	FVector Normal = FVector(0, 0, 1);
	FVector Tangent = FVector(1, 0, 0);
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[4], InputVert[5], InputVert[6], InputVert[7], Normal, Tangent, VertexOffset);

	//BottomFace
	Normal = FVector(0, 0, -1);
	Tangent = FVector(-1, 0, 0);
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[3], InputVert[2], InputVert[1], InputVert[0], Normal, Tangent, VertexOffset);

	//FrontFace
	Normal = MainAxis;
	Tangent = SecondaryAxis;
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[0], InputVert[1], InputVert[5], InputVert[4], Normal, Tangent, VertexOffset);

	//BackFace//
	Normal = -MainAxis;
	Tangent = -SecondaryAxis;
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[7], InputVert[6], InputVert[2], InputVert[3], Normal, Tangent, VertexOffset);

	//LeftFace
	Normal = -SecondaryAxis;
	Tangent = MainAxis;
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[7], InputVert[3], InputVert[0], InputVert[4], Normal, Tangent, VertexOffset);

	//RightFace//
	Normal = SecondaryAxis;
	Tangent = -MainAxis;
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[2], InputVert[6], InputVert[5], InputVert[1], Normal, Tangent, VertexOffset);

	ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, Normals, UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
}

void AWall_P::ProceduralPlatform(FVector Center, FVector GridSize, float Height, float Thickness)
{
	ProceduralMesh->ClearAllMeshSections();
	
	TArray<FVector> Vertices;
	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector2D> UVs;
	TArray<int32> Triangles;
	int32 VertexOffset = 0;

	TArray<FVector> InputVert = CalculateCoordinatesForPlatforms(Center, GridSize, Height, Thickness);
	FVector MainAxis = (FVector(Center.X + GridSize.X / 2, Center.Y - GridSize.Y / 2, 0) -
		FVector(Center.X - GridSize.X / 2, Center.Y - GridSize.Y / 2, 0));
	MainAxis.Z = 0;
	MainAxis.Normalize();
	FVector SecondaryAxis = FVector(-MainAxis.Y, MainAxis.X, MainAxis.Z);

	//TopFace //
	FVector Normal = FVector(0, 0, 1);
	FVector Tangent = FVector(1, 0, 0);
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[4], InputVert[5], InputVert[6], InputVert[7], Normal, Tangent, VertexOffset);

	//BottomFace
	Normal = FVector(0, 0, -1);
	Tangent = FVector(-1, 0, 0);
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[3], InputVert[2], InputVert[1], InputVert[0], Normal, Tangent, VertexOffset);

	//FrontFace
	Normal = MainAxis;
	Tangent = SecondaryAxis;
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[0], InputVert[1], InputVert[5], InputVert[4], Normal, Tangent, VertexOffset);

	//BackFace//
	Normal = -MainAxis;
	Tangent = -SecondaryAxis;
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[7], InputVert[6], InputVert[2], InputVert[3], Normal, Tangent, VertexOffset);

	//LeftFace
	Normal = -SecondaryAxis;
	Tangent = MainAxis;
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[7], InputVert[3], InputVert[0], InputVert[4], Normal, Tangent, VertexOffset);

	//RightFace//
	Normal = SecondaryAxis;
	Tangent = -MainAxis;
	CalculateFace(Vertices, Normals, UVs, Tangents, Triangles,
		InputVert[2], InputVert[6], InputVert[5], InputVert[1], Normal, Tangent, VertexOffset);

	ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, Normals, UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
}

TArray<FVector> AWall_P::CalculateCoordinates(FVector Start, FVector End, float Height, float Thickness)
{
	TArray<FVector> Vertices;
	FVector MainAxis = (End - Start);
	MainAxis.Normalize();
	FVector NormalAxis = FVector(- MainAxis.Y, MainAxis.X, MainAxis.Z);
	
	Vertices.Add(Start - NormalAxis * Thickness / 2); //0
	Vertices.Add(Start + NormalAxis * Thickness / 2); //1
	Vertices.Add(End + NormalAxis * Thickness / 2); //2
	Vertices.Add(End - NormalAxis * Thickness / 2); // 3      //PLAN 2D

	for(int i = 0; i < 4 ; i++)
	{
		FVector Vertex = Vertices[i];
		Vertex.Z = Start.Z + Height;
		Vertices.Add(Vertex);
	} // Ajout du Second plan en hauteur
	
	return Vertices;
}

TArray<FVector> AWall_P::CalculateCoordinatesForPlatforms(FVector Center, FVector GridSize, float Height,
	float Thickness)
{
	TArray<FVector> Vertices;
	FVector p1 = FVector(Center.X - GridSize.X / 2, Center.Y - GridSize.Y / 2, 0);
	FVector p2 = FVector(Center.X + GridSize.X / 2, Center.Y - GridSize.Y / 2, 0);
	FVector MainAxis = (p2 - p1);
	MainAxis.Normalize();
	FVector NormalAxis = FVector(- MainAxis.Y, MainAxis.X, MainAxis.Z);
	
	Vertices.Add(p1 - NormalAxis * Thickness / 2); //0
	Vertices.Add(p1 + NormalAxis * Thickness / 2); //1
	Vertices.Add(p2 + NormalAxis * Thickness / 2); //2
	Vertices.Add(p2 - NormalAxis * Thickness / 2); // 3      //PLAN 2D

	for(int i = 0; i < 4 ; i++)
	{
		FVector Vertex = Vertices[i];
		Vertex.Z = p1.Z + Height;
		Vertices.Add(Vertex);
	} // Ajout du Second plan en hauteur
	
	return Vertices;
}

void AWall_P::CalculateFace(TArray<FVector>& OutVertices, TArray<FVector>& OutNormals, TArray<FVector2D>& OutUVs,
                            TArray<FProcMeshTangent>& OutTangents, TArray<int32> &Triangles, FVector P0, FVector P1, FVector P2, FVector P3, FVector Normal, FVector Tangent,
                            int32 &VertexOffset)
{
	FProcMeshTangent Tan = FProcMeshTangent(Tangent, false);
	OutVertices.Add(P0);
	OutVertices.Add(P1);
	OutVertices.Add(P2);
	OutVertices.Add(P3);
	OutNormals.Add(Normal);
	OutNormals.Add(Normal);
	OutNormals.Add(Normal);
	OutNormals.Add(Normal);
	OutTangents.Add(Tan);
	OutTangents.Add(Tan);
	OutTangents.Add(Tan);
	OutTangents.Add(Tan);
	Triangles.Add(VertexOffset);
	Triangles.Add(VertexOffset + 1);
	Triangles.Add(VertexOffset + 2);
	Triangles.Add(VertexOffset);
	Triangles.Add(VertexOffset + 2);
	Triangles.Add(VertexOffset + 3);
	OutUVs.Add(FVector2d(0.0f, 1.0f));
	OutUVs.Add(FVector2d(1.0f, 1.0f));
	OutUVs.Add(FVector2d(1.0f, 0.0f));
	OutUVs.Add(FVector2d(0.0f, 0.0f));
	VertexOffset += 4;
}

TArray<FVector> AWall_P::CalculateNormals(FVector Start, FVector End)
{
	TArray<FVector> Normals;
	FVector MainAxis = (End - Start);
	MainAxis.Normalize();
	
	Normals.Add(FVector(0, -1, 0));  // Bas
	Normals.Add(FVector(0, 1, 0)); // Haut
	Normals.Add(FVector(0,- MainAxis.Y, 0)); //avant
	Normals.Add(FVector(MainAxis.X, 0, 0)); //droite
	Normals.Add(FVector(0,MainAxis.Y, 0)); //arrière
	Normals.Add(FVector(- MainAxis.X, 0, 0)); //gauche

	return Normals;
}

TArray<FVector> AWall_P::CalculateTangents(FVector Start, FVector End)
{
	TArray<FVector> Tangents;
	FVector MainAxis = (End - Start);
	MainAxis.Normalize();
	FVector SecondAxis (- MainAxis.Z, MainAxis.Y, MainAxis.X);
	Tangents.Add(FVector(MainAxis.X, 0, 0));
	Tangents.Add(FVector(0, 1, 0));
	Tangents.Add(FVector(0,1, 0));
	Tangents.Add(FVector(0, 1, 0));
	Tangents.Add(FVector(0,1,0 ));
	Tangents.Add(FVector(-MainAxis.X, 0, 0));

	return Tangents;
}


