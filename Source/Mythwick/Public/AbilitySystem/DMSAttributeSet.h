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

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Fatigue, Category = "Vital Attributes")
	FGameplayAttributeData Fatigue;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, Fatigue); //Will remove later to access via gameplay effects?

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxFatigue, Category = "Vital Attributes")
	FGameplayAttributeData MaxFatigue;
	ATTRIBUTE_ACCESSORS(UDMSAttributeSet, MaxFatigue); //Will remove later to access via gameplay effects?

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
	void OnRep_Fatigue(const FGameplayAttributeData& OldFatigue) const;

	UFUNCTION()
	void OnRep_MaxFatigue(const FGameplayAttributeData& OldMaxFatigue) const;

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

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;	
};

