#include "ATABaseCharacter.h"
#include "ANPC.h"

ATABaseCharacter::ATABaseCharacter()
{
    // Конструктор
}

void ATABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Призначення команд руху
    PlayerInputComponent->BindAxis("MoveForward", this, &ATABaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ATABaseCharacter::MoveRight);

    // Призначення команди інтеракції
    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ATABaseCharacter::Interact);
}

void ATABaseCharacter::MoveForward(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        // Визначення напрямку руху
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // Вектор руху вперед
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void ATABaseCharacter::MoveRight(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        // Визначення напрямку руху
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // Вектор руху вправо
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void ATABaseCharacter::Interact()
{
    // Логіка інтеракції
    // Отримання інформації про об'єкти поблизу
    TArray<AActor*> OverlappingActors;
    GetOverlappingActors(OverlappingActors);

    for (AActor* Actor : OverlappingActors)
    {
        // Перевірка, чи є актор NPC, який може дати квест
        ANPC* QuestGiver = Cast<ANPC>(Actor);
        if (QuestGiver)
        {
            // Взаємодія з NPC для отримання квесту
            QuestGiver->GiveQuestToPlayer(this);
            break;
        }
    }
}
