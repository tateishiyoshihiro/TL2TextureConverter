#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include "windows.h"

enum Argument
{
	kApplicationPath,//アプリケーションのパス
	kFilePath,		 //渡されたファイルのパス

	NumArgument
};

int main(int argc,char*argv[]) {
	////argcの数だけ繰り返す
	//for(int i=0;i<argc;i++){
	//	//文字列argvのi番を表示
	//	printf(argv[i]);
	//	//改行
	//	printf("\n");
	//}
	assert(argc >= NumArgument);

	//COMライブラリの初期化
	HRESULT hresult = CoInitializeEx(nullptr,COINIT_MULTITHREADED);
	assert(SUCCEEDED(hresult));

	//テクスチャコンバータ
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();

	system("pause");
	return 0;
}