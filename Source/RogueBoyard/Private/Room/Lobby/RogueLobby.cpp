#include "Room/Lobby/RogueLobby.h"

#include "Characters/RogueCharacter.h"
#include "Characters/RogueCharacterStateID.h"
#include "Characters/RogueCharacterStateMachine.h"
#include "Core/RogueGameMode.h"

ARogueLobby::ARogueLobby()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARogueLobby::BeginPlay()
{
	Super::BeginPlay();
}

void ARogueLobby::EndRoom()
{
	Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode())->EndLobbyRoom();
	if(ARogueGameMode* GameMode =  Cast<ARogueGameMode>(GetWorld()->GetAuthGameMode()))
	{
		for (ARogueCharacter* Character : GameMode->Characters)
		{
			Character->StateMachine->ChangeState(ERogueCharacterStateID::Waiting);
		}
	}
}

void ARogueLobby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

