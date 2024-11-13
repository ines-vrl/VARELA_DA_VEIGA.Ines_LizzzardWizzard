#include "Economy/RoguePurse.h"


URoguePurse::URoguePurse()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void URoguePurse::BeginPlay()
{
	Super::BeginPlay();
}


void URoguePurse::Spend(const int Price)
{
	Coins -= Price;
}

void URoguePurse::Earn(const int Money)
{
	Coins += Money;
}

