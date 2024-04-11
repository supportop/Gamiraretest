// Fill out your copyright notice in the Description page of Project Settings.

#include "TAQuestComponent.h"
#include "ATAQuestManager.h"

UTAQuestComponent::UTAQuestComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTAQuestComponent::BeginPlay()
{
    Super::BeginPlay();
}

TArray<FQuestData> UTAQuestComponent::GetAvailableQuests() const
{
    // Повертаємо список доступних квестів з менеджера квестів
    return UTAQuestManager::GetInstance()->GetQuestDataArray();
}

void UTAQuestComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
