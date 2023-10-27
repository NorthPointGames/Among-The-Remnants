// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HumanComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYCOMPONENTS_API UHumanComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHumanComp();

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	int32 MaxHitPoints = 2;

	UPROPERTY(BlueprintReadOnly, Category= "Health")
	int32 CurrentHitPoints = 2;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	float HealDelay = 4;

	UPROPERTY(BlueprintReadOnly, Category="Refs")
	AActor* ActorRef = nullptr;

	FTimerHandle DamageTimerHandle;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintCallable)
	void DealDamage(int DamageTaken);

	UPROPERTY(BlueprintCallable)
	void DamageTimer();

};
