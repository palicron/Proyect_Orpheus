// Fill out your copyright notice in the Description page of Project Settings.


#include "FPlayer_AI_Ctr.h"
#include "Proyect_Orpheus/Proyect_OrpheusCharacter.h"

void AFPlayer_AI_Ctr::SetMoveLocation(FVector destination)
{
	MoveToLocation(destination);
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
