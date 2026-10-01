// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATreasureChest.generated.h"

class UBoxComponent;

UCLASS()
class JJENGINES2EXRCS_API AATreasureChest : public AActor
{
	GENERATED_BODY()
	
	public:	
		// Sets default values for this actor's properties
		AATreasureChest();

	protected:

		// Treasure Mesh of type static mesh component
		UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UStaticMeshComponent> TreasureMesh;

		UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UBoxComponent> BoxCollider;

		UFUNCTION()
		void Collected();

		UFUNCTION()
		void OnBeginOverlapComponentEvent(UPrimitiveComponent*
			OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32
			OtherBodyIndex, bool bFromSweep, const FHitResult&
			SweepResult);

		UPROPERTY()
		bool bCollected;
		

		/*UFUNCTION()
		virtual void UpdateScore();*/


	public:

		

};
