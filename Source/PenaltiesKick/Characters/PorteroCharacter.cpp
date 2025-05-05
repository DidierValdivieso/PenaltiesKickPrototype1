#include "PorteroCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"

APorteroCharacter::APorteroCharacter()
{
    // Crear la c�mara
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

    // Adjuntarla al RootComponent o al Mesh
    CameraComponent->SetupAttachment(RootComponent);

    // Posicionarla detr�s del personaje
    CameraComponent->SetRelativeLocation(FVector(-300.0f, 0.0f, 100.0f)); // Elevar la c�mara
    CameraComponent->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f)); // Ajustar el �ngulo

    // Log para confirmar
    UE_LOG(LogTemp, Warning, TEXT("Portero: Camara creada y posicionada"));
}

void APorteroCharacter::OnAction()
{
    // L�gica espec�fica para el pateador cuando hace clic
    UE_LOG(LogTemp, Warning, TEXT("�El portero hizo click para atajar!"));
}