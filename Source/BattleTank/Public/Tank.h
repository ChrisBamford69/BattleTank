// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDeath);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCausor) override;

	// returns current health as a percentage of starting health between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthRemaining() const;

	FTankDeath TankDeath;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 InnerHealth;
};
