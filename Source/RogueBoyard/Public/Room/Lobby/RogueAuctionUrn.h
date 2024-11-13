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

	UFUNCTION(BlueprintCallable)
	int GetBids() const;

	UFUNCTION(BlueprintCallable)
	void AddBid();
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	int Bids;
};
