#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RogueShop.generated.h"

UENUM()
enum class EItemEffect
{
	NotImplemented=0,
};

USTRUCT()
struct FShopItemData : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	FName Name;
	UPROPERTY(EditAnywhere)
	int Price;
	UPROPERTY(EditAnywhere)
	EItemEffect Effect;
};

class UCapsuleComponent;

UCLASS()
class ROGUEBOYARD_API ARogueShop : public AActor
{
	GENERATED_BODY()

public:
	ARogueShop();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UCapsuleComponent> Collider;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
	
};
