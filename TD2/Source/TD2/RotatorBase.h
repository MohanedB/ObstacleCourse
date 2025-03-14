// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotatorBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD2_API URotatorBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotatorBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    float Speed = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    bool bRotateX = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    bool bRotateY = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    bool bRotateZ = true;
};