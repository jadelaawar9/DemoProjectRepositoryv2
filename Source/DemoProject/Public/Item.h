// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class DEMOPROJECT_API UItem : public UObject
{
	GENERATED_BODY()
    
public:
    
    UItem();
    
    virtual class UWorld* GetWorld() const {return World;};
    
    UPROPERTY(Transient)
    class UWorld* World;
    
    // The text for using this item (eat, use, equip)
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
    FText UseActionText;
    
    // The mesh to display for this items pickup
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
    class UStaticMesh* PickupMesh;
    
    // The thumbnail for this item
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
    class UTexture2D* Thumbnail;
    
    // The display name for the itme in the invesntory
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
    FText ItemDisplayName;
    
    // An optional description
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (Multiline = true))
    FText ItemDescription;
    
    UPROPERTY()
    class UInventoryComponent* OwningInventory;
    
    virtual void Use(class ADemoProjectCharacter* Character);
    
    //virtual void PickUp(class ADemoProjectCharacter* Character);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnUse(class ADemoProjectCharacter* Character);
	
};
