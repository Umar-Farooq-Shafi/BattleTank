// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

// Implementation for Get Controller
ATank* ATankPlayerController::GetControlledTank() const
{
	// Casting to ATank
	return Cast<ATank>(GetPawn());
}

// Implementation for aiming the cross over
void ATankPlayerController::AimTowardsCrosshair() const
{
	if(!GetControlledTank()) return;

	/// OUT param for hit location
	/// Has some "side-effect", is going to ray-cast (line trace)
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
		GetControlledTank()->AimAt(HitLocation);
}

// Get world location for line trace through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	/// Find the crosshair position
	/// Calculating the screen location
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	const FVector2D ScreenLocation(
		ViewportSizeX * CrossHairXLocation,
		ViewportSizeY * CrossHairYLocation
	);

	/// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection, LookLocation;
	if(!DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		LookLocation,
		LookDirection
	))
		return false;

	/// Line-tracing along that direction and see what hit
	struct FHitResult Hit;
	const auto Start = PlayerCameraManager->GetCameraLocation(),
		End = Start + (LookDirection * LineTraceRange);
	if (!GetWorld()->LineTraceSingleByChannel(
		Hit,
		Start,
		End,
		ECollisionChannel::ECC_Visibility
	))
	{
		HitLocation = FVector(0);
		return false;
	}

	HitLocation = Hit.Location;
	return true;
}

// Call when begin to play
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

// Tick for every frame
void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

