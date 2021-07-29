// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Proyect_OrpheusPlayerController.generated.h"
class UTIntractable;
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
	void OnRelaseTouch(const ETouchIndex::Type FingerIndex, const FVector Location);

	void LongPress();

	void SelectedInteractive(UTIntractable* inter);

	bool SpawnDecale = false;

	bool ValidDestination = false;

	 UTIntractable* selectedInteractive = nullptr;
	FVector2D clickDestination;
	bool bLongClink = false;
	bool bClicked = false;
	float longClickTime = 2.0f;
	float clickTimer = 0.0f;
	FHitResult clickHitResult;
};


