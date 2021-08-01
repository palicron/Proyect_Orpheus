// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Compoent/TIntractable.h"
#include "movableInteract.generated.h"

UENUM(BlueprintType)
enum class EMovementType:uint8
{
	SimpleDirLinear UMETA(DisplayName = "Simple move in direction linear"),
	SimpleActorLinear UMETA(DisplayName = "Simple move to actor linear"),
};
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROYECT_ORPHEUS_API UmovableInteract : public UTIntractable
{
	GENERATED_BODY()


public:

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Move Config")
		AActor* Target;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Move Config")
		bool TwoWays = true;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Move Config")
		EMovementType Type = EMovementType::SimpleDirLinear;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Move path")
		TArray<FVector> MovePat;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Direction config")
		FVector DirectionVector = FVector::ZeroVector;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Direction config")
		float TravelDistance = 0.0f;
	bool moving = false;

	int index = 0;

	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void OnPress() override;

	virtual void OnLongPress() override;

	virtual void OnSelectet() override;

	virtual void OnDeSelectet() override;

	virtual void ActorDectroid() override;

protected:

	virtual void BeginPlay() override;
	//Calcular el vector de direccion
	UFUNCTION(BlueprintCallable,Category="Direction config")
	void SimpleMoveCalculation();
	//Mueve el actor 
	void MoveTarger(float deltaTime);

	bool activateInter = true;
	

};
