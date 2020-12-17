// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FloatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEVELDESIGNPROJECT_API UFloatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFloatComponent();

	// Whether the owner rotates counterclockwise
	// EditAnywhere allows us to change this value from details
	// BlueprintReadWrite allows us to get and set this variable in Blueprint
	UPROPERTY(Category="Float", EditAnywhere, BlueprintReadWrite)
	bool Counterclockwise = false;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Set the direction the owner spins
	// BlueprintCallable allows us to call this function in Blueprint
	UFUNCTION(BlueprintCallable)
	void SetSpin(bool clockwise);
};
