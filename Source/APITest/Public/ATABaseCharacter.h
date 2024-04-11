// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ATABaseCharacter.generated.h"

UCLASS()
class APITEST_API ATABaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ATABaseCharacter();

protected:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Методи для руху
    void MoveForward(float Value);
    void MoveRight(float Value);

    // Метод для інтеракції
    void Interact();
};
