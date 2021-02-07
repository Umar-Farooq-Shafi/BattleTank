// OISI


#include "TankTrack.h"

void UTankTrack::SetThrottle(const float& Throttle)
{
	Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent())
		->AddForceAtLocation(
			GetForwardVector() * Throttle * TrackMaxDerivingForce,
			GetComponentLocation()
		);
}
