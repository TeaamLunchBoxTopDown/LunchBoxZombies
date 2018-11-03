// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/MasterWeapon.h"
#include "Components/SkeletalMeshComponent.h"


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

}

// Called when the game starts or when spawned
void AMasterWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMasterWeapon::Fire()
{
	//Fire
}

