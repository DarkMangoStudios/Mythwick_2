// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DMSPlayerController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class MYTHWICK_API ADMSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADMSPlayerController();

	//Overriding player tick function for cursor trace/highlighting enemies
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	//Creating a pointer to point to our context mapping and naming it DMSContext
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> DMSContext;

	//Creating pointers to our input actions
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	
	//Creating functions for what our input actions will do. Must be bound to appropriate inputs in cpp
	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);
	void Jump();

	//Setting up cursor trace function for highlighting enemies.
	//Also making pointers to store cursor hits as frames go on.
	void CursorTrace();
	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;

	//Position of mouse cursor for Look action on top-down view. This is for controller support. Locks cursor to viewport.
	float LastLocationX;
	float LastLocationY;

	//Giving a default value of 12.f on look sensitivity. Can change in blueprint if desired.
	UPROPERTY(EditAnywhere, Category = "Adjust Look Sensitivity For Controller")
	float LookSensitivity {12.f};
	
};

