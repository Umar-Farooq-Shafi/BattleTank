// Fill out your copyright notice in the Description page of Project Settings.

// Default Implementation Source file
#include "TankAIController.h"

// Locals include
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Get player tank
	const auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank ||
		!(FPlatformTime::Seconds() - LastFireTime > 3)) return;

	// Get controlled tank(AI)
	const auto ControlledTank = Cast<ATank>(GetPawn());
	if(!ControlledTank) return;
	
	// Aim towards the player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	// Fire towards the player
	ControlledTank->Fire();
	
	LastFireTime = FPlatformTime::Seconds();
}
