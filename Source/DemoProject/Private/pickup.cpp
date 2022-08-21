// Fill out your copyright notice in the Description page of Project Settings.


#include "pickup.h"


// Sets default values
Apickup::Apickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));
    RootComponent = PickupRoot;
    
    MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item"));
    MyMesh->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
    
    PickupBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupItem"));
    PickupBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
    PickupBox->SetGenerateOverlapEvents(true);
    PickupBox->OnComponentBeginOverlap.AddDynamic(this, &Apickup::OnPlayerEnterPickupBox);
    PickupBox->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void Apickup::BeginPlay()
{
	Super::BeginPlay(); 
}

// Called every frame
void Apickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Apickup::OnPlayerEnterPickupBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    Destroy();
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Picked Up!"));
    if(FoodItem)
    {
        character->Inventory->AddItem(FoodItem);
    }
}
