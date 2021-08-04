// Fill out your copyright notice in the Description page of Project Settings.


#include "Compoent/FHealthSystem.h"

// Sets default values for this component's properties
UFHealthSystem::UFHealthSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	CurrentHealth = MaxHealth;

	// ...
}


// Called when the game starts
void UFHealthSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFHealthSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UFHealthSystem::TakeDmg(int32 dmg)
{
	return 0;
}

int32 UFHealthSystem::CureDmg(int32 cure)
{
	return 0;
}

void UFHealthSystem::Death()
{
}

