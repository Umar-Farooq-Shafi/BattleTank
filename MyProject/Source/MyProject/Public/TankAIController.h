// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declaration
class ATank;

/**
 * 
 */
UCLASS()
class MYPROJECT_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	// Override the parent function
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaSeconds) override;

private:
	double LastFireTime{ 0 };
};
