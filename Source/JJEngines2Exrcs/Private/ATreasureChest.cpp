// Fill out your copyright notice in the Description page of Project Settings.


#include "ATreasureChest.h"
#include "Components/BoxComponent.h"

// Sets default values
AATreasureChest::AATreasureChest()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Initialize our Treasure Mesh
    TreasureMesh = CreateDefaultSubobject<UStaticMeshComponent>("Treasure Mesh");

    TreasureMesh->SetGenerateOverlapEvents(false);

    BoxCollider = CreateDefaultSubobject<UBoxComponent>("Collision Detection");

    // Init the box collider
    SetRootComponent(BoxCollider);

    // Setup the root component
    TreasureMesh->SetupAttachment(BoxCollider);

    // Parent the treasure mesh component to the box collider
    bCollected = false;

}

// Called when the game starts or when spawned
void AATreasureChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATreasureChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

