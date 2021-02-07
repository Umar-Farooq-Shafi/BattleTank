// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrel;
class UTankTurret;

// Hold's Barrel property and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Moving the barrel towards to aim
	void MoveBarrelTowards(const FVector&) const;
	
	void AimAt(const FVector&, const float&) const;

	void SetBarrelReference(UTankBarrel*);
	
	void SetTurretReference(UTankTurret*);

private:
	UTankBarrel* Barrel{ nullptr };
	UTankTurret* Turret{ nullptr };
};
