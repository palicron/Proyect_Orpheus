// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyect_Orpheus/Public/Actors/NavigatorDecaleInvalid.h"
#include "TimerManager.h"

ANavigatorDecaleInvalid::ANavigatorDecaleInvalid()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = meshMaterial;
	SetActorRotation(FRotator(0.0f, 00.0f, -90.0));
}



void ANavigatorDecaleInvalid::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(DestroidTimerHandle,this, &ANavigatorDecaleInvalid::destroid, decaleLifeSpawn,false, decaleLifeSpawn);
}

void ANavigatorDecaleInvalid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANavigatorDecaleInvalid::start(AActor* actor)
{
}

void ANavigatorDecaleInvalid::upDate()
{
}

void ANavigatorDecaleInvalid::destroid()
{
	Destroy();
}
