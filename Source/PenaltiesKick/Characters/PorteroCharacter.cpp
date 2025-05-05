#include "PorteroCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"

APorteroCharacter::APorteroCharacter()
{
    // Crear la cámara
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

    // Adjuntarla al RootComponent o al Mesh
    CameraComponent->SetupAttachment(RootComponent);

    // Posicionarla detrás del personaje
    CameraComponent->SetRelativeLocation(FVector(-300.0f, 0.0f, 100.0f)); // Elevar la cámara
    CameraComponent->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f)); // Ajustar el ángulo

    // Log para confirmar
    UE_LOG(LogTemp, Warning, TEXT("Portero: Camara creada y posicionada"));
}

void APorteroCharacter::OnAction()
{
    // Lógica específica para el pateador cuando hace clic
    UE_LOG(LogTemp, Warning, TEXT("¡El portero hizo click para atajar!"));
}