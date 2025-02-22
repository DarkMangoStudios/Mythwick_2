// Copyright Dark Mango Studios

#include "AbilitySystem/DMSAbilitySystemComponent.h"

#include "DMSGameplayTags.h" //Included to access native gameplay tags. GAS 87.

void UDMSAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UDMSAbilitySystemComponent::EffectApplied);

	/*//This is how we are accessing our gameplay tags from DMSGameplayTags.h
	const FDMSGameplayTags& GameplayTags = FDMSGameplayTags::Get();
	//Can also get directly via:
	//FDMSGameplayTags::Get().Attributes_Primary_Strength //(GAS 88)
	
	//DEBUG: Testing to see if we are able to access the Armor gameplay tag that was created natively.
	//Will print as many times as abilityactorinfoset is used to set up characters/enemies. GAS 87.
	/*GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Orange,
		FString::Printf(TEXT("Tag: %s"), 
		*GameplayTags.Attributes_Secondary_Armor.ToString()));#1#*/
}

//(GAS 98)
void UDMSAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		//GiveAbility(AbilitySpec);

		//Option to give ability and activate immediately. Function below does not allow AbilitySpec to be const.
		GiveAbilityAndActivateOnce(AbilitySpec);
	}
}

void UDMSAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                               const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	//Adding tag container to pass into get all asset tags below
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	//Any class who binds to effectAssetTags delegate, will receive a tag container filled with asset tags. Used with
	//overlay widget controller class
	EffectAssetTags.Broadcast(TagContainer);
	
}
