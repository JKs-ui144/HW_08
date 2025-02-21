// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"



// Sets default values
AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticComp->SetupAttachment(SceneRoot);
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Potion_A.SM_Potion_A"));
	if (MeshAsset.Succeeded())
	{
		StaticComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Game/Resources/Materials/M_Potion_HP.M_Potion_HP"));
	if (Material.Succeeded())
	{
		StaticComp->SetMaterial(0, Material.Object);
	}
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
}



void AItem::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	//						 pitch,  yaw,  roll
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(2.0f));

	OnItemPickUp();
	// 트랜스폼을 한번에 관리하고싶을때.
	/*FVector NewLocation(300.0f, 200.0f, 100.0f);
	FRotator NewRotation(0.0f, 90.0f, 0.0f);
	FVector NewScale(2.0f);

	FTransform NewTransform(NewRotation, NewLocation, NewScale);
	SetActorTransform(NewTransform);*/
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
	// 유저의 사양 차이마다 프레임이 다른 이유로 델타타임을 곱해준다(프레임 독립적인 계산)
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

void AItem::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);	// ZeroVector(원점을 가리킴)
}

float AItem::GetRotationSpeed() const
{
	return RotationSpeed;
}



// 탄생
// 생성자 - 메모리에 생김(딱 한번만 호출됨)
// PostInitializeComponents() - 컴포넌트가 완성된 직후 호출. 컴포넌트끼리 데이터 주고받기, 상호작용
// BeginPlay() - 배치(Spawn) 직후
// 
// 활동
// Tick(float DeltaTime) - 매 프레임마다 호출
// 
// 소멸
// Destroyed() - 액터가 삭제되기 직전에 호출
// EndPlay() - 게임 종료, 파괴(Destroyed()), 레벨 전환 시 호출