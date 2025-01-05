// Fill out your copyright notice in the Description page of Project Settings.


#include "EUW/BlueprintValidator.h"
#include "Kismet2/KismetEditorUtilities.h"


void UBlueprintValidator::FindUnconnectedNodes()
{
	// Récupère tous les blueprints
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetData;
	AssetRegistryModule.Get().GetAssetsByClass(UBlueprint::StaticClass()->GetFName(), AssetData);

	// Analyse chaque blueprint
	for (FAssetData Asset : AssetData)
	{
		UBlueprint* Blueprint = Cast<UBlueprint>(Asset.GetAsset());
		if (Blueprint)
		{
			AnalyzeBlueprint(Blueprint);
		}
	}
}

void UBlueprintValidator::AnalyzeBlueprint(UBlueprint* Blueprint)
{
	if (!Blueprint) return;

	FBlueprintValidationResult Result;
	Result.BlueprintName = Blueprint->GetName();
	Result.BlueprintPtr = Blueprint;
    
	// Parcourir tous les graphes du blueprint
	for (UEdGraph* Graph : Blueprint->UbergraphPages)
	{
		if (!Graph) continue;
        
		// Vérifier chaque node du graphe
		for (UEdGraphNode* Node : Graph->Nodes)
		{
			if (!Node) continue;
            
			if (!IsNodeConnected(Node))
			{
				Result.UnconnectedNodeNames.Add(FString::Printf(TEXT("%s (Graph: %s)"), 
					*Node->GetNodeTitle(ENodeTitleType::ListView).ToString(),
					*Graph->GetName()));
			}
		}
	}
	// Ajouter le résultat seulement si des nodes non connectés ont été trouvés
	if (Result.UnconnectedNodeNames.Num() > 0)
	{
		ValidationResults.Add(Result);
	}
}

bool UBlueprintValidator::IsNodeConnected(UEdGraphNode* Node)
{
	if (!Node) return true;

	// Un node est connecté si :
	// - Il a au moins une connexion entrante
	// - Il a au moins une connexion sortante
	// - C'est un node d'exécution (Event, etc.)
	bool bHasInputConnections = false;
	bool bHasOutputConnections = false;

	// Vérifier les pins d'entrée
	for (UEdGraphPin* Pin : Node->Pins)
	{
		if (Pin->Direction == EGPD_Input && Pin->LinkedTo.Num() > 0)
		{
			bHasInputConnections = true;
			break;
		}
	}

	// Vérifier les pins de sortie
	for (UEdGraphPin* Pin : Node->Pins)
	{
		if (Pin->Direction == EGPD_Output && Pin->LinkedTo.Num() > 0)
		{
			bHasOutputConnections = true;
			break;
		}
	}

	return bHasInputConnections || bHasOutputConnections;
}

void UBlueprintValidator::JumpToNode(const FString& BlueprintName, const FString& GraphName, const FString& NodeName)
{
	// Trouver le résultat correspondant
	for (const FBlueprintValidationResult& Result : ValidationResults)
	{
		if (Result.BlueprintName == BlueprintName)
		{
			if (UBlueprint* Blueprint = Result.BlueprintPtr.Get())
			{
				// D'abord, mettre le focus sur le Blueprint
				FKismetEditorUtilities::BringKismetToFocusAttentionOnObject(Blueprint);
                
				// Trouver le bon graphe et le bon nœud
				for (UEdGraph* Graph : Blueprint->UbergraphPages)
				{
					if (Graph && Graph->GetName() == GraphName)
					{
						for (UEdGraphNode* Node : Graph->Nodes)
						{
							if (Node && Node->GetNodeTitle(ENodeTitleType::ListView).ToString() == NodeName)
							{
								// Trouver un pin sur le nœud
								if (UEdGraphPin* Pin = FindFirstPinInNode(Node))
								{
									// Mettre le focus sur le pin
									FKismetEditorUtilities::BringKismetToFocusAttentionOnPin(Pin);
								}
								return;
							}
						}
					}
				}
			}
			break;
		}
	}
}

void UBlueprintValidator::OpenBlueprint(const FString& BlueprintName)
{
	for (const FBlueprintValidationResult& Result : ValidationResults)
	{
		if (Result.BlueprintName == BlueprintName)
		{
			if (UBlueprint* Blueprint = Result.BlueprintPtr.Get())
			{
				FKismetEditorUtilities::BringKismetToFocusAttentionOnObject(Blueprint);
			}
			break;
		}
	}
}

UEdGraphPin* UBlueprintValidator::FindFirstPinInNode(UEdGraphNode* Node)
{
	if (!Node || Node->Pins.Num() == 0)
		return nullptr;
    
	// Retourner le premier pin disponible
	return Node->Pins[0];
}


