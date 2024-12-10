#pragma once
#include <string>
#include "External/DirectXTex/DirectXTex.h"
class TextureConverter
{
public:
	///<summary>
	///テクスチャをWICからDDSに変換する
	///</summary>
	///<param name="filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filePath);

private:
	///<summary>
	///テクスチャを読み込む
	///</summary>
	///<param name="filePath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filePath);

private:
	///<summary>
	///マルチバイト文字列をワイド文字列に変換
	///</summary>
	///<param name="mString">マルチバイト文字列</param>
	///<returns>ワイド文字列</returns>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

private:
	//画像の表示
	DirectX::TexMetadata metadata_;
	//画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;

private:
	///<summary>
	///フォルダパスとファイル名を分離する
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void SeparateFilePath(const std::wstring& filePath);

private:
	//ディレクションパス
	std::wstring directoryPath_;
	//ファイル名
	std::wstring fileName_;
	//ファイル拡張子
	std::wstring fileExt_;

private:
	///<summary>
	///DDSテクスチャとしてファイル書き出し
	/// </summary>
	void SaveDDSTextureToFile();
};

