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

	/*
	 *  Primary Attributes
	 */

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
	
	/*
	 *  Vital Attributes
	 */
	
	//Setting up game attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Health); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxHealth); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Mana); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxMana); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Vital Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Stamina); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "Vital Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxStamina); //Will remove later to access via gameplay effects?

	//AuxAttributes 1-3
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AuxAttribute1, Category = "Vital Attributes")
	FGameplayAttributeData AuxAttribute1;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, AuxAttribute1); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxAuxAttribute1, Category = "Vital Attributes")
	FGameplayAttributeData MaxAuxAttribute1;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxAuxAttribute1); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AuxAttribute2, Category = "Vital Attributes")
	FGameplayAttributeData AuxAttribute2;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, AuxAttribute2); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxAuxAttribute2, Category = "Vital Attributes")
	FGameplayAttributeData MaxAuxAttribute2;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxAuxAttribute2); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AuxAttribute3, Category = "Vital Attributes")
	FGameplayAttributeData AuxAttribute3;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, AuxAttribute3); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxAuxAttribute3, Category = "Vital Attributes")
	FGameplayAttributeData MaxAuxAttribute3;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxAuxAttribute3); //Will remove later to access via gameplay effects?

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;

	//AuxAttributes 1-3
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


	//Primary Attributes setup
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

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;	
};

