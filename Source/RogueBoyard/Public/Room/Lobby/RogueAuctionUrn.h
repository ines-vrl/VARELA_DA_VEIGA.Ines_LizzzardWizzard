#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RogueAuctionUrn.generated.h"

class UBoxComponent;

UCLASS()
class ROGUEBOYARD_API ARogueAuctionUrn : public AActor
{
	GENERATED_BODY()

public:
	ARogueAuctionUrn();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UBoxComponent* Collider;

	int GetBids() const;

	void AddBid();
	
protected:
	virtual void BeginPlay() override;

private:
	int Bids;
};
