// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController_SSA.h"


void APlayerController_SSA::BeginPlay()
{
	Super::BeginPlay(); 

	// Input setup
	APlayerController* PlayerController = Cast<APlayerController>(this);
	if (!(PlayerController && MappingContext_SSA)) UE_LOG(LogTemp, Fatal, TEXT("Failed input setup ! "));;

	   if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
	    ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	   {
	       Subsystem->AddMappingContext(MappingContext_SSA, 0);
	   }

    AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass());
	SceneCamera = Cast<ACameraActor>(FoundActor);

	// HUD setup
	// if (WidgetHud == nullptr) UE_LOG(LogTemp, Fatal, TEXT("No WidgetHud assigned ! "));

	// SpawnedWidgetHud = CreateWidget(this, WidgetHud);
	// SpawnedWidgetHud->AddToViewport();

	UE_LOG(LogTemp, Log, TEXT("APlayerController_SSA::BeginPlay"));

	PlayerPawn_Ssa = Cast<APlayerPawn_SSA>(GetPawn());
}

void APlayerController_SSA::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(InputComponent);
	if (EIC == nullptr) UE_LOG(LogTemp, Fatal, TEXT("Failed to bind actions ! "));

	// Bind all actions

	EIC->BindAction(ActionMovement, ETriggerEvent::Triggered, this, &APlayerController_SSA::HandleMovement);
	EIC->BindAction(ActionMovement, ETriggerEvent::Canceled, this, &APlayerController_SSA::HandleMovementStopped);
	EIC->BindAction(ActionMovement, ETriggerEvent::Completed, this, &APlayerController_SSA::HandleMovementStopped);

	EIC->BindAction(ActionFire, ETriggerEvent::Started, this, &APlayerController_SSA::HandleFire);
}

void APlayerController_SSA::HandleMovement(const FInputActionValue& InputValue)
{
	FVector2D MovementAmount = InputValue.Get<FInputActionValue::Axis2D>();
	// Or  InputValue.Get<FInputActionValue::Axis1D>();  if float input
	
	PlayerPawn_Ssa->Move(MovementAmount.Y);
}

void APlayerController_SSA::HandleMovementStopped()
{
	UE_LOG(LogTemp, Warning, TEXT("HandleMovementStopped"));
	PlayerPawn_Ssa->Move(0);
}

void APlayerController_SSA::HandleFire()
{
	UE_LOG(LogTemp, Warning, TEXT("HandleFire"));
	PlayerPawn_Ssa->Shoot();
}
