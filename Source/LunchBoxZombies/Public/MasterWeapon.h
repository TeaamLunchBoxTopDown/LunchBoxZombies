// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MasterWeapon.generated.h"

UCLASS()
class LUNCHBOXZOMBIES_API AMasterWeapon : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AMasterWeapon();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USkeletalMeshComponent* WeaponMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Fire();

	void SemiFire();

	void SetCanFire();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	float BaseDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	float FireRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	int32 NrOfBulletPerShot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	float Range;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	bool bIsFullAuto;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects | Socket")
	FName SocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects | Socket")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	int32 DefaultMagSize;

	UPROPERTY(BlueprintReadOnly, Category = "Stats")
	int32 AmmoInMag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects | Sound")
	USoundBase* FiringSound;


	float TimeBetweenShots;

	FTimerHandle TimerHandle_TimeBetween;

	FTimerHandle TimerHandle_SemiTimeBetween;

	float LastTimeFired;

	bool bCanFire;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Weapon Events")
	void StartFire();

	UFUNCTION(BlueprintCallable, Category = "Weapon Events")
	void StopFire();

	UFUNCTION(BlueprintCallable, Category = "Weapon Events")
	void Reload();
	

};
