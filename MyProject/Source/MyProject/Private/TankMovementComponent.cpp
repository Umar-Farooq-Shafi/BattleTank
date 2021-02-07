// OISI

// Default Implementation Source file
#include "TankMovementComponent.h"

// Locals include
#include "TankTrack.h"

void UTankMovementComponent::IntendMoveForward(const float& Throw)
{
	// Set throttle to move the tank
	if (!LeftTrack || !RightTrack) return;
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);	
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTankToSet, UTankTrack* RightTrackToSet)
{
	if(!LeftTankToSet || !RightTrackToSet) return;

	LeftTrack = LeftTankToSet;
	RightTrack = RightTrackToSet;
}
