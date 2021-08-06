// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FPlayer_AI_Ctr.generated.h"

/**
 * 
 */
class AProyect_OrpheusCharacter;
UCLASS()
class PROYECT_ORPHEUS_API AFPlayer_AI_Ctr : public AAIController
{
	GENERATED_BODY()

public:
	AProyect_OrpheusCharacter* possesActor;

	UFUNCTION(BlueprintCallable, Category = "AI Navigation")
		void SetMoveLocation(FVector destination);
protected:
	virtual void OnPossess(APawn* InPawn) override;

	virtual void OnUnPossess() override;
	
};
