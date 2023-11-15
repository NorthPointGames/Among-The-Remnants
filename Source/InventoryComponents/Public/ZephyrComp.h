// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ZephyrComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class INVENTORYCOMPONENTS_API UZephyrComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UZephyrComp();

	FTimerHandle FInfectionTimer;

	FTimerHandle FFireDamageTimer;

	FTimerHandle FHealDelayTimer;
	FTimerHandle FHealTimer;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	int CurrentHealth = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Settings")
	int MaxHealth = 8;

	UPROPERTY(BlueprintReadOnly, Category="Settings")
	float HealDelay = 10;

	UPROPERTY(BlueprintReadOnly, Category = "Settings")
	float HealTickRate = 1;

	int FireCurrentTick = 0;
	int FireMaxTicks = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Settings")
	float FireTickRate = 1;

	UPROPERTY(BlueprintReadOnly, Category = "Infection")
	float InfectionTickRate = 10;

	/*
	UPROPERTY(BlueprintReadOnly, Category = "Infection")
	bool IsOnFire = false;

	UPROPERTY(BlueprintReadOnly, Category = "Infection")
	bool IsInfected = false;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	float HealDelay = 10;
	*/

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Zephyr")
	void DealDamage(int Damage, bool Infect);

	// UFUNCTION(BlueprintCallable, Category = "Zephyr")
	void BeginHeal();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Zephyr")
	void Heal(int HealAmount);

	// UFUNCTION(BlueprintCallable, Category = "Zephyr")
	void FireDamage();

	UFUNCTION(BlueprintCallable, Category = "Zephyr")
	void CatchFire(int Duration);

	// UFUNCTION(BlueprintCallable, Category = "Zephyr")
	void Infected();

	// UFUNCTION(BlueprintCallable, Category = "Zephyr")
	void Turn();
		
	UFUNCTION(BlueprintCallable, Category = "Zephyr")
	void Cure();

};
