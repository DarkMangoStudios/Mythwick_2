// Copyright Dark Mango Studios


#include "Character/DMSCharacterBase.h"

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
