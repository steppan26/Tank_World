// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	auto PlayerTank = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no TankAIControllerAttached"))
	}
	else if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("The AITankcontroller %s cannot find the player controller"), *PlayerTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The AITankcontroller %s is looking at %s "), *ControlledTank->GetName(), *PlayerTank->GetName())
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
