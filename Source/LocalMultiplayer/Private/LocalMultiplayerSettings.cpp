// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalMultiplayerSettings.h"
#include "InputMappingContext.h"


bool FLocalMultiplayerProfileData::ContainsKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const
{
	TArray<FEnhancedActionKeyMapping> arrayPasOP = GetIMCFromType(MappingType)->GetMappings();
	for (auto elementPasOP : arrayPasOP)
	{
		if(elementPasOP.Key == Key) return true;
	}
	return false;
}

UInputMappingContext* FLocalMultiplayerProfileData::GetIMCFromType(ELocalMultiplayerInputMappingType MappingType) const
{
	switch(MappingType)
	{
		case ELocalMultiplayerInputMappingType::InGame:
			return IMCInGame;
		case ELocalMultiplayerInputMappingType::Menu:
			return IMCMenu;
	}
	
	return nullptr;
}

int ULocalMultiplayerSettings::GetNbKeyboardProfiles() const
{
	return KeyBoardProfilesData.Num();
}

int ULocalMultiplayerSettings::FindKeyboardProfileFromKey(const FKey& Key,
															ELocalMultiplayerInputMappingType MappingType) const
{
	for (int i = 0; i < GetNbKeyboardProfiles(); i++)
	{
		if(KeyBoardProfilesData[i].ContainsKey(Key, MappingType)) return i;
	}
	return -1;
}
