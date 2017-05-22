// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
protected:
	// How close can the AI tank get
	UPROPERTY(EditAnywhere, Category = "Setup") // TODO Consider EditDefaultsOnly
	float AcceptanceRadius = 3000;

	UPROPERTY(EditAnywhere, Category = "Setup")
	bool CanFire = true;

};