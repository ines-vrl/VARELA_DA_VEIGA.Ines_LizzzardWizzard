#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RogueGrimoire.generated.h"

class ARogueCharacter;

UCLASS()
class ROGUEBOYARD_API ARogueGrimoire : public AActor
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGrimoireChangedOwner);

public:
	ARogueGrimoire();
	virtual void Tick(float DeltaTime) override;
	ARogueCharacter* GetCurrentOwner();

	UPROPERTY(BlueprintAssignable)
	FOnGrimoireChangedOwner OnGrimoireChangedOwnerEvent;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION(BlueprintCallable)
	void SwitchOwner(ARogueCharacter* NewOwner);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ARogueCharacter* CurrentOwner;
};
