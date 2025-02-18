// Copyright Dark Mango Studios


#include "Player/DMSPlayerState.h"

//Included for creating subcomponents below
#include "AbilitySystem/DMSAbilitySystemComponent.h"
#include "AbilitySystem/DMSAttributeSet.h"
#include "Net/UnrealNetwork.h"

ADMSPlayerState::ADMSPlayerState()
{
	//Creating subobject of ASC and Attribute System to make them valid objects
//***************************************************************************************
	AbilitySystemComponent = CreateDefaultSubobject<UDMSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true); //Setting replicated for multiplayer
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed); //Can use Full, Mixed or Minimal. REF GAS video 22

	AttributeSet = CreateDefaultSubobject<UDMSAttributeSet>("AttributeSet");
//***************************************************************************************


//***************************************************************************************
    /**
     * Warning Message:
     * Variable 'NetUpdateFrequency' is deprecated, reason: 'Public access to NetUpdateFrequency has been deprecated.
     * Use SetNetUpdateFrequency() and GetNetUpdateFrequency() instead. Please update your code to the new API before
     * upgrading to the next release, otherwise your project will no longer compile.'
     **/
    //NetUpdateFrequency = 100.f;

	//Instead of above:
	SetNetUpdateFrequency(100.f);
//***************************************************************************************
}

void ADMSPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Boiler plate for make variables replicated for multiplayer functionality. GAS 73.
	DOREPLIFETIME(ADMSPlayerState, Level);
}

UAbilitySystemComponent* ADMSPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ADMSPlayerState::OnRep_Level(int32 OldLevel)
{
	
}
