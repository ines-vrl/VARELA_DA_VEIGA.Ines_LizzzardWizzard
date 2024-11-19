// Fill out your copyright notice in the Description page of Project Settings.


#include "Traps/WallBlade.h"

#include "LevelInstance/LevelInstanceTypes.h"


// Sets default values
AWallBlade::AWallBlade()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWallBlade::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWallBlade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveOnOneAxis(DeltaTime);
}

void AWallBlade::MoveOnOneAxis(const float& DeltaTime)
{
	FVector RightVector = GetActorRightVector();  // Récupère la direction "droite" dans le monde (localisé à l'acteur)

	// 2. On applique un mouvement basé sur MoveJoystick (valeur entre -1 et 1)
	FVector Direction = RightVector * MoveJoystick;

	// 3. Calculer la distance parcourue pendant cette frame
	MovementDelta = Direction * MovementSpeed * DeltaTime;

	// 4. Nouvelle position de l'acteur en fonction du mouvement calculé
	NewLocation = GetActorLocation() + MovementDelta;

	// 5. Calculer la distance totale parcourue depuis le début
	// On utilise le vecteur de départ et on calcule la distance par rapport à la position initiale
	float DistanceFromStart = FVector::Dist(StartPosition, NewLocation);

	// 6. Si la distance parcourue dépasse la distance maximale, on limite la position
	if (DistanceFromStart <= MaxDistance)
	{
		// Si la distance est inférieure à MaxDistance, on déplace l'acteur normalement
		SetActorLocation(NewLocation);
	}
	else
	{
		// Si la distance dépasse MaxDistance, on calcule la position limite
		// On va restreindre la position à la limite de la MaxDistance
		FVector ClampedLocation = StartPosition + RightVector * MaxDistance * FMath::Sign(MoveJoystick);
		SetActorLocation(ClampedLocation); // Appliquer la position limitée
	}

	// 7. Mettre à jour la distance parcourue
	DistanceTravelled = FVector::Dist(StartPosition, GetActorLocation());
}