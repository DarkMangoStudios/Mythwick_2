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

	FDMSAttributeInfo Info = PrimaryAttributeInfo->FindAttributeInfoForTag(FDMSGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
}
