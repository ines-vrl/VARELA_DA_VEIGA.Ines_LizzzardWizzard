#pragma once

#include "CoreMinimal.h"
#include "RogueLobby.h"
#include "RogueRandomLobby.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueRandomLobby : public ARogueLobby
{
	GENERATED_BODY()

public:
	ARogueRandomLobby();
	virtual void Tick(float DeltaTime) override;
	virtual void EndRoom() override;

protected:
	virtual void BeginPlay() override;

	
};
