// Copyright Dark Mango Studios


#include "UI/HUD/DMSHUD.h"

//#include "src/Core/MathFunctions.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "UI/Widgets/DMSUserWidget.h"

UOverlayWidgetController* ADMSHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		//Assigning the new object to our OverlayWidgetControllerClass object
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);

		//BindCallbacksToDependencies here, should pick up changes in game and update our hud
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

//Setting up communication for the attribute menu almost exactly like the overlay above. (GAS 92)
UAttributeMenuWidgetController* ADMSHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	if (AttributeMenuWidgetController == nullptr)
	{
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this,AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->SetWidgetControllerParams(WCParams);
		AttributeMenuWidgetController->BindCallbacksToDependencies();
	}
	return AttributeMenuWidgetController;
}

void ADMSHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	//checkf will crash if objects are null, and display message
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized. Please fill out BP_DMSHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized. Please fill out BP_DMSHUD"));
	
	//Creating the overlay widget
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UDMSUserWidget>(Widget);

	//Creating the widget controller
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	//Only after this setWidgetController has happened, then we should broadcast values from AS
	OverlayWidget->SetWidgetController(WidgetController);

	//Broadcasting initial values to our overlay
	WidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
}

