// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "Character/DMSCharacterBase.h"
#include "Interaction/EnemyInterface.h" //Was automatically added by Rider when we added IEnemyInterface to inheritance
#include "DMSEnemy.generated.h"

/**
 * 1/3/25 - Inheriting IEnemyInterface we created in order to highlight enemies when we hover over them.
 */
UCLASS()
class MYTHWICK_API ADMSEnemy : public ADMSCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()


public:
	ADMSEnemy();
	
	//Overriding our pure virtual functions from the EnemyInterface class
//********************************************************************************
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
//********************************************************************************

protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
};
