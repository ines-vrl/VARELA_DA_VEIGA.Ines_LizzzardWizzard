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
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float ElapsedTime = 0;

protected:
	virtual void BeginPlay() override;
	virtual void EndRoom() override;
	
};
