// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnValueChanged);

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class STATSYSTEM_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

	UStatComponent();
public:

#pragma region GettersAndSetters
	UFUNCTION(BlueprintCallable, Category = "Health")
	FORCEINLINE float GetCurrentValue() const { return CurrentValue; }

	UFUNCTION(BlueprintCallable, Category = "Health")
	FORCEINLINE float GetMinValue() const { return MinValue; }

	UFUNCTION(BlueprintCallable, Category = "Health")
	FORCEINLINE float GetMaxValue() const { return MaxValue; }
	
	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetValuePercentage() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetValue(float InValue);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetMinValue(float InMinHealth);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetMaxValue(float InMaxValue);
#pragma endregion 

	UFUNCTION(BlueprintCallable, Category = "Health")
	void DegreaseValue(float DegreaseValue);
	
	UFUNCTION(BlueprintCallable, Category = "Health")
	void IncreaseValue(float IncreaseValue);

public:
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnValueChanged OnValueChanged;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float CurrentValue;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float MinValue;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float MaxValue;
};
