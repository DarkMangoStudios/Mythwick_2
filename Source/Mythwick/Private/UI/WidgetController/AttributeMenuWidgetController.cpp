// Copyright Dark Mango Studios


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "DMSGameplayTags.h"
#include "AbilitySystem/DMSAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UDMSAttributeSet* AS = CastChecked<UDMSAttributeSet>(AttributeSet);

	check(PrimaryAttributeInfo);
	check(SecondaryAttributeInfo);
	check(VitalAttributeInfo);

	for (auto& Pair : AS->TagsToAttributes)
	{
		FDMSAttributeInfo PrimaryInfo = PrimaryAttributeInfo->FindAttributeInfoForTag(Pair.Key);
		PrimaryInfo.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(PrimaryInfo);

		FDMSAttributeInfo SecondaryInfo = SecondaryAttributeInfo->FindAttributeInfoForTag(Pair.Key);
		SecondaryInfo.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(SecondaryInfo);

		FDMSAttributeInfo VitalInfo = VitalAttributeInfo->FindAttributeInfoForTag(Pair.Key);
		VitalInfo.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(VitalInfo);
	}
}
