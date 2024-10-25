#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Room/RogueRoom.h"
#include "RogueGameMode.generated.h"

class ARogueCharacter;
class ARogueRoomPawn;

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

	void InitPlayers();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartBattleRoom();
	void StartBattleRoom_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EndBattleRoom();
	void EndBattleRoom_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartLobbyRoom();
	void StartLobbyRoom_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EndLobbyRoom();
	void EndLobbyRoom_Implementation();
};
