// Fill out your copyright notice in the Description page of Project Settings.


#include "ATreasureChest.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"

// Sets default values
AATreasureChest::AATreasureChest()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    // Initialize our Treasure Mesh
    TreasureMesh = CreateDefaultSubobject<UStaticMeshComponent>("TreasureMesh");

    TreasureMesh->SetGenerateOverlapEvents(false);

    BoxCollider = CreateDefaultSubobject<UBoxComponent>("Collision Detection");

    // Setup root component
    SetRootComponent(BoxCollider);

    // Parent the root component
    TreasureMesh->SetupAttachment(BoxCollider);

    bCollected = false;
    BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AATreasureChest::OnBeginOverlapComponentEvent);
    BoxCollider->SetCollisionProfileName("OverlapAllDynamic");
    BoxCollider->SetGenerateOverlapEvents(true);
}



void AATreasureChest::Collected()
{
    if (bCollected)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("Treasure Already Collected."));
        
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("Treasure Collected!"));
        bCollected = true;
    }
}

void AATreasureChest::OnBeginOverlapComponentEvent(UPrimitiveComponent*
    OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32
    OtherBodyIndex, bool bFromSweep, const FHitResult&
    SweepResult)
{
    if (Cast<AActor>(OtherActor))
    {
        AATreasureChest::Collected();
    }

}
