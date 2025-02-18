// Copyright Dark Mango Studios

#include "AbilitySystem/DMSAbilitySystemComponent.h"

void UDMSAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UDMSAbilitySystemComponent::EffectApplied);
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
