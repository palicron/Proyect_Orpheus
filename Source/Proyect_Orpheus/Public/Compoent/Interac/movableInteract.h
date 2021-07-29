// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Compoent/TIntractable.h"
#include "movableInteract.generated.h"

/**
 *
 */
UCLASS()
class PROYECT_ORPHEUS_API UmovableInteract : public UTIntractable
{
	GENERATED_BODY()


public:
	
		virtual void OnPress() override;

		virtual void OnLongPress() override;
	
		virtual void OnSelectet() override;
	
		virtual void OnDeSelectet() override;
	
		virtual void ActorDectroid() override;

};
