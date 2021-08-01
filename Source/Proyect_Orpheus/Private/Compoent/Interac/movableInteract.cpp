// Fill out your copyright notice in the Description page of Project Settings.


#include "Compoent/Interac/movableInteract.h"



void UmovableInteract::BeginPlay()
{

	Super::BeginPlay();

	switch (Type)
	{
	case EMovementType::SimpleDirLinear:
		MovePat.Add(GetOwner()->GetActorLocation());
		MovePat.Add((DirectionVector.GetSafeNormal(0.01f) * TravelDistance) + MovePat[0]);
		break;
	case EMovementType::SimpleActorLinear:

		break;
	
	}
}

void UmovableInteract::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	MoveTarger(DeltaTime);
}

void UmovableInteract::OnPress()
{
}

void UmovableInteract::OnLongPress()
{
}

void UmovableInteract::OnSelectet()
{
}

void UmovableInteract::OnDeSelectet()
{
}

void UmovableInteract::ActorDectroid()
{
}



void UmovableInteract::SimpleMoveCalculation()
{
	
}

void UmovableInteract::MoveTarger(float deltaTime)
{
	if(moving)
	{
		
	}
}
