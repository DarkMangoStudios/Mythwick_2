// Copyright Dark Mango Studios


#include "AbilitySystem/DMSAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h" //Needed for "const FGameplayEffectModCallbackData& Data" param in post gameplay effect
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

UDMSAttributeSet::UDMSAttributeSet()
{
	/*InitHealth(50.f); //Will remove later to access via gameplay effects
	/*InitMaxHealth(100.f); //Will remove later to access via gameplay effects
	InitMana(24.f); //Will remove later to access via gameplay effects
	/*InitMaxMana(50.f); //Will remove later to access via gameplay effects*/
}

void UDMSAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Primary Attributes lifetime notifications
//Start*************************************************************************************************
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Resilience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Vigor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Constitution, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Dexterity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Charisma, COND_None, REPNOTIFY_Always);
//End*************************************************************************************************
	
	//Secondary Attributes lifetime notifications
//Start*************************************************************************************************
	//Strength Association
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MeleeArmorPen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MeleeCritDam, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MeleeCritChance, COND_None, REPNOTIFY_Always);

	//Intelligence Association
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, SpellArmorPen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, SpellCritDam, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, SpellCritChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, SpellSlotRegen, COND_None, REPNOTIFY_Always);

	//Resilience Association
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, BlockChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, CritResistance, COND_None, REPNOTIFY_Always);

	//Constitution Association
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, HealthRegen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, StaminaRegen, COND_None, REPNOTIFY_Always);

	//Dexterity Association
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, RangedArmorPen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, RangedCritDam, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, RangedCritChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Stealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, SleightOfHand, COND_None, REPNOTIFY_Always);

	//Charisma Association
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Persuasion, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Intimidation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Deception, COND_None, REPNOTIFY_Always);
//End*************************************************************************************************
	
	//Vital Attributes lifetime notifications
//Start*************************************************************************************************
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, SpellSlots, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxSpellSlots, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	//Adding auxilary attributes to represent held breath, adrenaline, hold onto ledge, etc.
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, AuxAttribute1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxAuxAttribute1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, AuxAttribute2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxAuxAttribute2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, AuxAttribute3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxAuxAttribute3, COND_None, REPNOTIFY_Always);
//End*************************************************************************************************
	
}

//PreAttributeChange is primarily just for clamping values to mins and maxes
void UDMSAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	//Clamping our vital attributes to never go above max values or under 0. Note, not actually setting values. GAS 64.
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}

	if (Attribute == GetSpellSlotsAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxSpellSlots());
	}

	if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
	}

	//AuxAttributes 1-3
	if (Attribute == GetAuxAttribute1Attribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxAuxAttribute1());
	}
	
	if (Attribute == GetAuxAttribute2Attribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxAuxAttribute2());
	}

	if (Attribute == GetAuxAttribute3Attribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxAuxAttribute3());
	}
	//Relic of attempted clamping for max values
	/*if (Attribute == GetMaxAuxAttribute3Attribute())
	{
		NewValue = FMath::Max(NewValue, 0.f);
	}*/
}

void UDMSAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	//Source = causer of the effect, Target = target of the effect (owner of this AS)

	//Getting the effect context handle data
	Props.EffectContextHandle = Data.EffectSpec.GetContext();

	//Getting the Source ASC data
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	//Getting source controller data
	if (IsValid(Props.SourceASC) && (Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid()))
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			//Getting the source character data
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	//Getting target actor data
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}

void UDMSAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);

	//Properly setting attribute values. GAS 64.
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		//Message for debugging
		//GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Cyan, FString::Printf(TEXT("Health: %f"), GetHealth()));

		//Actually setting proper values on attributes on clamp at max value
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}

	if (Data.EvaluatedData.Attribute == GetSpellSlotsAttribute())
	{
		SetSpellSlots(FMath::Clamp(GetSpellSlots(), 0.f, GetMaxSpellSlots()));
	}
	
	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.f, GetMaxStamina()));
	}

	//Aux 1-3 ACTIVE
	if (Data.EvaluatedData.Attribute == GetAuxAttribute1Attribute())
	{
		SetAuxAttribute1(FMath::Clamp(GetAuxAttribute1(), 0.f, GetMaxAuxAttribute1()));
	}
	if (Data.EvaluatedData.Attribute == GetAuxAttribute2Attribute())
	{
		SetAuxAttribute2(FMath::Clamp(GetAuxAttribute2(), 0.f, GetMaxAuxAttribute2()));
	}
	if (Data.EvaluatedData.Attribute == GetAuxAttribute3Attribute())
	{
		SetAuxAttribute3(FMath::Clamp(GetAuxAttribute3(), 0.f, GetMaxAuxAttribute3()));
	}
	
}

void UDMSAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Health, OldHealth);
}

void UDMSAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxHealth, OldMaxHealth);
}

void UDMSAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Mana, OldMana);
}

void UDMSAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxMana, OldMaxMana);
}

void UDMSAttributeSet::OnRep_SpellSlots(const FGameplayAttributeData& OldSpellSlots) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, SpellSlots, OldSpellSlots);
}

void UDMSAttributeSet::OnRep_MaxSpellSlots(const FGameplayAttributeData& OldMaxSpellSlots) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxSpellSlots, OldMaxSpellSlots);
}

void UDMSAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Stamina, OldStamina);
}

void UDMSAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxStamina, OldMaxStamina);
}

//AuxAttributes 1-3
void UDMSAttributeSet::OnRep_AuxAttribute1(const FGameplayAttributeData& OldAuxAttribute1) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, AuxAttribute1, OldAuxAttribute1);
}

void UDMSAttributeSet::OnRep_MaxAuxAttribute1(const FGameplayAttributeData& OldMaxAuxAttribute1) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxAuxAttribute1, OldMaxAuxAttribute1);
}

void UDMSAttributeSet::OnRep_AuxAttribute2(const FGameplayAttributeData& OldAuxAttribute2) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, AuxAttribute2, OldAuxAttribute2);
}

void UDMSAttributeSet::OnRep_MaxAuxAttribute2(const FGameplayAttributeData& OldMaxAuxAttribute2) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxAuxAttribute2, OldMaxAuxAttribute2);
}

void UDMSAttributeSet::OnRep_AuxAttribute3(const FGameplayAttributeData& OldAuxAttribute3) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, AuxAttribute3, OldAuxAttribute3);
}

void UDMSAttributeSet::OnRep_MaxAuxAttribute3(const FGameplayAttributeData& OldMaxAuxAttribute3) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxAuxAttribute3, OldMaxAuxAttribute3);
}

void UDMSAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Strength, OldStrength);
}

void UDMSAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Intelligence, OldIntelligence);
}

void UDMSAttributeSet::OnRep_Resilience(const FGameplayAttributeData& OldResilience) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Resilience, OldResilience);
}

void UDMSAttributeSet::OnRep_Vigor(const FGameplayAttributeData& OldVigor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Vigor, OldVigor);
}

void UDMSAttributeSet::OnRep_Constitution(const FGameplayAttributeData& OldConstitution) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Constitution, OldConstitution);
}

void UDMSAttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Dexterity, OldDexterity);
}

void UDMSAttributeSet::OnRep_Charisma(const FGameplayAttributeData& OldCharisma) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Charisma, OldCharisma);
}

/* Secondary Attributes */
//Strength Association
void UDMSAttributeSet::OnRep_MeleeArmorPen(const FGameplayAttributeData& OldMeleeArmorPen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MeleeArmorPen, OldMeleeArmorPen);
}

void UDMSAttributeSet::OnRep_MeleeCritDam(const FGameplayAttributeData& OldMeleeCritDam) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MeleeCritDam, OldMeleeCritDam);
}

void UDMSAttributeSet::OnRep_MeleeCritChance(const FGameplayAttributeData& OldMeleeCritChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MeleeCritChance, OldMeleeCritChance);
}

//Intelligence Association
void UDMSAttributeSet::OnRep_SpellArmorPen(const FGameplayAttributeData& OldSpellArmorPen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, SpellArmorPen, OldSpellArmorPen);
}

void UDMSAttributeSet::OnRep_SpellCritDam(const FGameplayAttributeData& OldSpellCritDam) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, SpellCritDam, OldSpellCritDam);
}

void UDMSAttributeSet::OnRep_SpellCritChance(const FGameplayAttributeData& OldSpellCritChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, SpellCritChance, OldSpellCritChance);
}

void UDMSAttributeSet::OnRep_SpellSlotRegen(const FGameplayAttributeData& OldSpellSlotRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, SpellSlotRegen, OldSpellSlotRegen);
}

//Resilience Association
void UDMSAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Armor, OldArmor);
}

void UDMSAttributeSet::OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, BlockChance, OldBlockChance);
}

void UDMSAttributeSet::OnRep_CritResistance(const FGameplayAttributeData& OldCritResistance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, CritResistance, OldCritResistance);
}

//Constitution Association
void UDMSAttributeSet::OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, HealthRegen, OldHealthRegen);
}

void UDMSAttributeSet::OnRep_StaminaRegen(const FGameplayAttributeData& OldStaminaRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, StaminaRegen, OldStaminaRegen);
}

//Dexterity Association
void UDMSAttributeSet::OnRep_RangedArmorPen(const FGameplayAttributeData& OldRangedArmorPen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, RangedArmorPen, OldRangedArmorPen);
}

void UDMSAttributeSet::OnRep_RangedCritDam(const FGameplayAttributeData& OldRangedCritDam) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, RangedCritDam, OldRangedCritDam);
}

void UDMSAttributeSet::OnRep_RangedCritChance(const FGameplayAttributeData& OldRangedCritChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, RangedCritChance, OldRangedCritChance);
}

void UDMSAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Speed, OldSpeed);
}

void UDMSAttributeSet::OnRep_Stealth(const FGameplayAttributeData& OldStealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Stealth, OldStealth);
}

void UDMSAttributeSet::OnRep_SleightOfHand(const FGameplayAttributeData& OldSleightOfHand) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, SleightOfHand, OldSleightOfHand);
}

//Charisma Association
void UDMSAttributeSet::OnRep_Persuasion(const FGameplayAttributeData& OldPersuasion) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Persuasion, OldPersuasion);
}

void UDMSAttributeSet::OnRep_Intimidation(const FGameplayAttributeData& OldIntimidation) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Intimidation, OldIntimidation);
}

void UDMSAttributeSet::OnRep_Deception(const FGameplayAttributeData& OldDeception) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Deception, OldDeception);
}
