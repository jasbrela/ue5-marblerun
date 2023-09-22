// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyProjectPlayer.generated.h"

// Forward declarations: "a little bit cheaper (than #include), a little bit lightweight"
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class MYPROJECT2_API AMyProjectPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyProjectPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Define Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components") // These "UPROPERTY" seems similar to the unity attributes
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UCameraComponent* Camera;

	// Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveForce = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpImpulse = 1000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxJumpCount = 1;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Functions
	void MoveRight(float value); // between -1 and 1.	
	void MoveForward(float value);
	void Jump(float value);
	
	int32 JumpCount = 1;
};
