#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "PateadorCharacter.generated.h"

UCLASS()
class PENALTIESKICK_API APateadorCharacter : public AMainCharacter
{
    GENERATED_BODY()

public:
    APateadorCharacter();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    UCameraComponent* CameraComponent;   

    FTimerHandle ShootDelayHandle;

    void EjecutarDisparo();

protected:
    virtual void OnAction() override;

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
    UAnimMontage* AM_Pateador;
};