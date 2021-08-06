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


	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	UFUNCTION(BlueprintCallable)
		void SetCursolDecale(bool correct);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Decale)
		TSubclassOf<ANavigationDecales> DefaultDecale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Decale)
		TSubclassOf<ANavigationDecales> noPathDecale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float baseSpeed = 500.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		int32 baseStrength = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		int32 baseAgility = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		int32 baseIntelligence = 5;
	
	ANavigationDecales* SpawnetTarget;


	UFUNCTION(BlueprintCallable)
	virtual	void OnPosses();

	UFUNCTION(BlueprintCallable)
	virtual	void OnDePosses();

private:

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDecalComponent* CursorToWorld;

	FVector ActorMoVeLocation;


};

