// Fill out your copyright notice in the Description page of Project Settings.

#include "ATAQuestManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Serialization/JsonSerializer.h"

UTAQuestManager* UTAQuestManager::Instance = nullptr;

UTAQuestManager* UTAQuestManager::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = NewObject<UTAQuestManager>();
        Instance->AddToRoot();  // Запобігає знищенню об'єкта
    }
    return Instance;
}

UTAQuestManager::UTAQuestManager()
{
    // Конструктор
}

bool UTAQuestManager::LoadQuestData()
{
    FString QuestDataJson;
    FString FileName = FPaths::ProjectContentDir() + TEXT("/Data/questData.json");

    if (FFileHelper::LoadFileToString(QuestDataJson, *FileName))
    {
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(QuestDataJson);

        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            TArray<TSharedPtr<FJsonValue>> QuestArray = JsonObject->GetArrayField(TEXT("questArray"));

            for (TSharedPtr<FJsonValue> Value : QuestArray)
            {
                FQuestData QuestData;
                TSharedPtr<FJsonObject> QuestObject = Value->AsObject();

                QuestData.Id = QuestObject->GetIntegerField(TEXT("id"));
                QuestData.QuestDesc = QuestObject->GetStringField(TEXT("questDesc"));
                QuestData.QuestType = static_cast<EQuestType>(QuestObject->GetIntegerField(TEXT("questType")));
                QuestData.TargetLocation = FVector(QuestObject->GetNumberField(TEXT("locationX")),
                    QuestObject->GetNumberField(TEXT("locationY")), QuestObject->GetNumberField(TEXT("locationZ")));

                QuestDataArray.Add(QuestData);
            }
            return true;
        }
    }
    return false;
}
