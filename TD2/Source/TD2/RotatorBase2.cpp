// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatorBase2.h"

// Sets default values for this component's properties
URotatorBase2::URotatorBase2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts

// Called when the game starts
void URotatorBase2::BeginPlay()
{
    Super::BeginPlay();

    if (!GetOwner()) return;

    if (RotationAxis.IsNearlyZero())
    {
        RotationAxis = FVector(0.0f, 0.0f, 1.0f);
    }
}
// Called every frame
void URotatorBase2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    UpdateRotation(DeltaTime);
}

void URotatorBase2::UpdateRotation(float DeltaTime)
{
    AActor* Owner = GetOwner();
    if (!Owner) return;

    float RotationOffset = RotationSpeed * DeltaTime;

    if (bCanRotateBackAndForth)
    {
        CurrentRotationAngle += RotationOffset * RotationDirection;

        if (FMath::Abs(CurrentRotationAngle) >= RotationRange)
        {
            RotationDirection *= -1;
            CurrentRotationAngle = FMath::Clamp(CurrentRotationAngle, -RotationRange, RotationRange);
        }

        RotationOffset *= RotationDirection;
    }

    FRotator CurrentRotation = Owner->GetActorRotation();
    FRotator RotationDelta = FRotator(RotationAxis.X * RotationOffset, RotationAxis.Y * RotationOffset, RotationAxis.Z * RotationOffset);

    Owner->SetActorRotation(CurrentRotation + RotationDelta);
}

