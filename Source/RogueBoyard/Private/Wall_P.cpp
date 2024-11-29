// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall_P.h"


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
	
	FMeshStruct Mesh;
	int32 VertexOffset = 0;

	TArray<FVector> InputVert = CalculateCoordinates(Start, End, Height, Thickness);
	FVector MainAxis = (End - Start);
	MainAxis.Z = 0;
	MainAxis.Normalize();
	FVector SecondaryAxis = FVector(-MainAxis.Y, MainAxis.X, MainAxis.Z);

	//TopFace //
	FVector Normal = FVector(0, 0, 1);
	FVector Tangent = FVector(1, 0, 0);
	CalculateFace(Mesh,InputVert[4], InputVert[5], InputVert[6], InputVert[7], Normal, Tangent, VertexOffset);

	//BottomFace
	Normal = FVector(0, 0, -1);
	Tangent = FVector(-1, 0, 0);
	CalculateFace(Mesh, InputVert[3], InputVert[2], InputVert[1], InputVert[0], Normal, Tangent, VertexOffset);

	//FrontFace
	Normal = MainAxis;
	Tangent = SecondaryAxis;
	CalculateFace(Mesh, InputVert[0], InputVert[1], InputVert[5], InputVert[4], Normal, Tangent, VertexOffset);

	//BackFace//
	Normal = -MainAxis;
	Tangent = -SecondaryAxis;
	CalculateFace(Mesh, InputVert[7], InputVert[6], InputVert[2], InputVert[3], Normal, Tangent, VertexOffset);

	//LeftFace
	Normal = -SecondaryAxis;
	Tangent = MainAxis;
	CalculateFace(Mesh, InputVert[7], InputVert[3], InputVert[0], InputVert[4], Normal, Tangent, VertexOffset);

	//RightFace//
	Normal = SecondaryAxis;
	Tangent = -MainAxis;
	CalculateFace(Mesh, InputVert[2], InputVert[6], InputVert[5], InputVert[1], Normal, Tangent, VertexOffset);

	ProceduralMesh->CreateMeshSection(0, Mesh.Vertices, Mesh.Triangles, Mesh.Normals, Mesh.UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
}

void AWall_P::ProceduralPlatform(TArray<FTileBrush> Tiles, float GridSize, float Height, float SurfaceSize)
{
	ProceduralMesh->ClearAllMeshSections();
	
	FMeshStruct Mesh;
	int32 VertexOffset = 0;
	for (FTileBrush Tile : Tiles)
	{
		CalculateFace(Mesh, FVector(Tile.TileCoords.X - GridSize /2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z + Height),
			FVector(Tile.TileCoords.X + GridSize /2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z + Height),
			FVector(Tile.TileCoords.X + GridSize /2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z + Height),
			FVector(Tile.TileCoords.X - GridSize /2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z + Height),
			FVector(0, 0, 1),
			FVector(1, 0, 0),
			VertexOffset);
	}
	for (FTileBrush Tile : Tiles)
	{
		CalculateFace(Mesh, FVector(Tile.TileCoords.X - GridSize /2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z),
			FVector(Tile.TileCoords.X + GridSize /2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z),
			FVector(Tile.TileCoords.X + GridSize /2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z),
			FVector(Tile.TileCoords.X - GridSize /2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z),
			FVector(0, 0, -1),
			FVector(-1, 0, 0),
			VertexOffset);
	}
	//for (FTileBrush Tile : Tiles) // North
	//{
	//	CalculateFace(Mesh, FVector(Tile.TileCoords.X + GridSize /2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z),
	//	FVector(Tile.TileCoords.X + GridSize /2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z + Height),
	//	FVector(Tile.TileCoords.X - GridSize /2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z + Height),
	//	FVector(Tile.TileCoords.X - GridSize /2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z),
	//	FVector(0,1,0),
	//	FVector(1,0,0),
	//	VertexOffset);
	//}
	//for (FTileBrush Tile : Tiles) // South
	//{
	//	CalculateFace(Mesh, FVector(Tile.TileCoords.X - GridSize /2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z),
	//	FVector(Tile.TileCoords.X - GridSize /2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z + Height),
	//	FVector(Tile.TileCoords.X + GridSize /2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z + Height),
	//	FVector(Tile.TileCoords.X + GridSize /2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z),
	//	FVector(0,-1,0),
	//	FVector(-1,0,0),
	//	VertexOffset);
	//}
	/*for (FTileBrush Tile : Tiles) // West
	{
		CalculateFace(Mesh, FVector(Tile.TileCoords.X - GridSize / 2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z),
		FVector(Tile.TileCoords.X - GridSize / 2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z + Height),
		FVector(Tile.TileCoords.X - GridSize / 2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z + Height),
		FVector(Tile.TileCoords.X - GridSize / 2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z),
		FVector(-1,0,0),
		FVector(0,-1,0),
		VertexOffset);
	}
	for (FTileBrush Tile : Tiles) // East
	{
		CalculateFace(Mesh, 		FVector(Tile.TileCoords.X - GridSize / 2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z),
		FVector(Tile.TileCoords.X - GridSize / 2, Tile.TileCoords.Y + GridSize / 2, Tile.TileCoords.Z + Height),
		FVector(Tile.TileCoords.X - GridSize / 2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z + Height),
		FVector(Tile.TileCoords.X - GridSize / 2, Tile.TileCoords.Y - GridSize / 2, Tile.TileCoords.Z),
		FVector(1,0,0),
		FVector(0,1,0),
		VertexOffset);
	}*/
	CalculateCoordinatesForPlatforms(Tiles, GridSize, Mesh, Height, VertexOffset, SurfaceSize);
	ProceduralMesh->CreateMeshSection(0, Mesh.Vertices, Mesh.Triangles, Mesh.Normals, Mesh.UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
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

void AWall_P::CalculateCoordinatesForPlatforms(TArray<FTileBrush> Tiles, float GridSize, FMeshStruct& Mesh, float Height,
	int32& VertexOffset, float SurfaceSize)
{
	TArray<TArray<FVector>> North;
	TArray<TArray<FVector>> South;
	TArray<TArray<FVector>> East;
	TArray<TArray<FVector>> West;
	North.Init(TArray<FVector>(), SurfaceSize);
	South.Init(TArray<FVector>(), SurfaceSize);
	East.Init(TArray<FVector>(), SurfaceSize);
	West.Init(TArray<FVector>(), SurfaceSize);
	for (FTileBrush Tile : Tiles)
	{
		
		if(Tile.bNorth)
		{
			North[FMathf::Abs(Tile.TileCoords.Y)].Add(Tile.TileCoords);
		}
		if(Tile.bSouth)
		{
			South[FMathf::Abs(Tile.TileCoords.Y)].Add(Tile.TileCoords);
		}
		if(Tile.bEast)
		{
			East[FMathf::Abs(Tile.TileCoords.X)].Add(Tile.TileCoords);
		}
		if(Tile.bWest)
		{
			West[FMathf::Abs(Tile.TileCoords.X)].Add(Tile.TileCoords);
		}
	}
	
	for (auto Vectors : North)
	{
		if(!Vectors.IsEmpty()) CalculateVerticesCoords(Vectors, Mesh, Height, GridSize, VertexOffset,true);
	}
	
	TArray<FVector> SouthVertices;
	for (auto Vectors : South)
	{
		if(!Vectors.IsEmpty())CalculateVerticesCoords(Vectors, Mesh, Height, GridSize, VertexOffset,true, true);
	}
	
	TArray<FVector> EastVertices;
	for (auto Vectors : East)
	{
		if(!Vectors.IsEmpty())CalculateVerticesCoords(Vectors, Mesh, Height, GridSize, VertexOffset,false, false, true);
	}
	
	TArray<FVector> WestVertices;
	for (auto Vectors : West)
	{
		if(!Vectors.IsEmpty())CalculateVerticesCoords(Vectors, Mesh, Height, GridSize, VertexOffset,false, false, true , true);
	}
	
}

void AWall_P::CalculateVerticesCoords(TArray<FVector> Coordinates, FMeshStruct& Mesh, float Height, float GridSize,
		int32 &VertexOffset, bool bNorth, bool bSouth, bool bWest, bool bEast)
{
	TArray<FVector> Vertices;
	FVector min,max;
	if(bNorth)
	{
		min = Coordinates[0];
		max = Coordinates[0];
		for(int i = 0; i < Coordinates.Num(); i++)
		{
			if(Coordinates[i].X >= max.X + GridSize) max = Coordinates[i];
			if(Coordinates[i].X <= min.X - GridSize) min = Coordinates[i];
		}
		if(bSouth)
		{
			CalculateFace(Mesh, FVector(min.X - GridSize / 2, min.Y - GridSize / 2, min.Z),
			FVector(min.X - GridSize / 2, min.Y - GridSize / 2, min.Z + Height),
			FVector(max.X + GridSize / 2, max.Y - GridSize / 2, max.Z + Height),
			FVector(max.X + GridSize / 2, max.Y - GridSize / 2, max.Z),
			FVector(0,-1,0),
			FVector(-1,0,0),
			VertexOffset); // BON
		}
		else
		{
			CalculateFace(Mesh, FVector(max.X + GridSize / 2, max.Y + GridSize / 2, max.Z),
			FVector(max.X + GridSize / 2, max.Y + GridSize / 2, max.Z + Height),
			FVector(min.X - GridSize / 2, min.Y + GridSize / 2, min.Z + Height),
			FVector(min.X - GridSize / 2, min.Y + GridSize / 2, min.Z),
			FVector(0,1,0),
			FVector(1,0,0),
			VertexOffset); // BON
		}
			
	}
	if(bWest)
	{
			min = Coordinates[0];
			max = Coordinates[0];
			for(int i = 0; i < Coordinates.Num(); i++)
			{
				if(Coordinates[i].Y >= max.Y + GridSize) max = Coordinates[i];
				if(Coordinates[i].Y <= min.Y - GridSize) min = Coordinates[i];
			}
			if(bEast)
			{
				CalculateFace(Mesh, FVector(max.X - GridSize / 2, max.Y + GridSize / 2, max.Z),
				FVector(max.X - GridSize / 2, max.Y + GridSize / 2, max.Z + Height),
				FVector(min.X - GridSize / 2, min.Y - GridSize / 2, min.Z + Height),
				FVector(min.X - GridSize / 2, min.Y - GridSize / 2, min.Z),
				FVector(-1,0,0),
				FVector(0,-1,0),
				VertexOffset);
			}
			else
			{

				CalculateFace(Mesh, FVector(min.X + GridSize / 2, min.Y - GridSize / 2, min.Z),
				FVector(min.X + GridSize / 2, min.Y - GridSize / 2, min.Z + Height),
				FVector(max.X + GridSize / 2, max.Y + GridSize / 2, max.Z + Height),
				FVector(max.X + GridSize / 2, max.Y + GridSize / 2, max.Z),
				FVector(1,0,0),
				FVector(0,1,0),
				VertexOffset);
			}
	}
}

void AWall_P::CalculateFace(FMeshStruct& Mesh, FVector P0, FVector P1, FVector P2, FVector P3, FVector Normal, FVector Tangent,
                            int32 &VertexOffset)
{
	FProcMeshTangent Tan = FProcMeshTangent(Tangent, false);
	Mesh.Vertices.Add(P0);
	Mesh.Vertices.Add(P1);
	Mesh.Vertices.Add(P2);
	Mesh.Vertices.Add(P3);
	Mesh.Normals.Add(Normal);
	Mesh.Normals.Add(Normal);
	Mesh.Normals.Add(Normal);
	Mesh.Normals.Add(Normal);
	Mesh.Tangents.Add(Tan);
	Mesh.Tangents.Add(Tan);
	Mesh.Tangents.Add(Tan);
	Mesh.Tangents.Add(Tan);
	Mesh.Triangles.Add(VertexOffset);
	Mesh.Triangles.Add(VertexOffset + 1);
	Mesh.Triangles.Add(VertexOffset + 2);
	Mesh.Triangles.Add(VertexOffset);
	Mesh.Triangles.Add(VertexOffset + 2);
	Mesh.Triangles.Add(VertexOffset + 3);
	Mesh.UVs.Add(FVector2d(0.0f, 1.0f));
	Mesh.UVs.Add(FVector2d(1.0f, 1.0f));
	Mesh.UVs.Add(FVector2d(1.0f, 0.0f));
	Mesh.UVs.Add(FVector2d(0.0f, 0.0f));
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


