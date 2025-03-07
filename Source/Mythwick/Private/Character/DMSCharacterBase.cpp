// Copyright Dark Mango Studios


#include "Character/DMSCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/DMSAbilitySystemComponent.h"

ADMSCharacterBase::ADMSCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//AURA SPECIFIC. ADDS WEAPON TO HAND SOCKET, defined on skeletal meshes by name given below: "WeaponHandSocket"
	//************************************************************
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//************************************************************
	
}

void ADMSCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADMSCharacterBase::InitAbilityActorInfo()
{
	
}

void ADMSCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	//Need to set context handle in character. GAS 74.
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ADMSCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
}

//(GAS 98)
void ADMSCharacterBase::AddCharacterAbilities()
{
	UDMSAbilitySystemComponent* DMSASC = CastChecked<UDMSAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	DMSASC->AddCharacterAbilities(StartupAbilities);
}
