// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProjectPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMyProjectPlayer::AMyProjectPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	// Setting Root Component
	RootComponent = Mesh;

	
	SpringArm->SetupAttachment(Mesh); // Attach the Spring Arm to the Mesh. Spring will now follow the Mesh transform.
	Camera->SetupAttachment(SpringArm); // Attach the Camera to the Sprint Arm. Camera will now follow the Spring Arm transform.
}

// Called when the game starts or when spawned
void AMyProjectPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void AMyProjectPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyProjectPlayer::MoveRight(float value)
{
}

void AMyProjectPlayer::MoveForward(float value)
{
}

void AMyProjectPlayer::Jump(float value)
{
}

