// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(const float& RelativeSpeed)
{
	// Move the Turret right amount amount this frame
	// Give a max elevation speed, and the frame time
	SetRelativeRotation(
		FRotator(0,
			GetRelativeRotation().Yaw +
			FMath::Clamp<float>(RelativeSpeed, -1, 1) *
			MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds,
			0
		)
	);
}