// Copyright Dark Mango Studios


#include "Character/DMSCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/DMSAbilitySystemComponent.h"
#include "AbilitySystem/DMSAttributeSet.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/DMSPlayerController.h"
#include "Player/DMSPlayerState.h"
#include "UI/HUD/DMSHUD.h"


ADMSCharacter::ADMSCharacter()
{
	//TopDown constraints that can be set in the editor or here. Remove most for Mythwick.
//***********************************************************************************************
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 400.f, 0);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
//***********************************************************************************************

	
	//Updated for FPV/TPV constraints that can be set in the editor or here. Remove most for Mythwick.
//***********************************************************************************************
	/*GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 400.f, 0);
	GetCharacterMovement()->bConstrainToPlane = false; //Changed
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true; //Changed
	bUseControllerRotationRoll = false;*/
//***********************************************************************************************
	
}

void ADMSCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Init ability actor info for the server
	InitAbilityActorInfo();
}

void ADMSCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	//Init ability actor info for the client
	InitAbilityActorInfo();
}

int32 ADMSCharacter::GetPlayerLevel()
{
	const ADMSPlayerState* DMSPlayerState = GetPlayerState<ADMSPlayerState>();
	check(DMSPlayerState);
	return DMSPlayerState->GetPlayerLevel();
}

//Made a function to init ability actor info as the code would be used twice above
void ADMSCharacter::InitAbilityActorInfo()
{
	//Init Ability Actor info 
	ADMSPlayerState* DMSPlayerState = GetPlayerState<ADMSPlayerState>();
	check(DMSPlayerState);
	//SetOwner(DMSPlayerState); //Setting the owner as the ownerActor, see GAS video 23, 21min
	DMSPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(DMSPlayerState, this);

	//Info setting for gameplay tags GAS vid 54
	Cast<UDMSAbilitySystemComponent>(DMSPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();

	//Setting the null ASC and AS components inherited from character base to information from DMSPlayerState
	AbilitySystemComponent = DMSPlayerState->GetAbilitySystemComponent();
	AttributeSet = DMSPlayerState->GetAttributeSet();

	//Setting up a pointer to access HUD info
	if (ADMSPlayerController* DMSPlayerController = Cast<ADMSPlayerController>(GetController()))
	{
		if (ADMSHUD* DMSHUD = Cast<ADMSHUD>(DMSPlayerController->GetHUD()))
		{
			//Initializing 4 key variables
			DMSHUD->InitOverlay(DMSPlayerController, DMSPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}

	//Initializing primary default values for DMSCharacter on server. GAS 66.
	InitializePrimaryAttributes();
}
