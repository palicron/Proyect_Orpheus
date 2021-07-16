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


	ANavigationDecales* SpawnetTarget;

private:

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDecalComponent* CursorToWorld;


};

