// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "slua.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"



UCLASS(Blueprintable, BlueprintType)
class WATCHERS_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UMyGameInstance();

	UFUNCTION(BlueprintCallable)
	static UMyGameInstance* GetInstance();
	/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
	virtual void Init() override;
	/** virtual function to allow custom GameInstances an opportunity to do cleanup when shutting down */
	virtual void Shutdown() override;

	UFUNCTION()
		void LuaStateInitCallback();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="reply")
		FString reply_fstring;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "reply")
		TArray<FString> reply_string;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "reply")
		bool reply_changed=false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "reply")
		FString imgurl;
	// create global state, freed on app exit

	NS_SLUA::LuaState state;
};
