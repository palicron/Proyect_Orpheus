// Copyright Epic Games, Inc. All Rights Reserved.

#include "Proyect_OrpheusCharacter.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/DecalActor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Proyect_Orpheus/Private/Actors/NavigationDecales.h"
#include "Public/FPlayer_AI_Ctr.h"
#include "Kismet/GameplayStatics.h"
AProyect_OrpheusCharacter::AProyect_OrpheusCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->MaxWalkSpeed = baseSpeed;
	
	// Create a decal in the world to show the cursor's location
	DecaleCHild = CreateDefaultSubobject<UChildActorComponent>(TEXT("Selected Decale"));
	DecaleCHild->SetupAttachment(RootComponent);
	if(SelectDecale)
	{
		DecaleCHild->SetChildActorClass(SelectDecale);

	}
	DecaleCHild->SetRelativeRotation(FRotator(-90.f, 0.0f, 0.0f));
	DecaleCHild->SetRelativeLocation(FVector(0.0,0.0,-88.f));
	DecaleCHild->SetRelativeScale3D(FVector(1.f));
	DecaleCHild->SetVisibility(false);

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AProyect_OrpheusCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void AProyect_OrpheusCharacter::SetCursolDecale(bool correct)
{
	//TODO Optimizar esto
	APlayerController* PC =  UGameplayStatics::GetPlayerController(GetWorld(), 0);
	//TODO Cambiar el decale por un actor normal y ocriente guardar referecia apra destruccion
	if (PC)
	{
		FHitResult TraceHitResult;
		PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
		FVector CursorFV = TraceHitResult.ImpactPoint;
		CursorFV.Z += 2.0f;
		FRotator CursorR = CursorFV.Rotation();
		FActorSpawnParameters SpawnParams;
		if (DefaultDecale && noPathDecale)
		{
			if(SpawnetTarget==nullptr)
			{
				if(correct)
				{
					SpawnetTarget = GetWorld()->SpawnActor<ANavigationDecales>(DefaultDecale, CursorFV, FRotator::ZeroRotator, SpawnParams);
					if (SpawnetTarget)
					{
						SpawnetTarget->start(this);
					}
				}
				else
				{
					 GetWorld()->SpawnActor<ANavigationDecales>(noPathDecale, CursorFV, FRotator(-90, 0, 0), SpawnParams);
				}
			}
			else
			{
				if(correct)
				{
					SpawnetTarget->destroid();
					SpawnetTarget = GetWorld()->SpawnActor<ANavigationDecales>(DefaultDecale, CursorFV, FRotator::ZeroRotator, SpawnParams);
					if(SpawnetTarget)
					{
						SpawnetTarget->start(this);
					}
					
				}
				else
				{
					GetWorld()->SpawnActor<ANavigationDecales>(noPathDecale, CursorFV, FRotator(-90,0,0), SpawnParams);
				}
		
			}
		}

		
	}

}

void AProyect_OrpheusCharacter::OnSelected()
{
	Selected = true;

	DecaleCHild->SetVisibility(true);
	
	if(SpawnetTarget)
	{
		
		SpawnetTarget->ChangeMaterial();
	}
}

void AProyect_OrpheusCharacter::OnDeselected()
{
	Selected = false;
	DecaleCHild->SetVisibility(false);
	if(SpawnetTarget)
	{
		
		SpawnetTarget->ChangeMaterial();
	}
}
