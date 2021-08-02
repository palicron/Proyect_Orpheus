// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TIntractable.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSelectedDelegateEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROYECT_ORPHEUS_API UTIntractable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTIntractable();
	

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	virtual void OnPress();
	UFUNCTION(BlueprintCallable)
	virtual void OnLongPress();
	UFUNCTION(BlueprintCallable)
	virtual void OnSelectet();
	UFUNCTION(BlueprintCallable)
	virtual void OnDeSelectet();
	UFUNCTION(BlueprintCallable)
	virtual void ActorDectroid();
	UFUNCTION(BlueprintCallable)
	virtual void SetNavigationPoint(FVector point);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector NavigationPoint = FVector::ZeroVector;

	UPROPERTY(BlueprintAssignable)
	FSelectedDelegateEvent InSelectEvent;
	UPROPERTY(BlueprintAssignable)
	FSelectedDelegateEvent InDeSelectEvent;
		
};
