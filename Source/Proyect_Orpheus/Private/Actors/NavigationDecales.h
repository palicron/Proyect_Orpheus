// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavigationDecales.generated.h"

UCLASS()
class ANavigationDecales : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANavigationDecales();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="Decale")
	float decaleLifeSpawn = 1.0f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
		UStaticMeshComponent* meshMaterial;

	UFUNCTION(BlueprintCallable, Category = "DecalesNavigations")
		virtual void start(AActor* actor);
	UFUNCTION(BlueprintCallable, Category = "DecalesNavigations")
		virtual void upDate() ;
	UFUNCTION(BlueprintCallable, Category = "DecalesNavigations")
		virtual void destroid();

	UFUNCTION(BlueprintImplementableEvent)
		void ChangeMaterial();

};


