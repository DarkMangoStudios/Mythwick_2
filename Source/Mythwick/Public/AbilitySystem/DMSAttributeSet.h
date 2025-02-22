// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayEffect.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "DMSAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

//No longer needed. (GAS 95)
//DECLARE_DELEGATE_RetVal(FGameplayAttribute, FAttributeSignature);

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}
	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	APlayerController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

//GAS 95. Sweeping ugly code out of sight...
//typedef TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultTSDelegateUserPolicy>::FFuncPtr FAttributeFuncPtr;

//typedef is specific to the FGameplayAttribute() signature, but TStaticFuncPtr is generic to any signature chosen.
template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultTSDelegateUserPolicy>::FFuncPtr;

/**
 * 
 */
UCLASS()
class MYTHWICK_API UDMSAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UDMSAttributeSet();
	
	//GetLifeTimeReplicatedProps needed for multiplayer replication, boilerplate
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	//To link our attribute menu controller more efficiently. (GAS 95) Function pointer
	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;
	//TMap<FGameplayTag, FGameplayAttribute(*)()> TagsToAttributes;
	//TMap<FGameplayTag, TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultTSDelegateUserPolicy>::FFuncPtr> TagsToAttributes;
	//TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultTSDelegateUserPolicy>::FFuncPtr FunctionPointer;

	//Showing off (GAS 95)
	/*TStaticFuncPtr<float(int32, float, int32)> RandomFunctionPointer;
	static float RandomFunction(int32 I, float F, int32 I2) { return 0.f; }*/
	
	
	//Primary Attributes
//Start*************************************************************************************************
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Primary Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Resilience);

	//Vigor will be commented out later on to be replaced with Constitution
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Primary Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Vigor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Constitution, Category = "Primary Attributes")
	FGameplayAttributeData Constitution;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Constitution);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Dexterity, Category = "Primary Attributes")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Dexterity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Charisma, Category = "Primary Attributes")
	FGameplayAttributeData Charisma;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Charisma);
//End*************************************************************************************************

	//Secondary Attributes
//Start*************************************************************************************************
	//Strength Association
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MeleeArmorPen, Category = "Secondary Attributes")
	FGameplayAttributeData MeleeArmorPen;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MeleeArmorPen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MeleeCritDam, Category = "Secondary Attributes")
	FGameplayAttributeData MeleeCritDam;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MeleeCritDam);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MeleeCritChance, Category = "Secondary Attributes")
	FGameplayAttributeData MeleeCritChance;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MeleeCritChance);

	//Intelligence Association
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SpellArmorPen, Category = "Secondary Attributes")
	FGameplayAttributeData SpellArmorPen;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, SpellArmorPen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SpellCritDam, Category = "Secondary Attributes")
	FGameplayAttributeData SpellCritDam;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, SpellCritDam);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SpellCritChance, Category = "Secondary Attributes")
	FGameplayAttributeData SpellCritChance;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, SpellCritChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SpellSlotRegen, Category = "Secondary Attributes")
	FGameplayAttributeData SpellSlotRegen;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, SpellSlotRegen);

	//Resilience Association
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Secondary Attributes")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, BlockChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CritResistance, Category = "Secondary Attributes")
	FGameplayAttributeData CritResistance;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, CritResistance);

	//Constitution Association
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegen, Category = "Secondary Attributes")
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, HealthRegen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_StaminaRegen, Category = "Secondary Attributes")
	FGameplayAttributeData StaminaRegen;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, StaminaRegen);

	//Dexterity Association
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_RangedArmorPen, Category = "Secondary Attributes")
	FGameplayAttributeData RangedArmorPen;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, RangedArmorPen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_RangedCritDam, Category = "Secondary Attributes")
	FGameplayAttributeData RangedCritDam;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, RangedCritDam);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_RangedCritChance, Category = "Secondary Attributes")
	FGameplayAttributeData RangedCritChance;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, RangedCritChance);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Speed, Category = "Secondary Attributes")
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Speed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stealth, Category = "Secondary Attributes")
	FGameplayAttributeData Stealth;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Stealth);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SleightOfHand, Category = "Secondary Attributes")
	FGameplayAttributeData SleightOfHand;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, SleightOfHand);

	//Charisma Association
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Persuasion, Category = "Secondary Attributes")
	FGameplayAttributeData Persuasion;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Persuasion);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intimidation, Category = "Secondary Attributes")
	FGameplayAttributeData Intimidation;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Intimidation);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Deception, Category = "Secondary Attributes")
	FGameplayAttributeData Deception;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Deception);
//End*************************************************************************************************
	
	//Vital Attributes
//Start*************************************************************************************************
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxMana);

	//SpellSlots rather than Mana, can refactor later by removing all Mana related items
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SpellSlots, Category = "Vital Attributes")
	FGameplayAttributeData SpellSlots;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, SpellSlots);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxSpellSlots, Category = "Vital Attributes")
	FGameplayAttributeData MaxSpellSlots;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxSpellSlots);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Vital Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "Vital Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxStamina);

	//AuxAttributes 1-3
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AuxAttribute1, Category = "Vital Attributes")
	FGameplayAttributeData AuxAttribute1;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, AuxAttribute1);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxAuxAttribute1, Category = "Vital Attributes")
	FGameplayAttributeData MaxAuxAttribute1;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxAuxAttribute1);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AuxAttribute2, Category = "Vital Attributes")
	FGameplayAttributeData AuxAttribute2;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, AuxAttribute2);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxAuxAttribute2, Category = "Vital Attributes")
	FGameplayAttributeData MaxAuxAttribute2;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxAuxAttribute2);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AuxAttribute3, Category = "Vital Attributes")
	FGameplayAttributeData AuxAttribute3;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, AuxAttribute3);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxAuxAttribute3, Category = "Vital Attributes")
	FGameplayAttributeData MaxAuxAttribute3;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxAuxAttribute3);
//End*************************************************************************************************

	//OnRep UFUNCTIONS
//Start*************************************************************************************************
	/* Primary Attributes */
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	UFUNCTION()
	void OnRep_Constitution(const FGameplayAttributeData& OldConstitution) const;

	UFUNCTION()
	void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const;

	UFUNCTION()
	void OnRep_Charisma(const FGameplayAttributeData& OldCharisma) const;

	/* Secondary Attributes */
	//Strength Association
	UFUNCTION()
	void OnRep_MeleeArmorPen(const FGameplayAttributeData& OldMeleeArmorPen) const;

	UFUNCTION()
	void OnRep_MeleeCritDam(const FGameplayAttributeData& OldMeleeCritDam) const;

	UFUNCTION()
	void OnRep_MeleeCritChance(const FGameplayAttributeData& OldMeleeCritChance) const;

	//Intelligence Association
	UFUNCTION()
	void OnRep_SpellArmorPen(const FGameplayAttributeData& OldMeleeArmorPen) const;

	UFUNCTION()
	void OnRep_SpellCritDam(const FGameplayAttributeData& OldSpellCritDam) const;

	UFUNCTION()
	void OnRep_SpellCritChance(const FGameplayAttributeData& OldSpellCritChance) const;

	UFUNCTION()
	void OnRep_SpellSlotRegen(const FGameplayAttributeData& OldSpellSlotRegen) const;

	//Resilience Association
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UFUNCTION()
	void OnRep_CritResistance(const FGameplayAttributeData& OldCritResistance) const;

	//Constitution Association
	UFUNCTION()
	void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const;

	UFUNCTION()
	void OnRep_StaminaRegen(const FGameplayAttributeData& OldStaminaRegen) const;

	//Dexterity Association
	UFUNCTION()
	void OnRep_RangedArmorPen(const FGameplayAttributeData& OldRangedArmorPen) const;

	UFUNCTION()
	void OnRep_RangedCritDam(const FGameplayAttributeData& OldRangedCritDam) const;

	UFUNCTION()
	void OnRep_RangedCritChance(const FGameplayAttributeData& OldRangedCritChance) const;

	UFUNCTION()
	void OnRep_Speed(const FGameplayAttributeData& OldSpeed) const;

	UFUNCTION()
	void OnRep_Stealth(const FGameplayAttributeData& OldStealth) const;

	UFUNCTION()
	void OnRep_SleightOfHand(const FGameplayAttributeData& OldSleightOfHand) const;

	//Charisma Association
	UFUNCTION()
	void OnRep_Persuasion(const FGameplayAttributeData& OldPersuasion) const;

	UFUNCTION()
	void OnRep_Intimidation(const FGameplayAttributeData& OldIntimidation) const;

	UFUNCTION()
	void OnRep_Deception(const FGameplayAttributeData& OldDeception) const;
	
	/* Vital Attributes */
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UFUNCTION()
	void OnRep_SpellSlots(const FGameplayAttributeData& OldSpellSlots) const;

	UFUNCTION()
	void OnRep_MaxSpellSlots(const FGameplayAttributeData& OldMaxSpellSlots) const;

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;
	
	//Vital AuxAttributes 1-3
	UFUNCTION()
	void OnRep_AuxAttribute1(const FGameplayAttributeData& OldAuxAttribute1) const;

	UFUNCTION()
	void OnRep_MaxAuxAttribute1(const FGameplayAttributeData& OldMaxAuxAttribute1) const;

	UFUNCTION()
	void OnRep_AuxAttribute2(const FGameplayAttributeData& OldAuxAttribute2) const;

	UFUNCTION()
	void OnRep_MaxAuxAttribute2(const FGameplayAttributeData& OldMaxAuxAttribute2) const;
	
	UFUNCTION()
	void OnRep_AuxAttribute3(const FGameplayAttributeData& OldAuxAttribute3) const;

	UFUNCTION()
	void OnRep_MaxAuxAttribute3(const FGameplayAttributeData& OldMaxAuxAttribute3) const;
	//End*************************************************************************************************
	
private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;	
};

