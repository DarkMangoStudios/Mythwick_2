// Copyright Dark Mango Studios


#include "DMSAssetManager.h"
#include "DMSGameplayTags.h"

UDMSAssetManager& UDMSAssetManager::Get()
{
    check(GEngine);

    UDMSAssetManager* DMSAssetManager = Cast<UDMSAssetManager>(GEngine->AssetManager);
    return *DMSAssetManager;
}

void UDMSAssetManager::StartInitialLoading()
{
    Super::StartInitialLoading();

    FDMSGameplayTags::InitializeNativeGameplayTags();
}
