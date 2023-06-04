// Fill out your copyright notice in the Description page of Project Settings.


#include "StatComponent.h"

UStatComponent::UStatComponent()
{
	MinValue = 0.f;
	MaxValue = 100.f;
	CurrentValue = MaxValue;
}

float UStatComponent::GetValuePercentage() const
{
	check(MaxValue > 0.f)
	return CurrentValue / MaxValue;
}

void UStatComponent::SetValue(float InValue)
{
	CurrentValue = InValue;
	OnValueChanged.Broadcast();
}

void UStatComponent::SetMinValue(float InMinHealth)
{
	MinValue= InMinHealth;
	OnValueChanged.Broadcast();
}

void UStatComponent::SetMaxValue(float InMaxValue)
{
	MaxValue = InMaxValue;
	OnValueChanged.Broadcast();
}

void UStatComponent::DegreaseValue(float DegreaseValue)
{
	CurrentValue = FMath::Max(0.f, CurrentValue - DegreaseValue);
	OnValueChanged.Broadcast();
}

void UStatComponent::IncreaseValue(float IncreaseValue)
{
	CurrentValue = FMath::Max(0.f, CurrentValue + IncreaseValue);
	OnValueChanged.Broadcast();
}
