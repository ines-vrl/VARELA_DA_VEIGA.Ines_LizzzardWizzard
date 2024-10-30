#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RogueDoor.generated.h"

UCLASS()
class ROGUEBOYARD_API ARogueDoor : public AActor
{
	GENERATED_BODY()

public:
	ARogueDoor();
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintNativeEvent)
	void Open();
	void Open_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void Close();
	void Close_Implementation();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsOpen;
};
