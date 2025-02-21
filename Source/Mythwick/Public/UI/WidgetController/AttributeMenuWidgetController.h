// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/DMSWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class MYTHWICK_API UAttributeMenuWidgetController : public UDMSWidgetController
{
	GENERATED_BODY()
public:
	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;
};
