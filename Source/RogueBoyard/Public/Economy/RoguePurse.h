#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RoguePurse.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROGUEBOYARD_API URoguePurse : public UActorComponent
{
	GENERATED_BODY()

public:
	URoguePurse();

	UFUNCTION(BlueprintCallable)
	void Spend(const int Price);

	UFUNCTION(BlueprintCallable)
	void Earn(const int Money);
	
protected:
	virtual void BeginPlay() override;

private:
	int Coins = 0;
};
