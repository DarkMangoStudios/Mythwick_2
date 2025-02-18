// Copyright Dark Mango Studios


#include "UI/Widgets/DMSUserWidget.h"

//Calling WidgetControllerSet is primary goal here
void UDMSUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
