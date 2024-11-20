#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RogueItem.generated.h"

UCLASS(Blueprintable)
class ROGUEBOYARD_API URogueItem : public UObject
{
	GENERATED_BODY()
public:
	virtual void Use(AActor* Character);
};
