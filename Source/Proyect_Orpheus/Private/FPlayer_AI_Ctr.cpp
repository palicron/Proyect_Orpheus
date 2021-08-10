// Fill out your copyright notice in the Description page of Project Settings.


#include "FPlayer_AI_Ctr.h"

#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Compoent/TIntractable.h"
#include "Proyect_Orpheus/Proyect_OrpheusCharacter.h"

void AFPlayer_AI_Ctr::SetMoveLocation(FVector destination)
{
	//MoveToLocation(destination);

	currentInteract = nullptr;
	MovingToActor = false;
	if (possesActor)
	{
		float const Distance = FVector::Dist(destination, possesActor->GetActorLocation());
		FVector newpos = FVector::ZeroVector;
		ValidDestination = UNavigationSystemV1::K2_GetRandomLocationInNavigableRadius(GetWorld(), destination, newpos, 0.0f);



		if ((Distance > StopingDistance) && ValidDestination)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, destination);

		}
	}


	if (UAIBlueprintHelperLibrary::GetCurrentPath(this) == nullptr || !ValidDestination)
	{


		if (possesActor)
		{

			possesActor->SetCursolDecale(false);

		}
	}
	else
	{
		if (possesActor)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Entro para el decale"));
			possesActor->SetCursolDecale(true);

		}
	}

	
}

void AFPlayer_AI_Ctr::setMoveToInteractive(UTIntractable* interactive)
{
	if(interactive)
	{
		currentInteract = interactive;

		currentInteract->OnPress();
		if (currentInteract->NavigationPoint != FVector::ZeroVector)
		{
			CurrenInteractuveGoal = currentInteract->NavigationPoint;

		}
		else
		{
			CurrenInteractuveGoal = currentInteract->GetOwner()->GetActorLocation();

		}
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CurrenInteractuveGoal);
		MovingToActor = true;
		
	}
}

void AFPlayer_AI_Ctr::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (MovingToActor && currentInteract)
	{

		if (FVector::Dist(possesActor->GetActorLocation(), CurrenInteractuveGoal) <= StopingDistance + 100.0f)
		{
			MovingToActor = false;

				currentInteract->OnSelectet();			
			
		}
	}
}

void AFPlayer_AI_Ctr::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	possesActor = Cast<AProyect_OrpheusCharacter>(GetPawn());



}

void AFPlayer_AI_Ctr::OnUnPossess()
{
	Super::OnUnPossess();
}
