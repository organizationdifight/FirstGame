// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FBox.generated.h"

UCLASS()
class FIRSTGAME_API AFBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFBox();

	AFBox(FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


private:
	UPROPERTY(EditDefaultsOnly, Category = "My Mesh")
		UStaticMeshComponent* ourMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Collision Comp")
		USphereComponent* collisionComp;

	UPROPERTY(EditDefaultsOnly, Category = "Our Light")
		ULightComponent* ourLight;

private:
	bool bIsOn;

public:
	void toggleLight();


	
	
};
