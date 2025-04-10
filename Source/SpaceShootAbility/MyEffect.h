// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyEffect.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class GroundDirection : uint8 {
     ACID = 0 UMETA(DisplayName = "ACID"),
     VULNERABLE = 1 UMETA(DisplayName = "VULNERABLE"),
     SNARE = 2 UMETA(DisplayName = "SNARE"),
     STOP = 3 UMETA(DisplayName = "STOP"),
};

UCLASS()
class SPACESHOOTABILITY_API UMyEffect : public UObject
{
	GENERATED_BODY()
	
};
