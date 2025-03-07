// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AttributeInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAttributeInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYTHWICK_API IAttributeInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual int32 GetPlayerLevel();
};
