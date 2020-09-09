// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Core/Public/HAL/FileManagerGeneric.h"
#include "MyBlueprintFunctionLibrary.generated.h"



/**
 * 
 */
UCLASS()
class WATCHERS_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "File operation")
		static bool DeleteFile(FString FilePath);
	UFUNCTION(BlueprintCallable, Category = "GetFildContent")
		FString GetFileContent(FString Filepath, FString Extension);



};
