// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
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

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* PawnMesh;

public:
	UFUNCTION()
	void Die();
	
	// Events
	FOnDeath OnDeath;
	
};
