#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallActor.generated.h"

UCLASS()
class PENALTIESKICK_API ABallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABallActor();

	virtual void Tick(float DeltaTime) override;

	// M�todo para obtener la posici�n inicial del bal�n
	FVector GetInitialPosition() const;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BallMesh;

protected:
	virtual void BeginPlay() override;

private:
	FVector InitialPosition;
};
