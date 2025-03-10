// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeBase_SSA.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTABILITY_API AGameModeBase_SSA : public AGameModeBase
{
	GENERATED_BODY()

public: 
	AGameModeBase_SSA();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metrics")
	int32 StartingMoney = 8;

protected :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metrics")
	UDataTable* DTGameData;
};
