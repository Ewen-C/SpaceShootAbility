// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBase_SSA.h"
#include "PlayerController_SSA.h"

AGameModeBase_SSA::AGameModeBase_SSA()
{
	PlayerControllerClass = APlayerController_SSA::StaticClass();
}
