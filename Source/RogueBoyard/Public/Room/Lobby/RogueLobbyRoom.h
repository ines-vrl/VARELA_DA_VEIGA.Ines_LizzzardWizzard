#pragma once

#include "CoreMinimal.h"
#include "Room/RogueRoom.h"
#include "RogueLobbyRoom.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueLobbyRoom : public ARogueRoom
{
	GENERATED_BODY()

public:
	ARogueLobbyRoom();
	virtual void Tick(float DeltaTime) override;

private:
	
};
