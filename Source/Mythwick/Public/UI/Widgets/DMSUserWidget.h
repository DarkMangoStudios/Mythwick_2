// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DMSUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYTHWICK_API UDMSUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	//Using this function to call "constructor" like function below 'WidgetControllerSet();'
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	//Setting up a basic WidgetController object to interact with this class
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:

	//Basically like a constructor to setup our widget controller, implementable event means we can define in BP
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
