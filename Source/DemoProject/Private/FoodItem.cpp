// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "../DemoProjectCharacter.h"

void UFoodItem::Use(class ADemoProjectCharacter* Character)
{
    if(Character)
    {
        Character->health += 10;
    }
}

