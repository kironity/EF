// Copyright Epic Games, Inc. All Rights Reserved.

#include "EngineFeautresCharacter.h"

#include "EFBasicObject.h"
#include "EFObjectStore.h"
#include "EngineFeautres.h"
#include "EngineFeautresProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Core/EFWorldStateManager.h"
#include "StatSystem/Public/StatComponent.h"
#include "Types/FWorldSaveData.h"


//////////////////////////////////////////////////////////////////////////
// AEngineFeautresCharacter

void AEngineFeautresCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

AEngineFeautresCharacter::AEngineFeautresCharacter()
{
	// Character doesnt have a rifle at start
	bHasRifle = false;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	PlayerStat = CreateDefaultSubobject<UStatComponent>(TEXT("PlayerStat"));
}

void AEngineFeautresCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	UEFBasicObject* SomeObject = NewObject<UEFBasicObject>(GetTransientPackage(), UEFBasicObject::StaticClass());
	
	WeakObjectPtr = SomeObject;
	if (WeakObjectPtr.Get())
	{
		BasicObjects.Add(WeakObjectPtr.Get());
		UE_LOG(LogTemp, Warning, TEXT("Weak gun valid"));
	}
	FGuid();
}

//////////////////////////////////////////////////////////////////////////// Input
void AEngineFeautresCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AEngineFeautresCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AEngineFeautresCharacter::Look);
	}
}


void AEngineFeautresCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AEngineFeautresCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AEngineFeautresCharacter::SetHasRifle(bool bNewHasRifle)
{
	bHasRifle = bNewHasRifle;
}

bool AEngineFeautresCharacter::GetHasRifle()
{
	return bHasRifle;
}

void AEngineFeautresCharacter::CreateSmartPointers()
{
	NativeObjectVar = MakeShareable(new FEFNativeObject());

	GetGameInstance()->GetSubsystem<UEFObjectStore>()->ReferenceToSmartObject = NativeObjectVar;
}

void AEngineFeautresCharacter::Suicide()
{
	Destroy();
}

void AEngineFeautresCharacter::SaveGame()
{
	if (AEFWorldStateManager* WorldStateManager = GetGameInstance()->GetSubsystem<UEFObjectStore>()->WorldStateManager.Get())
	{
		WorldStateManager->SaveWorld();
	}
}

void AEngineFeautresCharacter::GetSaveData(FWorldSaveData& SaveData)
{
	SaveData.PlayerSaveData.PlayerLocation = GetActorLocation();
	SaveData.PlayerSaveData.Healths = PlayerStat->GetCurrentValue();
}

void AEngineFeautresCharacter::LoadSaveData(const FWorldSaveData& LoadData)
{
	const FVector NewActorLocation = LoadData.PlayerSaveData.PlayerLocation;
	TeleportTo(NewActorLocation, GetActorRotation());
	const float NewHealth = LoadData.PlayerSaveData.Healths;
	PlayerStat->SetValue(NewHealth);
}
