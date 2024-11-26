#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RogueShop.generated.h"

class URogueItem;

UENUM()
enum class EItemEffect
{
	NotImplemented=0,
};

USTRUCT()
struct FShopItemData : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Price;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemEffect Effect;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UStaticMesh> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<URogueItem> ItemObject;
};

class UCapsuleComponent;

UCLASS()
class ROGUEBOYARD_API ARogueShop : public AActor
{
	GENERATED_BODY()

public:
	ARogueShop();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UCapsuleComponent> Collider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FShopItemData Item;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemBought);
	UPROPERTY(BlueprintAssignable)
	FOnItemBought OnItemBoughtEvent;

	UFUNCTION(BlueprintCallable)
	FShopItemData BuyItem();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
