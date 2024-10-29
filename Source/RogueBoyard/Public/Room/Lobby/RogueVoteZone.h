#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "RogueVoteZone.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerEnterZone);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllPlayersLeaveZone);

UCLASS()
class ROGUEBOYARD_API ARogueVoteZone : public AActor
{
	GENERATED_BODY()

public:
	ARogueVoteZone();
	virtual void OnConstruction(const FTransform& Transform) override;
	int GetVoteResults(int LastMjIndex);

	UPROPERTY()
	TArray<UBoxComponent*> VoteZones;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBoxComponent* P1VoteZone;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBoxComponent* P2VoteZone;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBoxComponent* P3VoteZone;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBoxComponent* P4VoteZone;

	UPROPERTY(BlueprintCallable)
	FOnPlayerEnterZone OnPlayerEnterZoneEvent;
	
	UPROPERTY(BlueprintCallable)
	FOnAllPlayersLeaveZone OnAllPlayersLeaveZoneEvent;

private:
	UPROPERTY(EditAnywhere)
	float ZoneSize;
	
	UPROPERTY(EditAnywhere)
	float ZoneHeight;

	UPROPERTY(EditAnywhere)
	bool bCanMjGetVoted;

	/**
	 * If false the last mjs vote chooses
	 */
	UPROPERTY(EditAnywhere)
	bool bIsEqualityRandom;
};
