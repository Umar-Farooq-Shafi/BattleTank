// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// overriding the BeginPlay function
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	// Get the player tank controller
	ATank* GetControlledTank() const;

	/// Start the tank moving the barrel so that
	/// a shot would hit crosshair intersects world
	void AimTowardsCrosshair() const;

	// Boolean if pawn hit to something
	bool GetSightRayHitLocation(FVector& HitLocation) const;

private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
	double LineTraceRange = 1000000;
};
