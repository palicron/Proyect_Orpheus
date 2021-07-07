// Fill out your copyright notice in the Description page of Project Settings.


//#include "C:\Users\ELGRA\Documents\Unreal_Proyects\Proyect_Orpheus\Source\Proyect_Orpheus\Camera\GameCamera.h"
#include "GameCamera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"

// Sets default values
AGameCamera::AGameCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	
	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 3500.0;
	CameraBoom->SetRelativeRotation(FRotator(-45.f, -45.0, 0.0 ));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level
	CameraBoom->TargetOffset = FVector(-1000, 950, 0);
	
	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	TopDownCameraComponent->SetRelativeRotation(  FRotator(10.f,0.f,0.f));
	TopDownCameraComponent->FieldOfView = 45;
	TopDownCameraComponent->AspectRatio = 1.778646f;

}

// Called when the game starts or when spawned
void AGameCamera::BeginPlay()
{
	Super::BeginPlay();

	if(bStarCamera)
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if(PlayerController)
		{
			PlayerController->SetViewTargetWithBlend(this, 0.0f);
		}
		
	}
	
}

// Called every frame
void AGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameCamera::SetThisCamera(AActor* newTarget, float blendTime, EViewTargetBlendFunction transiton, float blenExp,
	bool DestroidThis)
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		PlayerController->SetViewTargetWithBlend(newTarget, blendTime, transiton, blenExp);

		if(DestroidThis)
		{
			this->Destroy();
		}
	}
}



