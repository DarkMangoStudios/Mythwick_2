// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "DMSHUD.generated.h"

class UOverlayWidgetController;
class UDMSUserWidget;
class UAbilitySystemComponent;	//Added forward declaration outside of tutorial... make sure all is working here
class UAttributeSet;			//Added forward declaration outside of tutorial... make sure all is working here
struct FWidgetControllerParams;
/**
 * 
 */
UCLASS()
class MYTHWICK_API ADMSHUD : public AHUD
{
	GENERATED_BODY()

public:

	//Making a getter function to get the overlay widget controller. Need a pointer in private section
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	//Getter for attribute menu widget controller (GAS 92)
	UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);

	//Since we do not directly have access to our 4 key variables: PlayerState, PlayerController, ASC and Attr Set
	//We will make a function in order to set those variables
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:

private:

	UPROPERTY()
	TObjectPtr<UDMSUserWidget> OverlayWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UDMSUserWidget> OverlayWidgetClass;

	//Pointer to be used in our getter function
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	//Need new subclass to assign our NewObject to within our getter function
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
};
