// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/NavigationDecales.h"

// Sets default values
ANavigationDecales::ANavigationDecales()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshMaterial = CreateDefaultSubobject<UStaticMeshComponent>(FName("PlaneMesh"));
	meshMaterial->SetRelativeRotation(FRotator(0.0f, 00.0f, -90.0));
	meshMaterial->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ANavigationDecales::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ANavigationDecales::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	upDate();
	
}

void ANavigationDecales::start()
{

}

void ANavigationDecales::upDate()
{

}
void ANavigationDecales::destroid()
{
	Destroy();
}


