// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return GetWorld()->GetFirstPlayerController()->GetPawn() ?
		Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn())
		: nullptr;
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!GetPlayerTank()) return;

	// Aim towards the player
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}
