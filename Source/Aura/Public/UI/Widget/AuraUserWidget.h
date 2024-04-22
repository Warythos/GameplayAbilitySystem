// Copyright SOLLOS

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//We should associate setting the widget controller with calling widget controller set.
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	// Whenever we set our widget controller for a given user widget, we're going to want to initialize the visuals.
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
