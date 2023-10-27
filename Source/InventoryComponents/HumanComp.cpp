// Fill out your copyright notice in the Description page of Project Settings.

#include "HumanComp.h"

// Sets default values for this component's properties
UHumanComp::UHumanComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}

// Called when the game starts
void UHumanComp::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		ActorRef = GetOwner();
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::White, TEXT("Actor Ref Set"));
	}

	

}

// Called every frame
void UHumanComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UHumanComp::DealDamage(int DamageTaken)
{
	CurrentHitPoints--;

	GetWorld()->GetTimerManager().SetTimer(DamageTimerHandle, HealDelay, false);

}

void UHumanComp::DamageTimer()
{

}
