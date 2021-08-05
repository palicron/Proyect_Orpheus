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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healh System Config")
	int32 MaxHealth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healh System Config")
		bool bIsAlive = true;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int32 CurrentHealth;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Healh System Config")
	float InvulnerabilityTime = 0.5f;

	float LastTimeDmg = 0.0f;

	float LastTimeHeal = 0.0f;
	
	UPROPERTY(BlueprintAssignable)
		FHealthSystemEvent TakeDmgEvent;

	UPROPERTY(BlueprintAssignable)
		FHealthSystemEvent CureDmgEvent;
	UPROPERTY(BlueprintAssignable)
		FHealthSystemEvent DeathEvent;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Health System Action")
	virtual int32 TakeDmg(int32 dmg);
	UFUNCTION(BlueprintCallable, Category = "Health System Action")
	virtual int32 CureDmg(int32 cure);
	UFUNCTION(BlueprintCallable, Category = "Health System Action")
	virtual void Death();


};
