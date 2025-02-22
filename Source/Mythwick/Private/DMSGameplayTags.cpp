// Copyright Dark Mango Studios


#include "DMSGameplayTags.h"
#include "GameplayTagsManager.h"

FDMSGameplayTags FDMSGameplayTags::GameplayTags;

void FDMSGameplayTags::InitializeNativeGameplayTags()
{
	/*//Individually adding gameplay tags to each attribute. Example below: (GAS 88)
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Armor"),
		FString("Reduces damage taken and improves Block Chance."));*/

	
	/* Primary Attributes */
//Start*************************************************************************************************
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"),
		FString("Increases physical damage."));

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Intelligence"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Resilience"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Primary_Constitution = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Constitution"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Dexterity"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Primary_Charisma = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Charisma"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Vigor"),
		FString("Update DMSGameplayTags.cpp description."));
//End*************************************************************************************************

	/* Secondary Attributes */
//Start*************************************************************************************************
	//Strength Association
	GameplayTags.Attributes_Secondary_MeleeArmorPen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MeleeArmorPen"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_MeleeCritDam = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MeleeCritDam"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_MeleeCritChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MeleeCritChance"),
		FString("Update DMSGameplayTags.cpp description."));
	
	//Intelligence Association
	GameplayTags.Attributes_Secondary_SpellArmorPen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.SpellArmorPen"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_SpellCritDam = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.SpellCritDam"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_SpellCritChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.SpellCritChance"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_SpellSlotRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.SpellSlotRegen"),
		FString("Update DMSGameplayTags.cpp description."));

	//Resilience Association
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Armor"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.BlockChance"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_CritResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CritResistance"),
		FString("Update DMSGameplayTags.cpp description."));

	//Constitution Association
	GameplayTags.Attributes_Secondary_HealthRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.HealthRegen"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_StaminaRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.StaminaRegen"),
		FString("Update DMSGameplayTags.cpp description."));

	//Dexterity Association
	GameplayTags.Attributes_Secondary_RangedArmorPen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.RangedArmorPen"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_RangedCritDam = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.RangedCritDam"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_RangedCritChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.RangedCritChance"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_Speed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Speed"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_Stealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Stealth"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_SleightOfHand = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.SleightOfHand"),
		FString("Update DMSGameplayTags.cpp description."));

	//Charisma Association
	GameplayTags.Attributes_Secondary_Persuasion = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Persuasion"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_Intimidation = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Intimidation"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Secondary_Deception = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Deception"),
		FString("Update DMSGameplayTags.cpp description."));
//End*************************************************************************************************

	/* Vital Attributes */
//Start*************************************************************************************************
	GameplayTags.Attributes_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.Health"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxHealth"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.Mana"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxMana"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_SpellSlots = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.SpellSlots"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_MaxSpellSlots = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxSpellSlots"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_Stamina = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.Stamina"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_MaxStamina = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxStamina"),
		FString("Update DMSGameplayTags.cpp description."));

	//Adding auxilary attributes to represent held breath, adrenaline, hold onto ledge, etc.
	GameplayTags.Attributes_Vital_AuxAttribute1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.AuxAttribute1"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_MaxAuxAttribute1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxAuxAttribute1"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_AuxAttribute2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.AuxAttribute2"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_MaxAuxAttribute2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxAuxAttribute2"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_AuxAttribute3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.AuxAttribute3"),
		FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.Attributes_Vital_MaxAuxAttribute3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxAuxAttribute3"),
		FString("Update DMSGameplayTags.cpp description."));
//End*************************************************************************************************

	/* InputTags */		//(GAS 100)
//Start*************************************************************************************************
	GameplayTags.InputTag_LeftMouseButton = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("InputTag.LeftMouseButton"),
			FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.InputTag_RightMouseButton = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("InputTag.RightMouseButton"),
			FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("InputTag.1"),
			FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("InputTag.2"),
			FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("InputTag.3"),
			FString("Update DMSGameplayTags.cpp description."));

	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("InputTag.4"),
			FString("Update DMSGameplayTags.cpp description."));
//End*************************************************************************************************
}
