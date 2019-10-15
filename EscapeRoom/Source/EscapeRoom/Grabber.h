// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Setup attached InputComponent. 
	void SetupInputComponent();

	//Find Physicshandle
	void FindPhysicsHandleComponent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

private:

	//Hoe far a player can see.
	float Reach = 100.f;
		
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	
	UInputComponent* InputComponent = nullptr;

	//Ray-Cast and grab whats in reach.
	void Grab();
	void Release();

	//Return Hit for the first physics body in reach.
	FHitResult const GetFirstPhysicsBodyInReach() ;

	//Return current end of reach line.
	FVector GetReachLineEnd();

	//Return current start of reach line.
	FVector GetReachLineStart();
};
