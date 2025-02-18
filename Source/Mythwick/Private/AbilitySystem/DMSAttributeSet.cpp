// Copyright Dark Mango Studios


#include "AbilitySystem/DMSAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h" //Needed for "const FGameplayEffectModCallbackData& Data" param in post gameplay effect
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

UDMSAttributeSet::UDMSAttributeSet()
{
	InitHealth(50.f); //Will remove later to access via gameplay effects
	InitMaxHealth(100.f); //Will remove later to access via gameplay effects
	InitMana(24.f); //Will remove later to access via gameplay effects
	InitMaxMana(50.f); //Will remove later to access via gameplay effects
}

void UDMSAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Primary Attributes Lifetime notifications
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Resilience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Vigor, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);

	//Adding auxilary attributes to represent held breath, adrenaline, hold onto ledge, etc.
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, AuxAttribute1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxAuxAttribute1, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, AuxAttribute2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxAuxAttribute2, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, AuxAttribute3, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDMSAttributeSet, MaxAuxAttribute3, COND_None, REPNOTIFY_Always);
	
}

//PreAttributeChange is primarily just for clamping values to mins and maxes
void UDMSAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	//Clamping our vital attributes to never go above max values or under 0. Note, not actually setting values. GAS 64.
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	/*if (Attribute == GetMaxHealthAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.f);
	}*/
	
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
	/*if (Attribute == GetMaxManaAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.f);
	}*/

	if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
	}
	/*if (Attribute == GetMaxStaminaAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.f);
	}*/

	//AuxAttributes 1-3
	if (Attribute == GetAuxAttribute1Attribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxAuxAttribute1());
	}
	/*if (Attribute == GetMaxAuxAttribute1Attribute())
	{
		NewValue = FMath::Max(NewValue, 0.f);
	}*/
	
	if (Attribute == GetAuxAttribute2Attribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxAuxAttribute2());
	}
	/*if (Attribute == GetMaxAuxAttribute2Attribute())
	{
		NewValue = FMath::Max(NewValue, 0.f);
	}*/

	if (Attribute == GetAuxAttribute3Attribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxAuxAttribute3());
	}
	/*if (Attribute == GetMaxAuxAttribute3Attribute())
	{
		NewValue = FMath::Max(NewValue, 0.f);
	}*/
	
}

void UDMSAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	//Source = causer of the effect, Target = target of the effect (owner of this AS)

	//Getting the effect context handle data
	Props.EffectContextHandle = Data.EffectSpec.GetContext();

	//Getting the Source ASC data
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	//Getting source controller data
	if (IsValid(Props.SourceASC) && (Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid()))
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			//Getting the source character data
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	//Getting target actor data
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}

void UDMSAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);

	//Properly setting attribute values. GAS 64.
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		//Message for debugging
		//GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Cyan, FString::Printf(TEXT("Health: %f"), GetHealth()));

		//Actually setting proper values on attributes on clamp at max value
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
	
	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.f, GetMaxStamina()));
	}

	//Aux 1-3 ACTIVE
	if (Data.EvaluatedData.Attribute == GetAuxAttribute1Attribute())
	{
		SetAuxAttribute1(FMath::Clamp(GetAuxAttribute1(), 0.f, GetMaxAuxAttribute1()));
	}
	if (Data.EvaluatedData.Attribute == GetAuxAttribute2Attribute())
	{
		SetAuxAttribute2(FMath::Clamp(GetAuxAttribute2(), 0.f, GetMaxAuxAttribute2()));
	}
	if (Data.EvaluatedData.Attribute == GetAuxAttribute3Attribute())
	{
		SetAuxAttribute3(FMath::Clamp(GetAuxAttribute3(), 0.f, GetMaxAuxAttribute3()));
	}
	
}

void UDMSAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Health, OldHealth);
}

void UDMSAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxHealth, OldMaxHealth);
}

void UDMSAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Mana, OldMana);
}

void UDMSAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxMana, OldMaxMana);
}

void UDMSAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Stamina, OldStamina);
}

void UDMSAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxStamina, OldMaxStamina);
}

//AuxAttributes 1-3
void UDMSAttributeSet::OnRep_AuxAttribute1(const FGameplayAttributeData& OldAuxAttribute1) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, AuxAttribute1, OldAuxAttribute1);
}

void UDMSAttributeSet::OnRep_MaxAuxAttribute1(const FGameplayAttributeData& OldMaxAuxAttribute1) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxAuxAttribute1, OldMaxAuxAttribute1);
}

void UDMSAttributeSet::OnRep_AuxAttribute2(const FGameplayAttributeData& OldAuxAttribute2) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, AuxAttribute2, OldAuxAttribute2);
}

void UDMSAttributeSet::OnRep_MaxAuxAttribute2(const FGameplayAttributeData& OldMaxAuxAttribute2) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxAuxAttribute2, OldMaxAuxAttribute2);
}

void UDMSAttributeSet::OnRep_AuxAttribute3(const FGameplayAttributeData& OldAuxAttribute3) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, AuxAttribute3, OldAuxAttribute3);
}

void UDMSAttributeSet::OnRep_MaxAuxAttribute3(const FGameplayAttributeData& OldMaxAuxAttribute3) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, MaxAuxAttribute3, OldMaxAuxAttribute3);
}

void UDMSAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Strength, OldStrength);
}

void UDMSAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Intelligence, OldIntelligence);
}

void UDMSAttributeSet::OnRep_Resilience(const FGameplayAttributeData& OldResilience) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Resilience, OldResilience);
}

void UDMSAttributeSet::OnRep_Vigor(const FGameplayAttributeData& OldVigor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDMSAttributeSet, Vigor, OldVigor);
}