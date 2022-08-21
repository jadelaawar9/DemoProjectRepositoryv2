// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableObj.h"

// Sets default values
APickableObj::APickableObj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickableObj::BeginPlay()
{
	Super::BeginPlay();
    this->ConditionalBeginDestroy();
}

// Called every frame
void APickableObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

