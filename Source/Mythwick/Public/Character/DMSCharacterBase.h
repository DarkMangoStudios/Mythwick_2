// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "DMSCharacterBase.generated.h"

//Forward declaring objects (classes)
class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

UCLASS(Abstract)
class MYTHWICK_API ADMSCharacterBase : public ACharacter, public IAbilitySystemInterface
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

	void InitializePrimaryAttributes() const;

};
