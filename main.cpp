#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include "windows.h"

enum Argument
{
	kApplicationPath,//�A�v���P�[�V�����̃p�X
	kFilePath,		 //�n���ꂽ�t�@�C���̃p�X

	NumArgument
};

int main(int argc,char*argv[]) {
	////argc�̐������J��Ԃ�
	//for(int i=0;i<argc;i++){
	//	//������argv��i�Ԃ�\��
	//	printf(argv[i]);
	//	//���s
	//	printf("\n");
	//}
	assert(argc >= NumArgument);

	//COM���C�u�����̏�����
	HRESULT hresult = CoInitializeEx(nullptr,COINIT_MULTITHREADED);
	assert(SUCCEEDED(hresult));

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;

	//�e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();

	system("pause");
	return 0;
}