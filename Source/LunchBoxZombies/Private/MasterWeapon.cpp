// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/MasterWeapon.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "TimerManager.h"


// Sets default values
AMasterWeapon::AMasterWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Components Creation
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;

	//Setting Defualts
	BaseDamage = 25;
	FireRate = 600;
	NrOfBulletPerShot = 1;
	Range = 1000;
	bIsFullAuto = true;

	bCanFire = true;

	TimeBetweenShots = 60 / FireRate;
}

// Called when the game starts or when spawned
void AMasterWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMasterWeapon::Fire()
{
	if (FiringSound)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), FiringSound);
	}

	LastTimeFired = GetWorld()->TimeSeconds;
}

void AMasterWeapon::StartFire()
{
	if (bIsFullAuto==false)
	{
		SemiFire();
	}
	else
	{
		float FirstDelay = FMath::Max(LastTimeFired + TimeBetweenShots - GetWorld()->TimeSeconds, 0.0f);

		GetWorldTimerManager().SetTimer(TimerHandle_TimeBetween, this, &AMasterWeapon::Fire, TimeBetweenShots, true, FirstDelay);
	}
}

void AMasterWeapon::StopFire()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetween);
}

void AMasterWeapon::SemiFire()
{
	float FirstDelay = FMath::Max(LastTimeFired + TimeBetweenShots - GetWorld()->TimeSeconds, 0.0f);


	if (bCanFire)
	{
		Fire();
		bCanFire = false;
		GetWorldTimerManager().SetTimer(TimerHandle_SemiTimeBetween, this, &AMasterWeapon::SetCanFire, TimeBetweenShots, false);
	}

}

void AMasterWeapon::SetCanFire()
{
	bCanFire = true;
}

// Called every frame
void AMasterWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMasterWeapon::Reload()
{
	//Reload
}

