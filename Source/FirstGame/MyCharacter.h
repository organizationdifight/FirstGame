// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "FBox.h"
#include "MyCharacter.generated.h"

UCLASS()
class FIRSTGAME_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	//AMyCharacter(const FObjectInitializer& ObjectInitializer);

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

	
public:
	void useObject();

private:
	bool isBox(class AFbox* Other);
	bool isLightSwitch(class ALightSwitch_Parent* Other);

private:
	ALightSwitch_Parent* currentSwitch;
	AFbox* currentBox;

	
	
};
