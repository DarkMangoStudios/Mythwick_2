// Copyright Dark Mango Studios


#include "AbilitySystem/Data/AttributeInfo.h"

#include "Animation/AnimAttributes.h"

FDMSAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FDMSAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error,
			TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s]."),
			*AttributeTag.ToString(), *GetNameSafe(this));
	}

	//If nothing is found, return empty FDMSAttributeInfo(). (GAS 89)
	return FDMSAttributeInfo();
}
