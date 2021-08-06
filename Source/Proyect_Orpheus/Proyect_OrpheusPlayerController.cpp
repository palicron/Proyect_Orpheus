// Copyright Epic Games, Inc. All Rights Reserved.

#include "Proyect_OrpheusPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Proyect_OrpheusCharacter.h"
#include "Actors/NavigationDecales.h"
#include "NavigationSystem.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Public/FPlayer_AI_Ctr.h"
#include  "Public\Compoent\TIntractable.h"
AProyect_OrpheusPlayerController::AProyect_OrpheusPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	bAutoManageActiveCameraTarget = false;

	
}


inline void AProyect_OrpheusPlayerController::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> AllCharacters;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AProyect_OrpheusCharacter::StaticClass(), AllCharacters);
	if(AllCharacters.Num()>0)
	{
		CurrentCharacter = Cast<AProyect_OrpheusCharacter>(AllCharacters[0]);
		if(CurrentCharacter)
		{
			CurrentCtr = Cast<AFPlayer_AI_Ctr>(CurrentCharacter->GetController());
			if(CurrentCtr)
			{
				UE_LOG(LogTemp, Warning, TEXT("El nombre del actor es %s"), *CurrentCharacter->GetName());
			}
			else
			{

				UE_LOG(LogTemp, Warning, TEXT("No hay AI_CTR"));
			}
		}
	}
}

void AProyect_OrpheusPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

  if(bClicked)
  {
		clickTimer += DeltaTime;
	
		if(clickTimer>=longClickTime)
		{
			if(!bLongClink)
			{
				LongPress();
				bLongClink = true;
			}
		}
	}
	if(MovingToActor)
	{
		
		if(FVector::Dist(GetPawn()->GetActorLocation(), CurrenInteractuveGoal)<= StopingDistance+100.0f)
		{
			MovingToActor = false;
			if(selectedInteractive)
			{
				selectedInteractive->OnSelectet();
			}
		}
	}

}

void AProyect_OrpheusPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	//InputComponent->BindAction("SetDestination", IE_Pressed, this, &AProyect_OrpheusPlayerController::OnSetDestinationPressed);
	//InputComponent->BindAction("SetDestination", IE_Released, this, &AProyect_OrpheusPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AProyect_OrpheusPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Released, this, &AProyect_OrpheusPlayerController::OnRelaseTouch);

	
	
}



void AProyect_OrpheusPlayerController::MoveToMouseCursor()
{
	//TODO Actulizar con el mouse tambine cunado halla tiempo toda funcin en touch
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
	clickDestination = ScreenSpaceLocation;
	ValidDestination = false;
	// Trace to see what is under the touch location
	
	GetHitResultAtScreenPosition(clickDestination, CurrentClickTraceChannel, true, clickHitResult);
	if (clickHitResult.bBlockingHit)
	{

		

		AProyect_OrpheusCharacter* pj = Cast<AProyect_OrpheusCharacter>(clickHitResult.GetActor());

		if(pj)
		{
			if(pj == GetPawn())
			{
				UE_LOG(LogTemp, Warning, TEXT("Character %s"), *clickHitResult.GetActor()->GetName());
			}
			else
			{
				Cast<AProyect_OrpheusCharacter>(GetPawn())->OnDePosses();
				UnPossess();
			
				Possess(pj);
				
			}
	
		}
		else
		{
			UTIntractable* inter = Cast<UTIntractable>(clickHitResult.GetActor()->GetComponentByClass(UTIntractable::StaticClass()));

			SelectedInteractive(inter);
			//TODO poner el decal cuando se precuiona un interactive
			if (selectedInteractive)
			{
				bClicked = true;

			}
			else
			{
				SetNewMoveDestination(clickHitResult.ImpactPoint);

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

				MovingToActor = false;
			}
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
		if ((Distance > StopingDistance) && ValidDestination)
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

void AProyect_OrpheusPlayerController::OnRelaseTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{

	//UE_LOG(LogTemp, Warning, TEXT("Relesee"));

	if(clickTimer<longClickTime && selectedInteractive)
	{
		selectedInteractive->OnPress();
		if(selectedInteractive->NavigationPoint!=FVector::ZeroVector)
		{
			CurrenInteractuveGoal = selectedInteractive->NavigationPoint;
		
		}
		else
		{
			CurrenInteractuveGoal = selectedInteractive->GetOwner()->GetActorLocation();
		
		}
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CurrenInteractuveGoal);
		MovingToActor = true;
	}

	
	 bLongClink = false;
	 bClicked = false;
	 clickTimer = 0;
	

}

void AProyect_OrpheusPlayerController::LongPress()
{
	if (selectedInteractive)
	{
		selectedInteractive->OnLongPress();
	}
}

void AProyect_OrpheusPlayerController::SelectedInteractive(UTIntractable* inter)
{
	//TODO Diferenciar si el pj tine que ir ahsta el elemnto ineteractivo para activarlo con ONSelect
	if(selectedInteractive)
	{
		if(inter)
		{
			
			if(inter->GetOwner() != selectedInteractive->GetOwner())
			{
				selectedInteractive->OnDeSelectet();
				selectedInteractive = inter;
				//selectedInteractive->OnSelectet();
				
			}
			else
			{
				//selectedInteractive->OnSelectet();
			}
		}
		else
		{
			selectedInteractive->OnDeSelectet();
			selectedInteractive = inter;
		}
	}
	else
	{
		selectedInteractive = inter;
		if(selectedInteractive)
		{
			//selectedInteractive->OnSelectet();
		}
	}
}

void AProyect_OrpheusPlayerController::MoveToInteract(FVector target)
{
}



