// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEMOPROJECT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
    
    UInventoryComponent();
    
    virtual void BeginPlay() override;
    
    bool AddItem(class UItem* Item);
    bool RemoveItem(class UItem* Item);
    
    UPROPERTY(EditDefaultsOnly, Instanced)
    TArray<class UItem*> DefaultItems;
    
    UPROPERTY(EditDefaultsOnly, Category = "Inventory")
    int32 Capacity;
    
    UPROPERTY(BlueprintAssignable, Category = "Inventory")
    FOnInventoryUpdated OnInventoryUpdated;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Items")
    TArray<class UItem*> Items;
		
};
