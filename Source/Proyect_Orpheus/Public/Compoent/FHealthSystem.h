// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FHealthSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthSystemEvent);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROYECT_ORPHEUS_API UFHealthSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFHealthSystem();
	int32 MaxHealth = 100;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int32 CurrentHealth;

	float InvulnerabilityTime = 0.5f;
	
	UPROPERTY(BlueprintAssignable)
		FHealthSystemEvent TakeDmgEvent;

	UPROPERTY(BlueprintAssignable)
		FHealthSystemEvent CureDmgEvent;
	UPROPERTY(BlueprintAssignable)
		FHealthSystemEvent DeathEvent;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	virtual int32 TakeDmg(int32 dmg);

	virtual int32 CureDmg(int32 cure);

	virtual void Death();


};
