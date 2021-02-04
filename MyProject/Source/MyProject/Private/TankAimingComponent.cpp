// Fill out your copyright notice in the Description page of Project Settings.

// Default Implementation Source file
#include "TankAimingComponent.h"

// Engine Includes
#include "Kismet/GameplayStatics.h"

// Local includes
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::MoveBarrelTowards(const FVector& AimDirection) const
{
	if (!Barrel || !Turret) return;

	// Work-out difference between current barrel rotation, aimDirection
	const FRotator DeltaRotate = AimDirection.Rotation() - Barrel->GetForwardVector().Rotation();
	Barrel->Elevate(DeltaRotate.Pitch);
	Turret->Rotate(DeltaRotate.Yaw);
}

void UTankAimingComponent::AimAt(const FVector& HitLocation, const float& LaunchSpeed)
{
	if (!Barrel) return;
	
	// Calculating the velocity
	FVector OutLaunchVelocity;
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		Barrel->GetSocketLocation(FName("Projectile")),
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	))
		MoveBarrelTowards(OutLaunchVelocity.GetSafeNormal());
	
	UE_LOG(LogTemp, Warning, TEXT("Aiming at : %s"),
		*OutLaunchVelocity.GetSafeNormal().ToString());
}

// Setter for Barrel property
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if(!BarrelToSet) return;
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if(!TurretToSet) return;
	Turret = TurretToSet;
}

