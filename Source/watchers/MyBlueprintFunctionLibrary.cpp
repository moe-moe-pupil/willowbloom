// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "PlatformFilemanager.h"
#include "FileHelper.h"

bool UMyBlueprintFunctionLibrary::DeleteFile(FString FilePath)
{
	return IFileManager::Get().Delete(*FilePath);
}
FString UMyBlueprintFunctionLibrary::GetFileContent( FString Filepath, FString Extension)
{
	TArray<FString>DirsArray;
	//文件夹路径
	FString filecontents;
	TSharedRef <TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&filecontents);
	JsonWriter->WriteObjectStart(); // 相当于写了一个｛
	JsonWriter->WriteObjectStart("content"); // 相当于写了一个"TestData": 和｛
	FString SearchedFiles = Filepath + "/" + TEXT("*");
	//返回Filepath该路径下的文件夹
	IFileManager::Get().FindFiles(DirsArray, *SearchedFiles, false, true);
	//返回文件
	//IFileManager::Get().FindFiles(DirsArray, *SearchedFiles, true, false);
	for (size_t i = 0; i < DirsArray.Num(); i++)
	{
		FString filePath = Filepath + "/" + DirsArray[i] + "/";
		FString fileWithExtension = filePath + Extension;
		//UE_LOG(LogTemp, Error, TEXT("TARRAY____%s"), *DirsArray[i]);
		//UE_LOG(LogTemp, Error, TEXT("文件夹____%s"), *fileWithExtension);
		//GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Filepath);
		TArray<FString>filesArray;
		IFileManager::Get().FindFiles(filesArray, *fileWithExtension, true, false);
		JsonWriter->WriteArrayStart(DirsArray[i]); // 相当于写了一个"Hobby": 和[
		for (size_t j = 0; j < filesArray.Num(); j++)
		{
			
			JsonWriter->WriteValue(filesArray[j]); // 相当于写了一个"Reading"
			//FString fileFullName = filePath + filesArray[j];
			//UE_LOG(LogClass, Error, TEXT("旧文件名...%s"), *fileFullName);
			//GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, fileFullName);
		}
		JsonWriter->WriteArrayEnd(); // 相当于写了一个]

	}
	JsonWriter->WriteObjectEnd();
	JsonWriter->WriteObjectEnd();
	JsonWriter->Close();
	return filecontents;
}
