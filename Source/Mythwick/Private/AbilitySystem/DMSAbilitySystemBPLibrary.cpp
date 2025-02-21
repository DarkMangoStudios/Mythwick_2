// Copyright Dark Mango Studios


#include "AbilitySystem/DMSAbilitySystemBPLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UI/WidgetController/DMSWidgetController.h"
#include "Player/DMSPlayerState.h"
#include "UI/HUD/DMSHUD.h"

UOverlayWidgetController* UDMSAbilitySystemBPLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ADMSHUD* DMSHUD = Cast<ADMSHUD>(PC->GetHUD()))
		{
			ADMSPlayerState* PS = PC->GetPlayerState<ADMSPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return DMSHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	//In event info above is unavailable.
	return nullptr;
}

UAttributeMenuWidgetController* UDMSAbilitySystemBPLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ADMSHUD* DMSHUD = Cast<ADMSHUD>(PC->GetHUD()))
		{
			ADMSPlayerState* PS = PC->GetPlayerState<ADMSPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return DMSHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
