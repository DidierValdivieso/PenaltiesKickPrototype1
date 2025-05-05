#include "BallActor.h"

ABallActor::ABallActor()
{
    PrimaryActorTick.bCanEverTick = true;

    BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
    check(BallMesh);
    RootComponent = BallMesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMeshAsset(TEXT("/Game/Meshes/football"));
    if (BallMeshAsset.Succeeded())
    {
        BallMesh->SetStaticMesh(BallMeshAsset.Object);
    }

    InitialPosition = GetActorLocation();
}

void ABallActor::BeginPlay()
{
	Super::BeginPlay();
	
    if (BallMesh)
    {
        BallMesh->SetSimulatePhysics(true);
        BallMesh->SetEnableGravity(true);
        BallMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        BallMesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
        BallMesh->SetNotifyRigidBodyCollision(true);
        BallMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
    }
}

void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector ABallActor::GetInitialPosition() const
{
	return InitialPosition;
}




