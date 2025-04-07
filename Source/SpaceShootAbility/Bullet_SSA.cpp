// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet_SSA.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABullet_SSA::ABullet_SSA()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if(!RootComponent)
    {
	    BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("BulletMesh");
		RootComponent = BulletMesh;
    }

	if(!ProjectileMovementComponent)
    {
        ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
        ProjectileMovementComponent->SetUpdatedComponent(BulletMesh);
        ProjectileMovementComponent->InitialSpeed = 200.0f;
        ProjectileMovementComponent->MaxSpeed = 200.0f;
        ProjectileMovementComponent->bRotationFollowsVelocity = true;
        ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
    }
}

// Called when the game starts or when spawned
void ABullet_SSA::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("ABullet_SSA::BeginPlay"));
	
	BulletMesh->SetSimulatePhysics(true);
	BulletMesh->SetEnableGravity(false);

	BulletMesh->OnComponentHit.AddDynamic(this, &ABullet_SSA::OnComponentHit);
	
}

// Called every frame
void ABullet_SSA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Function that initializes the projectile's velocity in the shoot direction.
void ABullet_SSA::FireInDirection(const FVector& ShootDirection)
{
    ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

void ABullet_SSA::OnDealDamage()
{
	
}

void ABullet_SSA::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// TODO : LOG
}

