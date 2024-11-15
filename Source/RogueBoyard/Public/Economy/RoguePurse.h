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
	DECLARE_MULTICAST_DELEGATE_OneParam(FOnPurseUpdateMoney, int);
	FOnPurseUpdateMoney OnUpdatedMoneyEvent;
	
	UFUNCTION(BlueprintCallable)
	void Earn(const int Money);
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	int Coins = 0;
	
	UFUNCTION(BlueprintCallable)
	void Spend(const int Price);
};
