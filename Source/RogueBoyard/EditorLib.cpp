// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorLib.h"
#include "LevelEditor.h"

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

void AEditorLib::HandleActorSelectionChanged(const TArray<UObject*>& NewSelection, bool bForceRefresh)
{
	for (UObject* SelectedObject : NewSelection)
	{
		if (AActor* SelectedActor = Cast<AActor>(SelectedObject))
		{
			UE_LOG(LogTemp, Log, TEXT("Selected Actor: %s"), *SelectedActor->GetName());
			OnActorSelectionChanged.Broadcast(SelectedActor);
		}
	}
}
