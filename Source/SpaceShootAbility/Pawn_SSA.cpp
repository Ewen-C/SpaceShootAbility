// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn_SSA.h"


// Sets default values
APawn_SSA::APawn_SSA()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>("PawnMesh");
    RootComponent = PawnMesh;
	
	ShootArrow = CreateDefaultSubobject<UArrowComponent>("ShootArrow");
	ShootArrow->ArrowLength = 25.f;

	PawnStats = NewObject<UMyStatsSystem>();
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

	if(CanMove && MovementAmount != 0)
	{
		FVector currentLocation = this->GetActorLocation();
		this->SetActorLocation(FVector(currentLocation.X + MovementAmount * MoveSpeed * DeltaTime * 100, currentLocation.Y, currentLocation.Z));
	}
	
}

// Called to bind functionality to input
void APawn_SSA::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Called to bind functionality to input
void APawn_SSA::Die()
{
	UE_LOG(LogTemp, Log, TEXT("APawn_SSA::Die"));
}

void APawn_SSA::Move(int NewMovementAmount)
{
	// UE_LOG(LogTemp, Log, TEXT("APawn_SSA::Move : %d"), NewMovementAmount);
	MovementAmount = NewMovementAmount;
}

void APawn_SSA::Shoot()
{
	UE_LOG(LogTemp, Log, TEXT("APawn_SSA::Shoot"));
    UWorld* World = GetWorld();
    if (World)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator();

        ABullet_SSA* Projectile = World->SpawnActor<ABullet_SSA>(
        	ProjectileClass,
        	this->GetActorLocation() + ShootArrow->GetRelativeLocation(),
        	this->GetActorRotation(),
        	SpawnParams);
    	
        if (Projectile)
        {
            FVector LaunchDirection = ShootArrow->GetRelativeRotation().Vector();
            Projectile->FireInDirection(LaunchDirection);

        	// TODO : Setup bullet stats
        }
    }
}

