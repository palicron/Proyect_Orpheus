// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Proyect_OrpheusCharacter.generated.h"

UCLASS(Blueprintable)
class AProyect_OrpheusCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AProyect_OrpheusCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;


	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

private:


	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;
};

