// Copyright Dark Mango Studios


#include "Player/DMSPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "Interaction/EnemyInterface.h"
#include "Kismet/GameplayStatics.h"

ADMSPlayerController::ADMSPlayerController()
{
	//Setting replication to true for multiplayer application
	bReplicates = true;
	
}

void ADMSPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	//Using cursor trace to highlight enemies through IEnemyInterface
	CursorTrace();
}

void ADMSPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(DMSContext);
	
	//Subsystem Setup
//**************************************************************************
	//Getting the local player subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem) //Prefer if statement over check assert in multiplayer applications as game won't crash if controllers are null
	{
		//Adding input context
		Subsystem->AddMappingContext(DMSContext, 0);
	}
//**************************************************************************

	
	//Showing cursor on screen, will change later. Need for tutorial.
//**************************************************************************
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
//**************************************************************************
	
}

void ADMSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Changing our input component to an enhanced input component pointer named EnhancedInputComponent.
	//CastChecked checks if the input component is valid before casting to our new type, UEnhancedInputComponent.
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	//Binding our inputs to the appropriate action functions below
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADMSPlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADMSPlayerController::Look);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ADMSPlayerController::Jump);
}

//Working function as of 1/1/2025. Universal: Not tied to DMSCharacter or BP_DMSCharacter
void ADMSPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

//Working function as of 1/1/2025. Universal: Not tied to DMSCharacter or BP_DMSCharacter. For TP View functionality
//Will Deactivate from the mapping context by removing the look "IA_Look" from BP_DMSPlayerController temporarily
/*void ADMSPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerYawInput(InputAxisVector.X);
		ControlledPawn->AddControllerPitchInput(InputAxisVector.Y);
	}
}*/

//This version of look will emulate controlling the mouse cursor with the right thumbstick for top down view.
void ADMSPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	float XPosition = InputAxisVector.X * LookSensitivity;
	float YPosition = InputAxisVector.Y * LookSensitivity;
	
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);

		int32 ViewportX, ViewportY;
		PC->GetViewportSize(ViewportX, ViewportY);

		if (LocalPlayer && LocalPlayer->ViewportClient)
		{
			bool bGotMousePosition = false;
			FVector2D MousePosition;
		
			bGotMousePosition = LocalPlayer->ViewportClient->GetMousePosition(MousePosition);
			
			float CurrentLocationX = MousePosition.X;
			float CurrentLocationY = MousePosition.Y;
			
			if (bGotMousePosition)
			{
				XPosition = FMath::Clamp(XPosition + CurrentLocationX, 0.f, ViewportX);
				YPosition = FMath::Clamp(YPosition + CurrentLocationY, 0.f, ViewportY);

				LastLocationX = XPosition;
				LastLocationY = YPosition;
				
				PC->SetMouseLocation(XPosition, YPosition);
			}
			else
			{
				PC->SetMouseLocation(LastLocationX, LastLocationY);
			}
		}
	}
}

//Working function as of 1/1/2025. Universal: Not tied to DMSCharacter or BP_DMSCharacter
void ADMSPlayerController::Jump()
{
	if (ACharacter* ControlledCharacter = GetPawn<ACharacter>())
	{
		ControlledCharacter->Jump();
	}
}

//Cursor is reading information on playertick to see if cursor hit is true. For highlighting enemies.
void ADMSPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	//Our pointers are constantly updating in order to accurately represent whether our cursor is still on
	//an enemy or not.
	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	//Cursor trace algorithm
//**************************************************************************************************
	/**
	 * Notes from lecture below, we are going over frame to frame situations using our pointers:
	 * Line trace from cursor. There are several scenarios:
	 *	A. LastActor is null && ThisActor is null
	 *		- Do nothing.
	 *	B. LastActor is null && ThisActor is valid
	 *		- Highlight ThisActor
	 *	C. LastActor is valid && ThisActor is null
	 *		- UnHighlight LastActor
	 *	D. Both actors are valid, but LastActor != ThisActor
	 *		- UnHighlight LastActor, and Highlight ThisActor
	 *	E. Both actors are valid, and are the same actor
	 *		- Do nothing.
	 *
	 *	Each situation is implemented below:
	 */

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Case B
			ThisActor->HighlightActor();
		}
		else
		{
			// Case A - both are null, do nothing			}
		}
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnHighlightActor();
		}
		else // both actors are valid
		{
			if (LastActor != ThisActor)
			{
				// Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Case E - Do nothing
			}
		}
	}
}
//**************************************************************************************************