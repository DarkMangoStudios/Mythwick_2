// Copyright Dark Mango Studios


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "DMSGameplayTags.h"
#include "AbilitySystem/DMSAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UDMSAttributeSet* AS = CastChecked<UDMSAttributeSet>(AttributeSet);
	
	//Set data assets within BP_AttributeMenuWidgetController. Checking initial setup.
	checkf(PrimaryAttributeInfo, TEXT("PrimaryAttributeInfo data asset not set. See AttributeMenuWidgetController.cpp"));
	checkf(SecondaryAttributeInfo, TEXT("SecondaryAttributeInfo data asset not set. See AttributeMenuWidgetController.cpp"));
	checkf(VitalAttributeInfo, TEXT("VitalAttributeInfo data asset not set. See AttributeMenuWidgetController.cpp"));
	
	for (auto& Pair : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
			[this, Pair, AS](const FOnAttributeChangeData& Data)
			{
				//Note: No longer capturing AS in lambda. Can remove for cleanup later if desired.
				
				BroadcastAttributeInfo(Pair.Key, Pair.Value(), PrimaryAttributeInfo);
				BroadcastAttributeInfo(Pair.Key, Pair.Value(), SecondaryAttributeInfo);
				BroadcastAttributeInfo(Pair.Key, Pair.Value(), VitalAttributeInfo);

				//Removed in favor of the function BroadcastAttributeInfo (GAS 96)
				/*FDMSAttributeInfo PrimaryInfo = PrimaryAttributeInfo->FindAttributeInfoForTag(Pair.Key);
				PrimaryInfo.AttributeValue = Pair.Value().GetNumericValue(AS);
				AttributeInfoDelegate.Broadcast(PrimaryInfo);

				FDMSAttributeInfo SecondaryInfo = SecondaryAttributeInfo->FindAttributeInfoForTag(Pair.Key);
				SecondaryInfo.AttributeValue = Pair.Value().GetNumericValue(AS);
				AttributeInfoDelegate.Broadcast(SecondaryInfo);

				FDMSAttributeInfo VitalInfo = VitalAttributeInfo->FindAttributeInfoForTag(Pair.Key);
				VitalInfo.AttributeValue = Pair.Value().GetNumericValue(AS);
				AttributeInfoDelegate.Broadcast(VitalInfo);*/
			}
		);
	}
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UDMSAttributeSet* AS = CastChecked<UDMSAttributeSet>(AttributeSet);

	//Set data assets within BP_AttributeMenuWidgetController. Checking initial setup.
	checkf(PrimaryAttributeInfo, TEXT("PrimaryAttributeInfo data asset not set. See AttributeMenuWidgetController.cpp"));
	checkf(SecondaryAttributeInfo, TEXT("SecondaryAttributeInfo data asset not set. See AttributeMenuWidgetController.cpp"));
	checkf(VitalAttributeInfo, TEXT("VitalAttributeInfo data asset not set. See AttributeMenuWidgetController.cpp"));

	for (auto& Pair : AS->TagsToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value(), PrimaryAttributeInfo);
		BroadcastAttributeInfo(Pair.Key, Pair.Value(), SecondaryAttributeInfo);
		BroadcastAttributeInfo(Pair.Key, Pair.Value(), VitalAttributeInfo);

		//Removed in favor of the function BroadcastAttributeInfo (GAS 96)
		/*FDMSAttributeInfo PrimaryInfo = PrimaryAttributeInfo->FindAttributeInfoForTag(Pair.Key);
		PrimaryInfo.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(PrimaryInfo);

		FDMSAttributeInfo SecondaryInfo = SecondaryAttributeInfo->FindAttributeInfoForTag(Pair.Key);
		SecondaryInfo.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(SecondaryInfo);

		FDMSAttributeInfo VitalInfo = VitalAttributeInfo->FindAttributeInfoForTag(Pair.Key);
		VitalInfo.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(VitalInfo);*/
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute, const UAttributeInfo* PassedAttributeInfo) const
{
	FDMSAttributeInfo Info = PassedAttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
