// Copyright Dark Mango Studios

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/DMSWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

class UAttributeInfo;
struct FDMSAttributeInfo;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FDMSAttributeInfo&, Info);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class MYTHWICK_API UAttributeMenuWidgetController : public UDMSWidgetController
{
	GENERATED_BODY()
public:
	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;
	
protected:

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeInfo> PrimaryAttributeInfo;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeInfo> SecondaryAttributeInfo;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeInfo> VitalAttributeInfo;

private:

	void BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute, const UAttributeInfo* AttributeInfo) const;
	
};
