#pragma once

#include "CoreMinimal.h"
#include "RogueLobby.h"
#include "RogueAuctionLobby.generated.h"

class ARogueAuctionUrn;

UCLASS()
class ROGUEBOYARD_API ARogueAuctionLobby : public ARogueLobby
{
	GENERATED_BODY()

public:
	ARogueAuctionLobby();
	virtual void Tick(float DeltaTime) override;
	virtual void EndRoom() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<ARogueAuctionUrn*> Urns;

protected:
	virtual void BeginPlay() override;
	
};
