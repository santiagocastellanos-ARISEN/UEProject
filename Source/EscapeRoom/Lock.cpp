// Fill out your copyright notice in the Description page of Project Settings.


#include "Lock.h"

// Sets default values
ALock::ALock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add("Lock");

	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root Comp"));
	SetRootComponent(rootComp);

	triggerComp = CreateDefaultSubobject<UTriggerComponent>(TEXT("trigger Comp"));
	triggerComp->SetupAttachment(rootComp);

	keyItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("item Mesh"));
	keyItemMesh->SetupAttachment(rootComp);

}

// Called when the game starts or when spawned
void ALock::BeginPlay()
{
	Super::BeginPlay();
	SetIsKeyPlaced(false);
	
}

// Called every frame
void ALock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALock::SetIsKeyPlaced(bool value)
{
	isKeyPlaced = value;

	triggerComp->Trigger(isKeyPlaced);
	keyItemMesh->SetVisibility(isKeyPlaced);
}

bool ALock::GetIsKeyPlaced() const
{
	return isKeyPlaced;
}

