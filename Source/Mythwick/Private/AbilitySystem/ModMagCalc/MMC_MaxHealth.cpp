// Copyright Dark Mango Studios


#include "AbilitySystem/ModMagCalc/MMC_MaxHealth.h"

#include "AbilitySystem/DMSAttributeSet.h"
#include "Interaction/AttributeInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	//GAS 74. Snapshot has to do with timing of when to capture the effect spec
	ConstitutionDef.AttributeToCapture = UDMSAttributeSet::GetConstitutionAttribute();
	ConstitutionDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	ConstitutionDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(ConstitutionDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// Gather tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Constitution = 0.f;
	GetCapturedAttributeMagnitude(ConstitutionDef, Spec, EvaluationParameters, Constitution);
	//Putting a clamp on Constitution to never be a negative value
	Constitution = FMath::Max<float>(Constitution, 0.0f);

	IAttributeInterface* CombatInterface = Cast<IAttributeInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	//Can make a custom calculation with information extracted above
	//TODO: Change static variables below to player class variables, i.e.
	//Fighter starting health = 10, gets plus 6 health every level
	//Can also add feat later if desired, will later be shown on GAS 127 onward.
	//return ClassStartingHealth + ConstitutionModifier + PlayerLevelClassHealthAdd + FeatHPxPlayerLevel
	return 10 + (FMath::Floor((Constitution - 10)/2)) + (6 * (PlayerLevel - 1));
}
