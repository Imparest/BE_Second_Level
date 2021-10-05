// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "OpenGateLeft.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BE_SECOND_LEVEL_API UOpenGateLeft : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenGateLeft();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenGate(float DeltaTime);
	void CloseGate(float DeltaTime);

private:
	UPROPERTY(EditAnywhere)
		float OpenSpeed = 30.f;

	UPROPERTY(EditAnywhere)
		float OpenAngle = -90.f;

	float TargetYaw;
};
