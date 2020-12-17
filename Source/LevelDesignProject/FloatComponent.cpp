// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatComponent.h"

// Sets default values for this component's properties
UFloatComponent::UFloatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFloatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UFloatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Get the Actor to which this component is attached
	AActor* owner = GetOwner();
	//Get the current location and rotation
	FVector NewLocation = owner->GetActorLocation();
	FRotator NewRotation = owner->GetActorRotation();
	//Get the owner's running time
	float RunningTime = owner->GetGameTimeSinceCreation();
	//Calculate the change in height
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;
	//Calculate the change in rotation based on the spin direction
	float DeltaRotation = DeltaTime * 20.0f;
	if (!Counterclockwise)
		NewRotation.Yaw += DeltaRotation;
	else
		NewRotation.Yaw -= DeltaRotation;
	//Update the location and rotation
	owner->SetActorLocationAndRotation(NewLocation, NewRotation);
}

// Set the direction the owner spins
void UFloatComponent::SetSpin(bool clockwise)
{
	Counterclockwise = !clockwise;
}

