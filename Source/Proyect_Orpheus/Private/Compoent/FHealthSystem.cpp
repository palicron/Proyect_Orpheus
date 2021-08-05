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
	if(GetWorld()->GetTimeSeconds()-LastTimeDmg>= InvulnerabilityTime && bIsAlive)
	{
		CurrentHealth = FMath::Clamp(CurrentHealth - dmg, 0, MaxHealth);
		TakeDmgEvent.Broadcast();
		if(CurrentHealth<=0)
		{
			Death();
		}
	}
	return CurrentHealth;
}

int32 UFHealthSystem::CureDmg(int32 cure)
{
	if (GetWorld()->GetTimeSeconds() - LastTimeHeal >= InvulnerabilityTime)
	{
		CurrentHealth = FMath::Clamp(CurrentHealth + cure, 0, MaxHealth);
		CureDmgEvent.Broadcast();
	}
	return CurrentHealth;
}

void UFHealthSystem::Death()
{
	bIsAlive = false;
	DeathEvent.Broadcast();
}

