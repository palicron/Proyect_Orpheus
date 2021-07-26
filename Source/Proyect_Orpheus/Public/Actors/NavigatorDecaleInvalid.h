// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/NavigationDecales.h"
#include "NavigatorDecaleInvalid.generated.h"

/**
 *
 */
UCLASS()
class PROYECT_ORPHEUS_API ANavigatorDecaleInvalid : public ANavigationDecales
{
	GENERATED_BODY()


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle DestroidTimerHandle;

public:
	ANavigatorDecaleInvalid();
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	virtual void start(AActor* actor=nullptr) override;

	virtual void upDate() override;

	virtual void destroid() override;

	
};
