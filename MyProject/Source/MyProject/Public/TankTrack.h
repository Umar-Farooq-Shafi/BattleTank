// OISI

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank track is used to set maximum driving force,
 * and to apply forces to tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYPROJECT_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Set a throttle b/w -1 and 1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(const float& Throttle);

private:
	// Max force for per track, in NEWTON
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDerivingForce = 400000.f;
};
