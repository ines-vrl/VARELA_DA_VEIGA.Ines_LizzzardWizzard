#pragma once

#include "CoreMinimal.h"
#include "RogueVoteZone.h"
#include "Room/RogueRoom.h"
#include "RogueLobbyRoom.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueLobbyRoom : public ARogueRoom
{
	GENERATED_BODY()

public:
	ARogueLobbyRoom();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	bool bShouldVoteTimerReset = false;
	
	UPROPERTY(EditAnywhere)
	ARogueVoteZone* VoteZone;
	
	UPROPERTY(EditAnywhere)
	float MaxLobbyTime = 120.0f;

	UPROPERTY(EditAnywhere)
	float VoteTimer = 10.0f;
	
	float ElapsedTime = 0.0f;

	UFUNCTION()
	void PlayerEnteredVoteZone();

	UFUNCTION()
	void AllPlayerExitVoteZone();

	bool bIsVoteActive = false;
};
