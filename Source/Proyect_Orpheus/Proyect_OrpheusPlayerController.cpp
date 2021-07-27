// Copyright Epic Games, Inc. All Rights Reserved.

#include "Proyect_OrpheusPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Proyect_OrpheusCharacter.h"
#include "Actors/NavigationDecales.h"
#include "NavigationSystem.h"
#include "Engine/World.h"
#include  "Public\Compoent\TIntractable.h"
AProyect_OrpheusPlayerController::AProyect_OrpheusPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AProyect_OrpheusPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

}

void AProyect_OrpheusPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AProyect_OrpheusPlayerController::OnSetDestinationPressed);
	//InputComponent->BindAction("SetDestination", IE_Released, this, &AProyect_OrpheusPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AProyect_OrpheusPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Released, this, &AProyect_OrpheusPlayerController::OnSetDestinationReleased);

	
	
}



void AProyect_OrpheusPlayerController::MoveToMouseCursor()
{

	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if(Hit.bBlockingHit)
	{
		UTIntractable* cop = Cast<UTIntractable>(Hit.GetActor()->GetComponentByClass(UTIntractable::StaticClass()));
		if (cop)
		{
			cop->OnPress();
		}
		else
		{
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}



}

void AProyect_OrpheusPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);
	ValidDestination = false;
	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);

	}
	if (UAIBlueprintHelperLibrary::GetCurrentPath(this) == nullptr || !ValidDestination)
	{
		if (AProyect_OrpheusCharacter* pawn = Cast<AProyect_OrpheusCharacter>(GetPawn()))
		{

			pawn->SetCursolDecale(false);

		}
	}
	else
	{
		if (AProyect_OrpheusCharacter* pawn = Cast<AProyect_OrpheusCharacter>(GetPawn()))
		{

			pawn->SetCursolDecale(true);

		}
	}
}

void AProyect_OrpheusPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());
		FVector newpos = FVector::ZeroVector;
		ValidDestination = UNavigationSystemV1::K2_GetRandomLocationInNavigableRadius(GetWorld(), DestLocation, newpos, 0.0f);

		
		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 100.0f) && ValidDestination)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);

		}

	}
}

void AProyect_OrpheusPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	ValidDestination = false;
	MoveToMouseCursor();


	if (UAIBlueprintHelperLibrary::GetCurrentPath(this) == nullptr || !ValidDestination)
	{
		if (AProyect_OrpheusCharacter* pawn = Cast<AProyect_OrpheusCharacter>(GetPawn()))
		{

			pawn->SetCursolDecale(false);

		}
	}
	else
	{
		if (AProyect_OrpheusCharacter* pawn = Cast<AProyect_OrpheusCharacter>(GetPawn()))
		{

			pawn->SetCursolDecale(true);

		}
	}

}

void AProyect_OrpheusPlayerController::OnSetDestinationReleased(const ETouchIndex::Type FingerIndex, const FVector Location)
{

	UE_LOG(LogTemp, Warning, TEXT("Relesee"));



}



