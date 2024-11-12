#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Room/RogueRoom.h"
#include "Room/RogueRoomPawn.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UMaterialInterface*> Materials;
	
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

	void AddRoom(ARogueRoomPawn* Pawn, ARogueRoom* Manager);
	void AddRoomPawn(ARogueRoomPawn* Pawn);
	void AddRoomManager(ARogueRoom* Manager);

private:
	bool bIsFirstRoomLoaded = false;
	
	void InitPlayers();
	void InitCharacters();
	void InitFirstRoom();

	UFUNCTION()
	void OnCharacterDeath();

	UFUNCTION()
	void OnRoomLoaded();
};
