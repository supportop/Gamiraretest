// Fill out your copyright notice in the Description page of Project Settings.

#include "TAMainGameInstance.h"
#include "ATAQuestManager.h"
#include "Engine/Engine.h"

void UTAMainGameInstance::Init()
{
    Super::Init();

    // Ініціалізація менеджера квестів та завантаження даних квестів
    if (UTAQuestManager::GetInstance()->LoadQuestData())
    {
        // Дані квестів успішно завантажені
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Quest data loaded successfully."));
        }
    }
    else
    {
        // Помилка при завантаженні даних квестів
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Failed to load quest data."));
        }
    }
}
