#pragma once

#include "CoreMinimal.h"
#include "RogueLobby.h"
#include "RogueGrimoireLobby.generated.h"

class ARogueGrimoire;

UCLASS()
class ROGUEBOYARD_API ARogueGrimoireLobby : public ARogueLobby
{
	GENERATED_BODY()

public:
	ARogueGrimoireLobby();
	virtual void Tick(float DeltaTime) override;

	virtual void EndRoom() override;

	UPROPERTY(EditAnywhere)
	USceneComponent* GrimoireSpawnPoint;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	ARogueGrimoire* Grimoire;
};
