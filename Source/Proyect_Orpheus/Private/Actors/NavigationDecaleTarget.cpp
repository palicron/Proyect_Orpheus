// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyect_Orpheus/Public/Actors/NavigationDecaleTarget.h"

ANavigationDecaleTarget::ANavigationDecaleTarget()
{
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void ANavigationDecaleTarget::BeginPlay()
{
	Super::BeginPlay();

}
void ANavigationDecaleTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}




void ANavigationDecaleTarget::start(AActor* actor)
{
	owner = actor;
}

void ANavigationDecaleTarget::upDate()
{
	if(owner)
	{
		if(FVector::Dist(owner->GetActorLocation(),GetActorLocation())<180)
		{
			destroid();
		}
	}
}

void ANavigationDecaleTarget::destroid()
{
	owner = nullptr;
	Destroy();
}

