// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/DMSWidgetController.h"
#include "OverlayWidgetController.generated.h"

USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag MessageTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Message = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UDMSUserWidget> MessageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Image = nullptr;
};

//No longer needed forward declaration because of 'class UDMSUserWidget' line in struct above
//class UDMSUserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);

//START*********************************************************************************************************
//Using multicast delegates here to broadcast health changes to our HUD class
//No longer needed because of the generic delegate FOnAttributeChangedSignature above. GAS 62.
/*DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewMaxMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStaminaChangedSignature, float, NewStamina);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxStaminaChangedSignature, float, NewMaxStamina);

//AuxAttributes 1-3 delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAuxAttribute1ChangedSignature, float, NewAuxAttribute1);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxAuxAttribute1ChangedSignature, float, NewMaxAuxAttribute1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAuxAttribute2ChangedSignature, float, NewAuxAttribute2);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxAuxAttribute2ChangedSignature, float, NewMaxAuxAttribute2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAuxAttribute3ChangedSignature, float, NewAuxAttribute3);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxAuxAttribute3ChangedSignature, float, NewMaxAuxAttribute3);*/
//END*********************************************************************************************************

//More delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature, FUIWidgetRow, Row);

/**
 * 
 */

UCLASS(BlueprintType, Blueprintable)
class MYTHWICK_API UOverlayWidgetController : public UDMSWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

//Creating OnAttributeChange objects
//START*********************************************************************************************************
	//OnHealthChanged is the delegate itself, signature is the type
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnManaChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnStaminaChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnMaxStaminaChanged;

	//AuxAttributes 1-3 OnChanged objects
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnAuxAttribute1Changed;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnMaxAuxAttribute1Changed;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnAuxAttribute2Changed;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnMaxAuxAttribute2Changed;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnAuxAttribute3Changed;
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeChangedSignature OnMaxAuxAttribute3Changed;
//END*********************************************************************************************************

	UPROPERTY(BlueprintAssignable, Category="GAS|Messages")
	FMessageWidgetRowSignature MessageWidgetRowDelegate;	
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Data")
	TObjectPtr<UDataTable> MessageWidgetDataTable;

//START*********************************************************************************************************
	//Replaced the attribute change callback functions below with lambdas in cpp file. Archived.
	/*void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
	void StaminaChanged(const FOnAttributeChangeData& Data) const;
	void MaxStaminaChanged(const FOnAttributeChangeData& Data) const;

	//AuxAttributes 1-3 function calls
	void AuxAttribute1Changed(const FOnAttributeChangeData& Data) const;
	void MaxAuxAttribute1Changed(const FOnAttributeChangeData& Data) const;
	void AuxAttribute2Changed(const FOnAttributeChangeData& Data) const;
	void MaxAuxAttribute2Changed(const FOnAttributeChangeData& Data) const;
	void AuxAttribute3Changed(const FOnAttributeChangeData& Data) const;
	void MaxAuxAttribute3Changed(const FOnAttributeChangeData& Data) const;*/
//END*********************************************************************************************************

	template<typename T>
	T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag);
};

template <typename T>
T* UOverlayWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
	T* Row = DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));
	return Row;
}
