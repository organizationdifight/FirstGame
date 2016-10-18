// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstGame.h"
#include "MyCharacter.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoomComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoomComp->TargetArmLength = 300.f;
	CameraBoomComp->AttachTo(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->AttachTo(CameraBoomComp);

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	// Проверяем InputComponent
	check(InputComponent);

	// Привязываем функции
	InputComponent->BindAxis("Forward", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("Right", this, &AMyCharacter::MoveRight);

	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("Look", this, &APawn::AddControllerPitchInput);

}

void AMyCharacter::MoveForward(float val) {

}

void AMyCharacter::MoveRight(float val) {

}

