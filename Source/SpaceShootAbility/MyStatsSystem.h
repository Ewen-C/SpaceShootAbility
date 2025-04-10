// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyEffect.h"
#include "UObject/NoExportTypes.h"
#include "MyStatsSystem.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTABILITY_API UMyStatsSystem : public UObject
{
	GENERATED_BODY()

public:
    UPROPERTY(VisibleAnywhere, Category = "Stats")
	float damage;
	
    UPROPERTY(VisibleAnywhere, Category = "Stats")
	float maxHealth;
	
    UPROPERTY(VisibleAnywhere, Category = "Stats")
	float currentHealth;
	
    UPROPERTY(VisibleAnywhere, Category = "Stats")
	float maxMovementSpeed;
	
    UPROPERTY(VisibleAnywhere, Category = "Stats")
	float currentMovementSpeed;
	
	UMyEffect currentEffects[];
	
};
