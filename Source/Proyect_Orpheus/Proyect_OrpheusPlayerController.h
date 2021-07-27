// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Proyect_OrpheusPlayerController.generated.h"

UCLASS()
class AProyect_OrpheusPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AProyect_OrpheusPlayerController();



protected:
	

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface


	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased(const ETouchIndex::Type FingerIndex, const FVector Location);

	bool SpawnDecale = false;

	bool ValidDestination = false;

};


