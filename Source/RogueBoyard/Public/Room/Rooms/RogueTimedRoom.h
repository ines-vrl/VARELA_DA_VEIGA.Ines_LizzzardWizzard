#pragma once

#include "CoreMinimal.h"
#include "Room/RogueRoom.h"
#include "RogueTimedRoom.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueTimedRoom : public ARogueRoom
{
	GENERATED_BODY()

public:
	ARogueTimedRoom();
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadOnly)
	float ElapsedTime = 0;

protected:
	virtual void BeginPlay() override;

private:
	/**
	 * Durée en secondes de la salle
	 */
	UPROPERTY(EditAnywhere)
	float Time = 90.0f;

	bool bHasBegun = false;
	
	virtual void BeginRoom() override;
};
