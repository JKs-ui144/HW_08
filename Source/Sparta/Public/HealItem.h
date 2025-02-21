// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "HealItem.generated.h"

/**
 * 
 */
UCLASS()
class SPARTA_API AHealItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	AHealItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealAmount")
	int32 HealAmount;

	virtual void ActivateItem(AActor* Activator) override;


};
