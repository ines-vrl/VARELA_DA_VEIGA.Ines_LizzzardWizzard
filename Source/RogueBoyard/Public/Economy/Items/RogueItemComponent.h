#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RogueItemComponent.generated.h"


class URogueItem;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROGUEBOYARD_API URogueItemComponent : public UActorComponent
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemUsed);
	
public:
	URogueItemComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
						   FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly)
	URogueItem* CurrentItem;
	
	UFUNCTION(BlueprintCallable)
	void SetCurrentItem(URogueItem* Item);

	UFUNCTION(BlueprintCallable)
	void UseItem() const;

	UPROPERTY(BlueprintAssignable)
	FOnItemUsed OnItemUsedEvent;
	
protected:
	virtual void BeginPlay() override;
};
