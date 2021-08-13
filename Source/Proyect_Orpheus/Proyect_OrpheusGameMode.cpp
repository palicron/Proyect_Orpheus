// Copyright Epic Games, Inc. All Rights Reserved.

#include "Proyect_OrpheusGameMode.h"
#include "Proyect_OrpheusPlayerController.h"
#include "Proyect_OrpheusCharacter.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

AProyect_OrpheusGameMode::AProyect_OrpheusGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AProyect_OrpheusPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Proyect_Orpheus/Player/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AProyect_OrpheusGameMode::BeginPlay()
{
	Super::BeginPlay();

	if(IsValid(InGameWidget))
	{
		CurrentWidget = CreateWidget(GetWorld(), InGameWidget);

		if(CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}
