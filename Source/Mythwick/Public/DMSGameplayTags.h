// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PropertyEditorCopyPaste.h"

/**
 * DMSGameplayTags
 *
 * Singleton containing native Gameplay Tags 
 */

struct FDMSGameplayTags
{
public:
	static const FDMSGameplayTags& Get() {return GameplayTags;}
	static void InitializeNativeGameplayTags();

	/* Primary Attributes */
//Start*************************************************************************************************
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Resilience;
	FGameplayTag Attributes_Primary_Constitution;
	FGameplayTag Attributes_Primary_Dexterity;
	FGameplayTag Attributes_Primary_Charisma;
	FGameplayTag Attributes_Primary_Vigor;
//End*************************************************************************************************
	
	/* Secondary Attributes */
//Start*************************************************************************************************
	//Strength Association
	FGameplayTag Attributes_Secondary_MeleeArmorPen;
	FGameplayTag Attributes_Secondary_MeleeCritDam;
	FGameplayTag Attributes_Secondary_MeleeCritChance;
	
	//Intelligence Association
	FGameplayTag Attributes_Secondary_SpellArmorPen;
	FGameplayTag Attributes_Secondary_SpellCritDam;
	FGameplayTag Attributes_Secondary_SpellCritChance;
	FGameplayTag Attributes_Secondary_SpellSlotRegen;
	
	//Resilience Association
	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CritResistance;
	
	//Constitution Association
	FGameplayTag Attributes_Secondary_HealthRegen;
	FGameplayTag Attributes_Secondary_StaminaRegen;

	//Dexterity Association
	FGameplayTag Attributes_Secondary_RangedArmorPen;
	FGameplayTag Attributes_Secondary_RangedCritDam;
	FGameplayTag Attributes_Secondary_RangedCritChance;
	FGameplayTag Attributes_Secondary_Speed;
	FGameplayTag Attributes_Secondary_Stealth;
	FGameplayTag Attributes_Secondary_SleightOfHand;

	//Charisma Association
	FGameplayTag Attributes_Secondary_Persuasion;
	FGameplayTag Attributes_Secondary_Intimidation;
	FGameplayTag Attributes_Secondary_Deception;
//End*************************************************************************************************
	
	/* Vital Attributes */
//Start*************************************************************************************************
	FGameplayTag Attributes_Vital_Health;
	FGameplayTag Attributes_Vital_MaxHealth;
	FGameplayTag Attributes_Vital_Mana;
	FGameplayTag Attributes_Vital_MaxMana;
	FGameplayTag Attributes_Vital_SpellSlots;
	FGameplayTag Attributes_Vital_MaxSpellSlots;
	FGameplayTag Attributes_Vital_Stamina;
	FGameplayTag Attributes_Vital_MaxStamina;
	//Adding auxilary attributes to represent held breath, adrenaline, hold onto ledge, etc.
	FGameplayTag Attributes_Vital_AuxAttribute1;
	FGameplayTag Attributes_Vital_MaxAuxAttribute1;
	FGameplayTag Attributes_Vital_AuxAttribute2;
	FGameplayTag Attributes_Vital_MaxAuxAttribute2;
	FGameplayTag Attributes_Vital_AuxAttribute3;
	FGameplayTag Attributes_Vital_MaxAuxAttribute3;
//End*************************************************************************************************

	/* InputTags */		//(GAS 100)
//Start*************************************************************************************************
	FGameplayTag InputTag_LeftMouseButton;
	FGameplayTag InputTag_RightMouseButton;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;
//End*************************************************************************************************
	
private:
	static FDMSGameplayTags GameplayTags;
	
};