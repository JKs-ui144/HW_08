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
	// Ʈ�������� �ѹ��� �����ϰ������.
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
	// ������ ��� ���̸��� �������� �ٸ� ������ ��ŸŸ���� �����ش�(������ �������� ���)
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

void AItem::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);	// ZeroVector(������ ����Ŵ)
}

float AItem::GetRotationSpeed() const
{
	return RotationSpeed;
}



// ź��
// ������ - �޸𸮿� ����(�� �ѹ��� ȣ���)
// PostInitializeComponents() - ������Ʈ�� �ϼ��� ���� ȣ��. ������Ʈ���� ������ �ְ�ޱ�, ��ȣ�ۿ�
// BeginPlay() - ��ġ(Spawn) ����
// 
// Ȱ��
// Tick(float DeltaTime) - �� �����Ӹ��� ȣ��
// 
// �Ҹ�
// Destroyed() - ���Ͱ� �����Ǳ� ������ ȣ��
// EndPlay() - ���� ����, �ı�(Destroyed()), ���� ��ȯ �� ȣ��