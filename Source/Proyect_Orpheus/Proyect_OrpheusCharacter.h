// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Proyect_OrpheusCharacter.generated.h"

class ANavigationDecales;
UCLASS(Blueprintable)
class AProyect_OrpheusCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AProyect_OrpheusCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;




	UFUNCTION(BlueprintCallable)
		void SetCursolDecale(bool correct);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Decale)
		TSubclassOf<ANavigationDecales> DefaultDecale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Decale)
		TSubclassOf<ANavigationDecales> noPathDecale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Decale)
		TSubclassOf<ANavigationDecales> SelectDecale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float baseSpeed = 350.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		int32 baseStrength = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		int32 baseAgility = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		int32 baseIntelligence = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		bool Selected=false;
	
	ANavigationDecales* SpawnetTarget;


	UFUNCTION(BlueprintCallable)
	virtual	void OnSelected();

	UFUNCTION(BlueprintCallable)
	virtual	void OnDeselected();
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Stats")
		UChildActorComponent* DecaleCHild;
private:

	FVector ActorMoVeLocation;
	



	


};

