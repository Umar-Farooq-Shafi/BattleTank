// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(const float& RelativeSpeed)
{
	// Move the Barrel right amount amount this frame
	// Give a max elevation speed, and the frame time
	SetRelativeRotation(
		FRotator(
			FMath::Clamp<float>(
				GetRelativeRotation().Pitch + 
					FMath::Clamp<float>(RelativeSpeed, -1, 1) * 
					MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds,
				MinElevationDegree,
				MaxElevationDegree
				),
			0,
			0
		)
	);
}
