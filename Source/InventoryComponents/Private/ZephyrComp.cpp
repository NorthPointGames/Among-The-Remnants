// Fill out your copyright notice in the Description page of Project Settings.


#include "ZephyrComp.h"

// Sets default values for this component's properties
UZephyrComp::UZephyrComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UZephyrComp::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	
}


// Called every frame
void UZephyrComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UZephyrComp::BeginHeal()
{
	GetWorld()->GetTimerManager().SetTimer(FHealTimer, [&] {UZephyrComp::Heal(1); }, HealTickRate, true, 0);

}

void UZephyrComp::FireDamage()
{
	DealDamage(1, false);

	FireCurrentTick++;

}

void UZephyrComp::CatchFire(int Duration)
{
	FireMaxTicks = Duration;
	GetWorld()->GetTimerManager().SetTimer(FHealTimer, [&] {UZephyrComp::FireDamage(); }, HealTickRate, true, 0);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::White, TEXT("On Fire"));

}

void UZephyrComp::Infected()
{
	GetWorld()->GetTimerManager().SetTimer(FInfectionTimer, this, &UZephyrComp::Turn, InfectionTickRate, false);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::White, TEXT("Infected"));

}

void UZephyrComp::Turn()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::White, TEXT("Turned"));

}

void UZephyrComp::Cure()
{
	GetWorld()->GetTimerManager().ClearTimer(FInfectionTimer);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::White, TEXT("Cured"));

}

void UZephyrComp::Heal_Implementation(int HealAmount)
{
	CurrentHealth += HealAmount;
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::White, TEXT("Healed"));

}

void UZephyrComp::DealDamage_Implementation(int Damage, bool Infect)
{
	CurrentHealth -= Damage;

	if (Infect)
	{
		Infected();
	}

}
