#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RoguePurse.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROGUEBOYARD_API URoguePurse : public UActorComponent
{
	GENERATED_BODY()

public:
	URoguePurse();

protected:
	virtual void BeginPlay() override;

private:
	int Coins = 0;
	
	UFUNCTION(BlueprintCallable)
	void Spend(const int Price);

	UFUNCTION(BlueprintCallable)
	void Earn(const int Money);
};
