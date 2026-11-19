// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Move.h"
#include "TriggerComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPEROOM_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()
public:
	UTriggerComponent();
	// Sets default values for this component's properties
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Trigger(bool triggerValue);

	UPROPERTY(EditAnywhere)
	bool isPressurePlat = false;

	UPROPERTY(VisibleAnywhere)
	bool isPressurePlate = false;

	UPROPERTY(EditAnywhere)
	AActor* moveActor;

	UMove* moveComponent;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* overlapedComp, AActor* otherActor, UPrimitiveComponent* otherComp,
		int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* overlapedComp, AActor* otherActor, UPrimitiveComponent* otherComp,
		int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

protected:

};
