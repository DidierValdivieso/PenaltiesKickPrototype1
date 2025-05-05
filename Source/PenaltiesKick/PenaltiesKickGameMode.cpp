
#include "PenaltiesKickGameMode.h"
#include "Characters/PorteroCharacter.h"
#include "Camera/CameraComponent.h"
#include "Characters/PateadorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Actors/BallActor.h"
#include "Actors/PorteriaActor.h"

APenaltiesKickGameMode::APenaltiesKickGameMode()
{
}

APorteroCharacter* APenaltiesKickGameMode::SpawnPorteroCharacter()
{
    if (!PorteroCharacterClass)
    {
        UE_LOG(LogTemp, Error, TEXT("PorteroCharacterClass no esta asignado en PenaltiesKickGameMode"));
        return nullptr;
    }

    if (PorteroCharacterClass)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        FVector SpawnLocation = FVector(0.f, 0.f, 300.f);
        FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);

        return GetWorld()->SpawnActor<APorteroCharacter>(PorteroCharacterClass, SpawnLocation, SpawnRotation, SpawnParams);
    }

    return nullptr;
}

APateadorCharacter* APenaltiesKickGameMode::SpawnPateadorCharacter(const FVector& ReferenceLocation)
{
    if (!PateadorCharacterClass)
    {
        UE_LOG(LogTemp, Error, TEXT("PateadorCharacterClass no esta asignado en PenaltiesKickGameMode"));
        return nullptr;
    }

    if (PateadorCharacterClass)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        // Calculamos 11 metros adelante en el eje X
        FVector SpawnLocation = ReferenceLocation + FVector(1100.f, 100.f, -200.f);
        FRotator SpawnRotation = FRotator(0.f, 180.f, 0.f);

        APateadorCharacter* Pateador = GetWorld()->SpawnActor<APateadorCharacter>(PateadorCharacterClass, SpawnLocation, SpawnRotation, SpawnParams);

        // Llamar a SpawnBall usando la ubicación del pateador
        if (Pateador)
        {
            SpawnBall(Pateador->GetActorLocation());
        }

        return Pateador;
    }

    return nullptr;
}


ABallActor* APenaltiesKickGameMode::SpawnBall(const FVector& PateadorLocation)
{
    if (!BallClass)
    {
        UE_LOG(LogTemp, Error, TEXT("SpawnBall no esta asignado en PenaltiesKickGameMode"));
        return nullptr;
    }

    if (BallClass)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        // Calculamos la nueva posición del balón 100 cm (1 metro) adelante del pateador
        FVector SpawnLocation = PateadorLocation - FVector(300.f, 100.f, 100.f); // Ajusta el eje según sea necesario
        FRotator SpawnRotation = FRotator::ZeroRotator; // Cambia esto si necesitas una rotación específica

        ABallActor* Ball = GetWorld()->SpawnActor<ABallActor>(BallClass, SpawnLocation, SpawnRotation, SpawnParams);

        return Ball;
    }
    return nullptr;
}

APorteriaActor* APenaltiesKickGameMode::SpawnPorteria()
{
    if (!PorteriaClass)
    {
        UE_LOG(LogTemp, Error, TEXT("PorteriaClass no esta asignado en PenaltiesKickGameMode"));
        return nullptr;
    }

    if (PorteriaClass)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        FVector SpawnLocation = FVector(-500.f, 0.f, -700.f);
        FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);

        APorteriaActor* Porteria = GetWorld()->SpawnActor<APorteriaActor>(PorteriaClass, SpawnLocation, SpawnRotation, SpawnParams);

        return Porteria;
    }

    return nullptr;
}


void APenaltiesKickGameMode::BeginPlay()
{
    Super::BeginPlay();

}
