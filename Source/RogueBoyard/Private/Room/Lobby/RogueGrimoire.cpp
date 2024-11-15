#include "Room/Lobby/RogueGrimoire.h"

#include "Characters/RogueCharacter.h"

#define PI 0.3141592f

ARogueGrimoire::ARogueGrimoire()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARogueGrimoire::BeginPlay()
{
	Super::BeginPlay();
}

void ARogueGrimoire::SwitchOwner(ARogueCharacter* NewOwner)
{
	CurrentOwner = NewOwner;
	OnGrimoireChangedOwnerEvent.Broadcast();
}

void ARogueGrimoire::ComputeConstants()
{
	K1 = Zeta / (PI * F);
	K2 = 1.0f/ (2*PI*F)* (2*PI*F);
	K3 = R*Zeta / (2*PI*F);	
}

void ARogueGrimoire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(CurrentOwner)
	{
		ComputeConstants();
		const FVector Input = CurrentOwner->GetActorLocation();
		const FVector InputVelocity = (Input - LastInputPos)/DeltaTime;
		LastInputPos = Input;

		FVector NewPosition = GetActorLocation();
		NewPosition += DeltaTime * Velocity;
		Velocity += DeltaTime*(Input + K3 * InputVelocity - NewPosition - K1*Velocity)/ K2;
		SetActorLocation(NewPosition);
	}
}

ARogueCharacter* ARogueGrimoire::GetCurrentOwner() const
{
	return CurrentOwner;
}

