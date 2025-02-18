// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYTHWICK_API IEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//Can use later to highlight objects in the world through an interface instead of just enemies
	//Pure virtual functions will cause compiler to crash, MUST OVERRIDE THEM IN INHERITED CLASSES
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
