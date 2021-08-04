// Fill out your copyright notice in the Description page of Project Settings.


#include "Compoent/Interac/ActivationInterac.h"

void UActivationInterac::OnPress()
{
}

void UActivationInterac::OnLongPress()
{
}

void UActivationInterac::OnSelectet()
{
	if(CanBeUse)
	{
		InSelectEvent.Broadcast();
		if(OneUse)
		{
			CanBeUse = false;
		}
	}
	else
	{
		OnNotActiveEvent.Broadcast();
	}
	
}

void UActivationInterac::OnDeSelectet()
{
	InDeSelectEvent.Broadcast();
}

void UActivationInterac::ActorDectroid()
{
}
