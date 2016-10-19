// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class FIRSTGAME_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION()
	void Forward(float val);

	UFUNCTION()
	void Turn(float val);

	UFUNCTION()
		void StartJump();

	UFUNCTION()
		void StopJump();

	UFUNCTION()
		void OnLight();

	UFUNCTION()
		void OffLight();

public:

	UPROPERTY(VisibleAnyWhere, Category = "Camera")
		UCameraComponent* CameraBoomComp;

	UPROPERTY(VisibleAnywhere, Category = "Switch Components")
		class UPointLightComponent* PointLight1;
	
	
};
