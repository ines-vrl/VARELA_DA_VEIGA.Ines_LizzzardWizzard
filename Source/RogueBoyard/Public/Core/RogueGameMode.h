#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Room/RogueRoom.h"
#include "RogueGameMode.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueGameMode : public AGameModeBase
{
	GENERATED_BODY()
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<ARogueRoom*> RoomManagers;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<ARogueRoomPawn*> RoomPawns;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<ARogueCharacter*> Characters;
};
