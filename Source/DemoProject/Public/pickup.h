// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "FoodItem.h"
#include "InventoryComponent.h"
#include "../DemoProjectCharacter.h"
#include "pickup.generated.h"



UCLASS()
class DEMOPROJECT_API Apickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
    Apickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    UPROPERTY(EditAnywhere)
    USceneComponent* PickupRoot;
    
    // The static mesh for pick up
    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* MyMesh;
    
    UPROPERTY(EditAnywhere)
    UShapeComponent* PickupBox;

    UPROPERTY(EditAnywhere)
    class UInventoryComponent* OwningInventory;

    UPROPERTY(EditAnywhere)
    class UItem* FoodItem;
    
    UPROPERTY(EditAnywhere)
    ADemoProjectCharacter* character;
    
    
    UFUNCTION(BlueprintImplementableEvent)
    void FindCharacter(class ADemoProjectCharacter* charc);
    
    UFUNCTION()
    void OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
