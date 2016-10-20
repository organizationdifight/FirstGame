// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstGame.h"
#include "FBox.h"
#include "MyCharacter.h"


// Sets default values
AFBox::AFBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AFBox::AFBox(FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ourMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Our Mesh"));
	ourMesh->SetEnableGravity(false);
	ourMesh->SetSimulatePhysics(false);
	ourMesh->AttachTo(RootComponent);
	RootComponent = ourMesh;

	collisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Comp"));
	FVector newLoc = FVector(0.f, 60.f, 0.f);
	collisionComp->SetRelativeLocation(newLoc);
	collisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	collisionComp->SetSphereRadius(60.f);
	collisionComp->AttachTo(RootComponent);

	ourLight = CreateDefaultSubobject<ULightComponent>(TEXT("Our Light"));
	FVector LightLoc = FVector(1000.f, 150.f, 120.f);
	ourLight->SetRelativeLocation(LightLoc);
	ourLight->SetVisibility(true);
	ourLight->AttachTo(RootComponent);

	bIsOn = true;

}

// Called when the game starts or when spawned
void AFBox::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AFBox::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AFBox::toggleLight()
{
	if (bIsOn == true)
	{
		bIsOn = false;		
	}
	else 
	{
		bIsOn = true;
	}
	ourLight->SetVisibility(bIsOn);
}

