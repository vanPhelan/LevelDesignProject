// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatComponent.h"
#include "FloatingActor.generated.h"

UCLASS()
class LEVELDESIGNPROJECT_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

	// Reference to the mesh component
	// VisibleAnywhere allows us to see it in the editor
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	// Reference to the custom component
	// BlueprintReadOnly allows us to get this reference in Blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UFloatComponent* FloatingComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
