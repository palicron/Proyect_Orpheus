// Fill out your copyright notice in the Description page of Project Settings.


#include "Compoent/Interac/movableInteract.h"



void UmovableInteract::BeginPlay()
{

	Super::BeginPlay();

	switch (Type)
	{
	case EMovementType::SimpleDirLinear:
		MovePat.Add(Target->GetActorLocation());
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
	//TODO incir movimiento al target
	if (!activateInter)
		return;
	//TODO activar target
	if(!moving || TwoWays )
	{
		index++;
		if(index>MovePat.Num()-1)
		{
			index = 0;
		}

		moving = true;
	}
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
		Target->SetActorLocation(FMath::VInterpTo(Target->GetActorLocation(), MovePat[index], deltaTime,5));
		if(FVector::Dist(Target->GetActorLocation(),MovePat[index])<=100.0f)
		{
			
			moving = false;

			if(!TwoWays)
			{
				activateInter = false;
			}
		}
	}
}
