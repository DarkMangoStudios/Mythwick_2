// Copyright Dark Mango Studios


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/DMSAbilitySystemComponent.h"
#include "AbilitySystem/DMSAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	//Casting our inherited TObjectPtr "AttributeSet" to our DMSAttribute set, essentially linking to that class to use
	//its accessors to get our vital attribute values
	const UDMSAttributeSet* DMSAttributeSet = CastChecked<UDMSAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(DMSAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(DMSAttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(DMSAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(DMSAttributeSet->GetMaxMana());

	/* Fatigue/Aux Attributes not currently set up based on note saying getters will not be used later in favor
	 * of using gameplay effects. */
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UDMSAttributeSet* DMSAttributeSet = CastChecked<UDMSAttributeSet>(AttributeSet);

//START*********************************************************************************************************
	//Lambdas to replace bindings commented out at the bottom of the file
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
			);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
			);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnManaChanged.Broadcast(Data.NewValue);
			}
			);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetMaxManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxManaChanged.Broadcast(Data.NewValue);
			}
			);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetFatigueAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnFatigueChanged.Broadcast(Data.NewValue);
			}
			);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetMaxFatigueAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxFatigueChanged.Broadcast(Data.NewValue);
			}
			);

	//Aux Attributes 1-3 LIVE
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetAuxAttribute1Attribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnAuxAttribute1Changed.Broadcast(Data.NewValue);
			}
			);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetMaxAuxAttribute1Attribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxAuxAttribute1Changed.Broadcast(Data.NewValue);
			}
			);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetAuxAttribute2Attribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnAuxAttribute2Changed.Broadcast(Data.NewValue);
			}
			);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetMaxAuxAttribute2Attribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxAuxAttribute2Changed.Broadcast(Data.NewValue);
			}
			);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetAuxAttribute3Attribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnAuxAttribute3Changed.Broadcast(Data.NewValue);
			}
			);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetMaxAuxAttribute3Attribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxAuxAttribute3Changed.Broadcast(Data.NewValue);
			}
			);
//END*********************************************************************************************************

	
//START*********************************************************************************************************
	//Binding attributes bound on changes. Replaced with Lambdas above. GAS 62. Archived.
	/*AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		DMSAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);*/
//END*********************************************************************************************************

	
	//Lambda is a function without a name that can be used here to access objects with specific asset tags
	Cast<UDMSAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// For example, say that Tag = Message.HealthPotion
				// "Message.HealthPotion".MatchesTag("Message") will return True, "Message".MatchesTag("Message.HealthPotion") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
				
				//Shows message on screen for debugging as needed
				/*const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);*/
			}
		}
	);
}

//START*********************************************************************************************************
//Obsolete delegate bindings now due to addlambda in BindCallbacksToDependencies function above. Archived.
/*
void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::FatigueChanged(const FOnAttributeChangeData& Data) const
{
	OnFatigueChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxFatigueChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxFatigueChanged.Broadcast(Data.NewValue);
}

//AuxAttributes 1-3
void UOverlayWidgetController::AuxAttribute1Changed(const FOnAttributeChangeData& Data) const
{
	OnAuxAttribute1Changed.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxAuxAttribute1Changed(const FOnAttributeChangeData& Data) const
{
	OnMaxAuxAttribute1Changed.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::AuxAttribute2Changed(const FOnAttributeChangeData& Data) const
{
	OnAuxAttribute2Changed.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxAuxAttribute2Changed(const FOnAttributeChangeData& Data) const
{
	OnMaxAuxAttribute2Changed.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::AuxAttribute3Changed(const FOnAttributeChangeData& Data) const
{
	OnAuxAttribute3Changed.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxAuxAttribute3Changed(const FOnAttributeChangeData& Data) const
{
	OnAuxAttribute3Changed.Broadcast(Data.NewValue);
}
*/
//END*********************************************************************************************************