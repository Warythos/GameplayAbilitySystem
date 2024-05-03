// Copyright SOLLOS


#include "AbilitySystem/AuraAbilitySystemComponent.h"

// We have a callback but we want to bind this to delegate back in AbilitySystemComponent.h  // OnGameplayEffectAppliedDelegateToSelf
void UAuraAbilitySystemComponent::SetAbilityActorInfo()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied); // binding function to delegate
}


void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	// Gameplay Tag that can be broadcast from whatever effect applied. IF that effect carries that tag, we can broadcast that to the widget controller
	// Which can brodcast it to the HUD. So we need to find out what gameplay tags the effect has.

	// We need a delegate to broadcast gampelay tags to Widget
	// Broadcasting: AbilitySystemComponent -> WidgetController -> HUD because the dependencies is the other way around.

	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);

}
