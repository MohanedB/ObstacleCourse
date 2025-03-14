// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovementBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD2_API UMovementBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovementBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement")
	float Speed = 100.0f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement")
	FVector MovementDirection = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement")
	float MovementRange = 0.0f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Movement")
	bool bCanMoveBackAndForth = false;

private:
	FVector StartPosition;

	void UpdateMovement(float DeltaTime);
};
