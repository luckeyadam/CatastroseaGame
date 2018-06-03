// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SSeaMine.generated.h"

class USHealthComponent;
class USphereComponent;
class USoundCue;

UCLASS()
class CATASTROSEA_API ASSeaMine : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASSeaMine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		USHealthComponent* HealthComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		USphereComponent* SphereComp;

	UFUNCTION()
		void HandleTakeDamage(USHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType,
			class AController* InstigatedBy, AActor* DamageCauser);

	FVector GetNextPathPoint();

	// Next point in navigation path
	FVector NextPathPoint;

	UPROPERTY(EditDefaultsOnly, Category = "SeaMine")
		float MovementForce;

	UPROPERTY(EditDefaultsOnly, Category = "SeaMine")
		bool bUseVelocityChange;

	UPROPERTY(EditDefaultsOnly, Category = "SeaMine")
		float RequiredDistanceToTarget;

	// Dynamic material to pulse on damage
	UMaterialInstanceDynamic* MatInst;

	void SelfDestruct();

	UPROPERTY(EditDefaultsOnly, Category = "SeaMine")
		UParticleSystem* ExplosionEffect;

	bool bExploded;

	bool bStartedSelfDestruction;

	UPROPERTY(EditDefaultsOnly, Category = "SeaMine")
		float ExplosionRadius;

	UPROPERTY(EditDefaultsOnly, Category = "SeaMine")
		float ExplosionDamage;

	UPROPERTY(EditDefaultsOnly, Category = "SeaMine")
		float SelfDamageInterval;

	FTimerHandle TimerHandle_SelfDamage;

	void DamageSelf();

	UPROPERTY(EditDefaultsOnly, Category = "SeaMine")
		USoundCue* SelfDestructSound;

	UPROPERTY(EditDefaultsOnly, Category = "SeaMine")
		USoundCue* ExplodeSound;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
