// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TAQuestManager.generated.h"

UCLASS()
class APITEST_API UTAQuestManager : public UObject
{
    GENERATED_BODY()

public:
    // Отримання екземпляру Singleton
    static UTAQuestManager* GetInstance();

    // Завантаження даних квестів з JSON
    bool LoadQuestData();

private:
    // Конструктор
    UTAQuestManager();

    // Екземпляр Singleton
    static UTAQuestManager* Instance;

    // Масив даних квестів
    TArray<FQuestData> QuestDataArray;
};
