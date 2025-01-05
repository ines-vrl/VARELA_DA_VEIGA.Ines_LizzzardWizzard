// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Editor/Blutility/Classes/EditorUtilityWidget.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "BlueprintValidator.generated.h"

// Structure pour stocker les résultats
	USTRUCT(BlueprintType)
struct FBlueprintValidationResult
	{
		GENERATED_BODY()
        
		UPROPERTY(BlueprintReadOnly)
		FString BlueprintName;
        
		UPROPERTY(BlueprintReadOnly)
		TArray<FString> UnconnectedNodeNames;

		UPROPERTY(BlueprintReadOnly)
		TArray<FGuid> UnconnectedNodeGuids;  // Pour identifier les nœuds de façon unique
    
		UPROPERTY(BlueprintReadOnly)
		TSoftObjectPtr<UBlueprint> BlueprintPtr;  // Référence au Blueprint
	};

UCLASS(BlueprintType)
class ROGUEBOYARD_API UBlueprintValidator : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
    // Fonction principale pour analyser tous les blueprints
    UFUNCTION(BlueprintCallable, Category = "Blueprint Validation")
    void FindUnconnectedNodes();

    // Liste des résultats accessible depuis le widget
    UPROPERTY(BlueprintReadOnly)
    TArray<FBlueprintValidationResult> ValidationResults;

	UFUNCTION(BlueprintCallable, Category = "Blueprint Validation")
	void JumpToNode(const FString& BlueprintName, const FString& GraphName, const FString& NodeName);

	// Fonction utilitaire pour ouvrir un Blueprint dans l'éditeur
	UFUNCTION(BlueprintCallable, Category = "Blueprint Validation")
	void OpenBlueprint(const FString& BlueprintName);

	UFUNCTION(BlueprintCallable, Category = "Blueprint Validation")
	const TArray<FBlueprintValidationResult>& GetValidationResults() const { return ValidationResults; }


private:
    // Analyse un blueprint spécifique
    void AnalyzeBlueprint(UBlueprint* Blueprint);
    
    // Vérifie si un node est connecté
    bool IsNodeConnected(UEdGraphNode* Node);

	// Fonction utilitaire pour trouver un pin spécifique
	UEdGraphPin* FindFirstPinInNode(UEdGraphNode* Node);
};