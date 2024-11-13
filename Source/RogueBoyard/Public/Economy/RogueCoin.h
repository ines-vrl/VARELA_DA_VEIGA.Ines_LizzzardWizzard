#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RogueCoin.generated.h"

class USphereComponent;

UCLASS()
class ROGUEBOYARD_API ARogueCoin : public AActor {
	GENERATED_BODY()
public:
	ARogueCoin();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USphereComponent* Collider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* CoinMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Value = 1;

protected:
	virtual void BeginPlay() override;

};
