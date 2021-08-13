// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Proyect_OrpheusGameMode.generated.h"
class UUserWidget;
UCLASS(minimalapi)
class AProyect_OrpheusGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AProyect_OrpheusGameMode();

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI component")
		TSubclassOf<UUserWidget> InGameWidget;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "UI component")
		UUserWidget* CurrentWidget;


	virtual void BeginPlay() override;
};



