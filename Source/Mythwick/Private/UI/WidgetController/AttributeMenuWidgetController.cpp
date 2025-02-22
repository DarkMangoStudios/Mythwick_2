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

	for (auto& Pair : AS->TagsToAttributes)
	{
		FDMSAttributeInfo Info = PrimaryAttributeInfo->FindAttributeInfoForTag(Pair.Key);
		Info.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(Info);
	}
}
