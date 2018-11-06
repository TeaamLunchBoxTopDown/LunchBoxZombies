// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileClass.generated.h"

UCLASS()
class LUNCHBOXZOMBIES_API AProjectileClass : public AActor
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	AProjectileClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UProjectileMovementComponent* ProjectileMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
