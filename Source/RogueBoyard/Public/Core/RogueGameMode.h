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

public:
	virtual void BeginPlay() override;

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
	virtual void StartBattleRoom_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EndBattleRoom();
	virtual void EndBattleRoom_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartLobbyRoom();
	virtual void StartLobbyRoom_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EndLobbyRoom();
	virtual void EndLobbyRoom_Implementation();

	void AddRoom(ARogueRoomPawn* Pawn, ARogueRoom* Manager);
	void AddRoomPawn(ARogueRoomPawn* Pawn);
	void AddRoomManager(ARogueRoom* Manager);

private:
	bool bIsFirstRoomLoaded = false;
	
	virtual void InitPlayers();
	virtual void InitCharacters();
	virtual void InitFirstRoom();

	UFUNCTION()
	void OnCharacterDeath();

	UFUNCTION()
	void OnRoomLoaded();
};
