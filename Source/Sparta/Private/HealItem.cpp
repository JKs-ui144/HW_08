// Fill out your copyright notice in the Description page of Project Settings.


#include "HealItem.h"
#include "SpartaCharacter.h"
AHealItem::AHealItem()
{
	HealAmount = 20;
	ItemType = "HealItem";
}

void AHealItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);

	if (Activator && Activator->ActorHasTag(TEXT("Player")))
	{
		if (ASpartaCharacter* PlayerCharacter = Cast<ASpartaCharacter>(Activator))
		{
			PlayerCharacter->AddHP(HealAmount);
		}
		DestroyItem();
	}
}
