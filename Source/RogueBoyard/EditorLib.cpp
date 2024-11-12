// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorLib.h"
#include "LevelEditor.h"
#include "Components/BoxComponent.h"

void AEditorLib::StartListening()
{
	FLevelEditorModule* levelEditorModule = FModuleManager::GetModulePtr<FLevelEditorModule>("LevelEditor");
	if(levelEditorModule != nullptr)
	levelEditorModule->OnActorSelectionChanged().AddUObject(this, &AEditorLib::HandleActorSelectionChanged);
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get LevelEditor module."));
	}
}

void AEditorLib::StopListening()
{
	if(FLevelEditorModule* LevelEditorModule = FModuleManager::GetModulePtr<FLevelEditorModule>("LevelEditor"))
		LevelEditorModule->OnActorSelectionChanged().RemoveAll(this);
}

void AEditorLib::ProceduralWall(FVector Start, FVector End)
{
	FVector WallCenter = (Start + End) * 0.5;
	FVector WallExtents = (End - Start).GetAbs() * 0.5; //Distance entre centre et la bordure
}

void AEditorLib::SavePoint(FVector Point)
{

	if(Points.Contains(Point))
	{
		Points.Remove(Point);
		return;
	}
	Points.Add(Point);
}

FVector AEditorLib::FindPoint(FVector End)
{
	for (auto Point : Points)
	{
		//UE_LOG(LogTemp, Log, TEXT("CurrentDistance: %f"), (Point - End).Length());
		if((Point - End).Length() < SnapDistance) return Point;
	}
	return End;
}

void AEditorLib::HandleActorSelectionChanged(const TArray<UObject*>& NewSelection, bool bForceRefresh)
{
	for (UObject* SelectedObject : NewSelection)
	{
		if (AActor* SelectedActor = Cast<AActor>(SelectedObject))
		{
			//wUE_LOG(LogTemp, Log, TEXT("Selected Actor: %s"), *SelectedActor->GetName());
			OnActorSelectionChanged.Broadcast(SelectedActor);
		}
	}
}

