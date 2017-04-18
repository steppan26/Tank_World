// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no TankAIControllerAttached"))
	}
	else if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("The AITankcontroller %s cannot find the player controller"), *GetPlayerTank()->GetName())
	}
	else
	{
		return;
	}


}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
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
