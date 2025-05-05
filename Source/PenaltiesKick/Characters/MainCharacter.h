#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS(Abstract) // ¡Muy importante! Para que no puedas instanciar directamente este personaje.
class PENALTIESKICK_API AMainCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMainCharacter();

protected:
    virtual void BeginPlay() override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
    virtual void PlayAnimation(UAnimMontage* Animation);

    // Accion principal, se va a sobrescribir en los hijos
    virtual void OnAction();

    UFUNCTION()
    void SwitchCharacter();

};