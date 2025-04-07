// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/ArrowComponent.h"
#include "Pawn_SSA.generated.h"

// Delegates - must be before the UCLASS ; MULTICAST -> Exposed to BPs
DECLARE_MULTICAST_DELEGATE(FOnDeath);

UCLASS()
class SPACESHOOTABILITY_API APawn_SSA : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawn_SSA();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame	
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* PawnMesh;
	
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UArrowComponent* ShootArrow;

protected:

    UPROPERTY()
    float MovementAmount;

public:
    UPROPERTY(EditAnywhere, Category = "Metrics")
    bool CanMove = true;
	
    UPROPERTY(EditAnywhere, Category = "Metrics")
    float MoveSpeed = 25.f;
	
	UFUNCTION()
	void Die();
	
	UFUNCTION()
	void Move(int NewMovementAmount);

	UFUNCTION()
	void Shoot();
	
	// Events
	FOnDeath OnDeath;
	
};
