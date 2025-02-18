// Copyright Dark Mango Studios


#include "UI/WidgetController/DMSWidgetController.h"

void UDMSWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UDMSWidgetController::BroadcastInitialValues()
{
	
}

void UDMSWidgetController::BindCallbacksToDependencies()
{
	
}
