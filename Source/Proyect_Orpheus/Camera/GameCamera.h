// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameCamera.generated.h"


USTRUCT(BlueprintType)
struct FCameraConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Congifuration")
		FVector CenterPos = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Congifuration")
		FRotator CenterRotation = FRotator::ZeroRotator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Congifuration")
		FRotator CameraRelativeRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Congifuration")
		float CameraArmLenght = 3500.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Congifuration")
		float fileOfview = 45.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Congifuration")
		float CameraRation = 1.778646f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Congifuration")
		FVector CameraOFfset = FVector(-1000.0f, 950.f, 0.0f);
};

UCLASS()
class PROYECT_ORPHEUS_API AGameCamera : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGameCamera();


	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		bool bStarCamera = false;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		bool bMoving = false;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = CameraMove, meta = (AllowPrivateAccess = "true"))
		bool bRotating = false;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = CameraMove, meta = (AllowPrivateAccess = "true"))
		FVector CameraTarget;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = CameraMove, meta = (AllowPrivateAccess = "true"))
		FRotator CameraRTarget;
	UFUNCTION()
		void MoveActorCamera(float deltaTime);
	UFUNCTION()
		void RotateActorCamera(float deltaTime);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "CameraUtiles")
		void SetThisCamera(AActor* newTarget, float blendTime, EViewTargetBlendFunction transiton, float blenExp, bool DestroidThis = false);

	UFUNCTION(BlueprintCallable, Category = "CameraUtiles")
		void MoveCameraInDir(FVector Dir, float speed, float moveTime = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "CameraUtiles")
		void MoveCameraToActor(AActor* target, float speed);

	UFUNCTION(BlueprintCallable, Category = "CameraUtiles")
		void RotateCamera(FRotator targetRot, float speed, bool ConterClockwise = false);

	UFUNCTION(BlueprintCallable, Category = "CameraUtiles")
		void ResetCameraToStarPosition();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		FCameraConfig StartConfiguration;
};


