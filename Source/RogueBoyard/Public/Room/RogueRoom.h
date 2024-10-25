#pragma once

#include "CoreMinimal.h"
#include "RogueDoor.h"
#include "GameFramework/Actor.h"
#include "RogueRoom.generated.h"

class ARogueCharacter;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRoomEnter);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRoomExit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRoomBegin);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRoomEnd);

UCLASS()
class ROGUEBOYARD_API ARogueRoom : public AActor
{
	GENERATED_BODY()

public:
	ARogueRoom();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ACameraActor* RoomCamera = nullptr;
	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	virtual void RoomEnter();

	UFUNCTION(BlueprintCallable)
	void PlacePlayers(TArray<ACharacter*> Players);

	UFUNCTION(BlueprintCallable)
	void PlacePlayer(ARogueCharacter* Player, int Index);

	FOnRoomBegin OnRoomBeginEvent;
	FOnRoomEnd OnRoomEndEvent;
	FOnRoomEnter OnRoomEnterEvent;
	FOnRoomExit OnRoomExitEvent;

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	TArray<USceneComponent*> SpawnPoints;

	//TODO Mettre 4 Enter Doors, une par player, a chaque SpawnPoint;
	UPROPERTY(EditAnywhere)
	TObjectPtr<ARogueDoor> EnterDoor;

	UPROPERTY(EditAnywhere)
	TObjectPtr<ARogueDoor> ExitDoor;

private:
	UFUNCTION(BlueprintCallable)
	virtual void BeginRoom();
	
	UFUNCTION(BlueprintCallable)
	virtual void EndRoom();

	UFUNCTION(BlueprintCallable)
	virtual void RoomExit();
};