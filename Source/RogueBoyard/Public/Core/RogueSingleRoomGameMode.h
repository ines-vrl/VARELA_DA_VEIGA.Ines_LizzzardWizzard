#pragma once

#include "CoreMinimal.h"
#include "RogueGameMode.h"
#include "RogueSingleRoomGameMode.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueSingleRoomGameMode : public ARogueGameMode
{
	GENERATED_BODY()
	virtual void BeginPlay() override;

	virtual void InitFirstRoom() override;
};
