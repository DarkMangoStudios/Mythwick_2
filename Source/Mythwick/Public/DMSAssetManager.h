// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "DMSAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class MYTHWICK_API UDMSAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:

	static UDMSAssetManager& Get();

protected:

	virtual void StartInitialLoading() override;
};
