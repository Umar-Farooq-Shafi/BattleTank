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
	// Get controlled tank(AI)
	const auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	const auto ControlledTank = Cast<ATank>(GetPawn());
	if (!PlayerTank && !ControlledTank) return;

	// Aim towards the player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	// Fire towards the player
	ControlledTank->Fire();
}
