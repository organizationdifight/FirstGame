// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstGame.h"
#include "MyCharacter.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Настраиваем камеры
	CameraBoomComp = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	CameraBoomComp->AttachTo(GetCapsuleComponent());
	CameraBoomComp->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// Allow the pawn to control camera rotation.
	CameraBoomComp->bUsePawnControlRotation = true;


}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Добро пожаловать в тестовую игру!"));
	}
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

	check(InputComponent);

	//Задаем функции для действий
	InputComponent->BindAxis("Forward", this, &AMyCharacter::Forward);
	InputComponent->BindAxis("Turn", this, &AMyCharacter::Turn);

	InputComponent->BindAxis("Lookup", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("Lookturn", this, &APawn::AddControllerPitchInput);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJump);


	InputComponent->BindAction("Use", IE_Pressed, this, &AMyCharacter::OffLight);
	InputComponent->BindAction("Use", IE_Released, this, &AMyCharacter::OnLight);

	//InputComponent->BindAction("Use", this, )

}

void AMyCharacter::OffLight() {
	/*PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight3"));
	PointLight1->bVisible = false;*/
}
void AMyCharacter::OnLight() {
	/*PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight3"));
	PointLight1->bVisible = true;*/
}

void AMyCharacter::Forward(float val) {
	// проверяем что активен персонаж и передан не нулевой параметр
	if ((Controller != NULL) && (val != 0.0f)) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, val);
	}

}

void AMyCharacter::Turn(float val) {
	if ((Controller != NULL) && (val != 0.0f)) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, val);
	}
}


void AMyCharacter::StartJump()
{
	bPressedJump = true;
}

void AMyCharacter::StopJump()
{
	bPressedJump = false;
}


