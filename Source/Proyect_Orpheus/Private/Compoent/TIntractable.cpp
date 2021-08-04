// Fill out your copyright notice in the Description page of Project Settings.


#include "Compoent/TIntractable.h"

// Sets default values for this component's properties
UTIntractable::UTIntractable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	// ...
}


// Called when the game starts
void UTIntractable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTIntractable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTIntractable::OnPress()
{
	UE_LOG(LogTemp, Warning, TEXT("Press"));
}

void UTIntractable::OnLongPress()
{
	UE_LOG(LogTemp, Warning, TEXT("Long press"));
}

void UTIntractable::OnSelectet()
{
	UE_LOG(LogTemp, Warning, TEXT("Select"));
}

void UTIntractable::OnDeSelectet()
{
	UE_LOG(LogTemp, Warning, TEXT("DeSelect"));
}

void UTIntractable::ActorDectroid()
{
	UE_LOG(LogTemp, Warning, TEXT("Destroid"));
}

void UTIntractable::SetNavigationPoint(FVector point)
{
	NavigationPoint = point;
}

