#include "PateadorCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Animation/AnimMontage.h"
#include "MainCharacter.h"
#include "../Actors/BallActor.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

APateadorCharacter::APateadorCharacter()
{
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComponent->SetupAttachment(RootComponent);
    CameraComponent->SetRelativeLocation(FVector(-300.0f, 0.0f, 100.0f)); // Elevar la cámara
    CameraComponent->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f)); // Ajustar el ángulo

    UE_LOG(LogTemp, Warning, TEXT("Pateador: Camara creada y posicionada"));

    static ConstructorHelpers::FObjectFinder<UAnimMontage> KickAnimationAsset(TEXT("/Game/Blueprints/AM_Pateador"));
    if (KickAnimationAsset.Succeeded())
    {
        AM_Pateador = KickAnimationAsset.Object;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No se pudo encontrar la animacion de pateo."));
    }
}

void APateadorCharacter::OnAction()
{
    Super::OnAction();
    PlayAnimation(AM_Pateador);

    GetWorldTimerManager().SetTimer(ShootDelayHandle, this, &APateadorCharacter::EjecutarDisparo, 0.7f, false);
}


void APateadorCharacter::EjecutarDisparo()
{
    ABallActor* Ball = nullptr;
    for (TActorIterator<ABallActor> It(GetWorld()); It; ++It)
    {
        Ball = *It;
        break;
    }

    if (!Ball) return;

    APlayerController* PC = Cast<APlayerController>(GetController());
    if (!PC) return;

    float MouseX, MouseY;
    if (!PC->GetMousePosition(MouseX, MouseY)) return;

    FVector WorldLocation, WorldDirection;
    if (!PC->DeprojectScreenPositionToWorld(MouseX, MouseY, WorldLocation, WorldDirection)) return;

    FVector BallLocation = Ball->GetActorLocation();
    FVector TraceEnd = BallLocation + WorldDirection * 1000.f;

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(Ball);

    bool bHit = GetWorld()->LineTraceSingleByChannel(
        HitResult,
        BallLocation,
        TraceEnd,
        ECC_Visibility,
        Params
    );

    FVector TargetPoint;
    if (bHit)
    {
        TargetPoint = HitResult.ImpactPoint;
    }
    else
    {
        TargetPoint = TraceEnd;
    }

    FVector Direction = (TargetPoint - BallLocation).GetSafeNormal();
    Direction.Z += 0.3f;
    Direction = Direction.GetSafeNormal();

    float KickForce = 1500.0f;
    Ball->BallMesh->AddImpulse(Direction * KickForce, NAME_None, true);
}

