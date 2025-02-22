// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Interaction/AttributeInterface.h"
#include "DMSCharacterBase.generated.h"

//Forward declaring objects (classes)
class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

UCLASS(Abstract)
class MYTHWICK_API ADMSCharacterBase : public ACharacter, public IAbilitySystemInterface, public IAttributeInterface
{
	GENERATED_BODY()
	
public:
	
	ADMSCharacterBase();

	//Need to override pure virtual function from IAbilitySystemInterface below.
	//Creating a getter function for ASC and Attribute set. Functions defined inline to return their respective objects
//************************************************************
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
//************************************************************
	
protected:
	
	virtual void BeginPlay() override;

	//AURA SPECIFIC. ADDS WEAPON TO HAND SOCKET, defined on skeletal meshes by name given in cpp file
//************************************************************
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
//************************************************************

	
	//Making an ability system component and attribute set to pass down to child classes. Forward declared above and
	//objects/pointers created below are null.
//************************************************************
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
//************************************************************

	virtual void InitAbilityActorInfo();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

	//Refactored Initialization of attributes function
	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;
	void InitializeDefaultAttributes() const;

	void AddCharacterAbilities();
	
private:
	
	//(GAS 98) Array of abilities
	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};
