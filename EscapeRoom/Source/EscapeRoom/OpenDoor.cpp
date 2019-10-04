// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner(); //Store the Owner.
	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	//Set new Rotation.
	Owner->SetActorRotation(FRotator(0., OpenAngle, 0.));
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0., 0., 0.));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Poll every frame.
	//if the ActorThatOpen is in the volume.
	if (PressurePlate->IsOverlappingActor(ActorThatOpen))
	{
		OpenDoor();
		LastTimeDoorOpen = GetWorld()->GetTimeSeconds();
	}

	//Check if it's time to close the door.
	if (GetWorld()->GetTimeSeconds() - LastTimeDoorOpen > DoorCloseDelay)
	{
		CloseDoor();
	}
}

