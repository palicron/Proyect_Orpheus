// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Compoent/TIntractable.h"
#include "ActivationInterac.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROYECT_ORPHEUS_API UActivationInterac : public UTIntractable
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite,Category="Activation Config")
	bool OneUse = true;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Activation Config")
	bool CanBeUse = true;

	UPROPERTY(BlueprintAssignable)
		FSelectedDelegateEvent OnNotActiveEvent;
	
	virtual void OnPress() override;

	virtual void OnLongPress() override;

	virtual void OnSelectet() override;

	virtual void OnDeSelectet() override;

	virtual void ActorDectroid() override;
	
};
