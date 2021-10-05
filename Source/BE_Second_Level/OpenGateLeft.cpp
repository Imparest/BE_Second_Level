// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenGateLeft.h"

// Sets default values for this component's properties
UOpenGateLeft::UOpenGateLeft()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenGateLeft::BeginPlay()
{
	Super::BeginPlay();

	// ...

	TargetYaw = GetOwner()->GetActorRotation().Yaw + OpenAngle;
}


// Called every frame
void UOpenGateLeft::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	OpenGate(DeltaTime);
}

void UOpenGateLeft::OpenGate(float DeltaTime) {

	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator OpenGate{ 0.f, 0.f, 0.f };
	OpenGate.Yaw = FMath::FInterpConstantTo(CurrentYaw, TargetYaw, DeltaTime, OpenSpeed);
	GetOwner()->SetActorRotation(OpenGate);
}