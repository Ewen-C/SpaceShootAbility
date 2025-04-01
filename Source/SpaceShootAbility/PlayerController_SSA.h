// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "Camera/CameraActor.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "PlayerPawn_SSA.h"
#include "PlayerController_SSA.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTABILITY_API APlayerController_SSA : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
  
	// Input Mapping Context
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Input")
	class UInputMappingContext* MappingContext_SSA;
	
	// Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Input")
	class UInputAction* ActionMovement;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Input")
	class UInputAction* ActionFire;
	
	
	// Input Action handlers
	void HandleMovement(const FInputActionValue& InputValue);
	void HandleFire();

	// Cached actors
	UPROPERTY()
	ACameraActor* SceneCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Widgets")
	TSubclassOf<UUserWidget> WidgetHud;

	UPROPERTY()
	UUserWidget* SpawnedWidgetHud;

	UPROPERTY()
	APlayerPawn_SSA* PlayerPawn_Ssa;
	
};
