// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "DMSPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
/**
 * 
 */
UCLASS()
class MYTHWICK_API ADMSPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ADMSPlayerState();

	//Pasted in from DMSCharacterBase.h. Player state needs it's own getters as they are not inherited by charbase
//***************************************************************************************
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
//***************************************************************************************

protected:
	//Boilerplate, creating ASC and attribute system, null until defined in cpp file
//***************************************************************************************
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
//***************************************************************************************
};
