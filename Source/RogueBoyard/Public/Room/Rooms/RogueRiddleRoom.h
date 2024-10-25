#pragma once

#include "CoreMinimal.h"
#include "Room/RogueRoom.h"
#include "RogueRiddleRoom.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueRiddleRoom : public ARogueRoom
{
	GENERATED_BODY()

public:
	ARogueRiddleRoom();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	int ThingsToValidate = 0;
};
