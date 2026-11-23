// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
	if (moveActor != nullptr)
	{
		moveComponent = moveActor->FindComponentByClass<UMove>();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("MOVE COMPONENT IS NULL"))
	}

	if (isPressurePlat)
	{
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		//OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}

}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComponent::Trigger(bool triggerValue)
{
	isTriggered = triggerValue;
	if (moveComponent)
	{
		moveComponent->SetShouldMove(isTriggered);
	}
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* overlapedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor && otherActor->ActorHasTag("Player"))
	{
		activatorCount++;
		if(!isTriggered && activatorCount == 1)
		{
			Trigger(true);
		}
		UE_LOG(LogTemp, Display, TEXT("On player Overlap"));
	}
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* overlapedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor && otherActor->ActorHasTag("Player"))
	{
		activatorCount--;
		if (!isTriggered && activatorCount == 0)
		{
			Trigger(false);
		}
		UE_LOG(LogTemp, Display, TEXT("End player Overlap"));
	}
}