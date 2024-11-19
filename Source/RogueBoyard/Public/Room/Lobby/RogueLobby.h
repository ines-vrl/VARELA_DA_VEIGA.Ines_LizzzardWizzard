#pragma once

#include "CoreMinimal.h"
#include "Room/RogueRoom.h"
#include "RogueLobby.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueLobby : public ARogueRoom
{
	GENERATED_BODY()
	
public:
	ARogueLobby();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	int ChosenPlayer = -1;

protected:
	virtual void BeginPlay() override;
	
	/**
	 * Super à mettre à la fin;
	 */
	virtual void EndRoom() override;
};
