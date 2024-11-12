#include "TextureConverter.h"
#include "stringapiset.h"

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath) 
{
	//1.テクスチャファイルを読み込む
	LoadWICTextureFromFile(filePath);
	//2.DDS形式に変換して書き出す
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath) 
{
	//1.ファイルパスをワイド文字列に変換
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);
	//2.テクスチャを読み込む
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString) 
{
	//ワイド文字列に変換した際の文字数を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return std::wstring();
}