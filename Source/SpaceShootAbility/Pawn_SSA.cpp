// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn_SSA.h"

// Sets default values
APawn_SSA::APawn_SSA()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>("PawnMesh");
    RootComponent = PawnMesh;
}

// Called when the game starts or when spawned
void APawn_SSA::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawn_SSA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawn_SSA::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Called to bind functionality to input
void APawn_SSA::Die()
{
	UE_LOG(LogTemp, Log, TEXT("APawn_SSA::Die"));;
}

