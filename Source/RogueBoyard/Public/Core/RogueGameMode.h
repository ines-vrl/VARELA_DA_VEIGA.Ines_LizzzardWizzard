#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RogueGameMode.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueGameMode : public AGameModeBase
{
	GENERATED_BODY()
	virtual void BeginPlay() override;

	void InitPlayers();
};
