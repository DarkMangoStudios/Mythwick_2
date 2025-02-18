// Copyright Dark Mango Studios


#include "Character/DMSEnemy.h"
#include "AbilitySystem/DMSAbilitySystemComponent.h"
#include "AbilitySystem/DMSAttributeSet.h"
#include "Mythwick/Mythwick.h"

ADMSEnemy::ADMSEnemy()
{
	//Setting the collision settings to block visibility. This can be overridden in BP
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	//Creating subobject of ASC and Attribute System to make them valid objects
//***************************************************************************************
	AbilitySystemComponent = CreateDefaultSubobject<UDMSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true); //Setting replicated for multiplayer
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed); //Can use Full, Mixed or Minimal. REF GAS video 22

	AttributeSet = CreateDefaultSubobject<UDMSAttributeSet>("AttributeSet");
//***************************************************************************************
}

void ADMSEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	//We usually shouldn't set the depth of the stencil value every time, but it is a cheap operation and should be fine
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED); //Defined in Mythwick.h

	//Highlighting the weapon. Weapon can be accessed as it is inherited from the DMSCharacterBase
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void ADMSEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

int32 ADMSEnemy::GetPlayerLevel()
{
	return Level;
}

void ADMSEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilityActorInfo();
	
}

void ADMSEnemy::InitAbilityActorInfo()
{
	//Initializing our ability system component in begin play for AI-Controlled character, as ASC lives on the pawn
	//virtual void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor); Owner and Avatar are the same here
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	Cast<UDMSAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}
