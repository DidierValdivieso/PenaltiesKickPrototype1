#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PenaltiesKickGameMode.generated.h"

class APorteroCharacter;
class APateadorCharacter;

UCLASS()
class PENALTIESKICK_API APenaltiesKickGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APenaltiesKickGameMode();

	void BeginPlay();

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	APorteroCharacter* SpawnPorteroCharacter();

	// Función para spawnear el Pateador basado en una ubicación
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	APateadorCharacter* SpawnPateadorCharacter(const FVector& ReferenceLocation);

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	ABallActor* SpawnBall(const FVector& PateadorLocation);

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	APorteriaActor* SpawnPorteria();

	// Clase del personaje que vamos a spawnear
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<APorteroCharacter> PorteroCharacterClass;

	// Clase del PateadorCharacter para spawnear
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<APateadorCharacter> PateadorCharacterClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<ABallActor> BallClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<APorteriaActor> PorteriaClass;

};
