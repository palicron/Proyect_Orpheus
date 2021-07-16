// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/NavigationDecales.h"
#include "NavigationDecaleTarget.generated.h"

/**
 * 
 */
UCLASS()
class PROYECT_ORPHEUS_API ANavigationDecaleTarget : public ANavigationDecales
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ANavigationDecaleTarget();
	
	virtual void Tick(float DeltaTime) override;
	

		virtual void start() override;
	
		virtual void upDate() override;
	
		virtual void destroid() override;
	
};

