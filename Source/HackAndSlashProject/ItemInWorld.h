// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInWorld.generated.h"
//class UItemData;


UCLASS()
class HACKANDSLASHPROJECT_API AItemInWorld : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemInWorld();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	bool isDual;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	//UItemData *  itemData;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
