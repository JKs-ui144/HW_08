// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"



UCLASS()
class SPARTA_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	UPROPERTY(VIsibleAnyWhere, BluePrintReadOnly, Category = "Itme|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Itme|Components")
	UStaticMeshComponent* StaticComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Itme|Components")
	float RotationSpeed;


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Itme|Actions")
	void ResetActorPosition();
	
	// 리턴값만 반환
	UFUNCTION(BlueprintPure)
	float GetRotationSpeed() const;

	// 구현은 블루프린트에서 하고 C++로 불러오는 인자
	UFUNCTION(BlueprintImplementableEvent, Category = "Itme|Components")
	void OnItemPickUp();
};
