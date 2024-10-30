#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "RogueVoteZone.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueVoteZone : public AActor
{
	GENERATED_BODY()

public:
	ARogueVoteZone();
	virtual void OnConstruction(const FTransform& Transform) override;
	int GetVoteResults(int LastMjIndex);
	

private:
	UPROPERTY(EditAnywhere)
	float ZoneSize;
	
	UPROPERTY(EditAnywhere)
	float ZoneHeight;
	
	UPROPERTY()
	TArray<UBoxComponent*> VoteZones;

	UPROPERTY(EditAnywhere)
	bool bCanMjGetVoted;

	/**
	 * If false the last mjs vote chooses
	 */
	UPROPERTY(EditAnywhere)
	bool bIsEqualityRandom;
};
