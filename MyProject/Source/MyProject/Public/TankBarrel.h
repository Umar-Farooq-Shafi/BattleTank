// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYPROJECT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 max downward speed, and +1 is max up speed movement
	void Elevate(const float&);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSeconds = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegree = 40.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegree = 0.f;
};
