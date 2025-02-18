// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "DMSCharacterBase.h"
#include "DMSCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MYTHWICK_API ADMSCharacter : public ADMSCharacterBase
{
	GENERATED_BODY()

public:
	ADMSCharacter();

	//Init Ability Actor info. Setting up our owner and avatar for ASC
	//~ Begin
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	//~ End

private:
	
	virtual void InitAbilityActorInfo() override;
	
};
