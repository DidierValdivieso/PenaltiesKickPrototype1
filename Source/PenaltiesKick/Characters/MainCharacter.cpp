#include "MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "../Controllers/MainController.h"

AMainCharacter::AMainCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMainCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(PlayerInputComponent);
    // Detectar clic izquierdo para ejecutar acción
    PlayerInputComponent->BindKey(EKeys::LeftMouseButton, IE_Pressed, this, &AMainCharacter::OnAction);
}

void AMainCharacter::PlayAnimation(UAnimMontage* Animation)
{
    if (Animation)
    {
        PlayAnimMontage(Animation);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("El montage es NULL"));
    }
}

void AMainCharacter::OnAction()
{
    // Base vacío. Se sobreescribe en Pateador y Portero.
}

void AMainCharacter::SwitchCharacter()
{
    AController* MyController = GetController();
    if (MyController)
    {
        AMainController* MainController = Cast<AMainController>(MyController);
        if (MainController)
        {
            MainController->SwitchCharacter();
        }
    }
}
