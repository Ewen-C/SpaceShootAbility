// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState_SSA.h"
#include "GameModeBase_SSA.h"


void APlayerState_SSA::BeginPlay()
{
	Super::BeginPlay();

	if(const AGameModeBase_SSA* Gm_Td = Cast<AGameModeBase_SSA>(GetWorld()->GetAuthGameMode()))
	{
		AddMoney(Gm_Td->StartingMoney);
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Can't get GameMode in TDPlayerState ! "));
	}
}

void APlayerState_SSA::AddMoney(const int32 Amount)
{
	if(!Amount) return;
	
	CurrentMoney += Amount;
	UE_LOG(LogTemp, Warning, TEXT("APlayerState_SSA::AddMoney %i -> %i !"), Amount, CurrentMoney);
	OnMoneyChanged.Broadcast(CurrentMoney);
}

bool APlayerState_SSA::SpendMoney(const int32 Amount)
{
	if(CurrentMoney < Amount)
	{
		OnInsufficientFunds.Broadcast();
		return false;
	}
	
	CurrentMoney -= Amount;
	OnMoneyChanged.Broadcast(CurrentMoney);
	return true;
}
