/*
1cheaders.inl
������ ���� �������� ����������� ��������� ���������� ��������,
����������� ������ ������������ � 1�-��������, � ��������� ��������
�������.
������������� ���������� � ����������� lib'�/
����� ����� �������� ��� � stdafx.cpp � ������ ��������
*/

// ����� ������� �������� ���������
//#pragma comment(linker,"/FILEALIGN:512")

// ��������� ����
// ���� � ����� ������ ��������� �� �������� �������� �������, � �� �� �������� ����� �����
// �� ��������� ������� ������� �� ����� ������ � ��������� 1CHeaders
// ���� ��� �� ���, �� ����� ���������� 1cheaders.inl ����� ���������� ������ HEADER1C_PATH
#ifndef HEADER1C_PATH
	#define HEADER1C_PATH "../1cheaders"
#endif

#pragma comment (lib,HEADER1C_PATH "/libs/basic.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/bkend.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/blang.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/br32.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/dbeng32.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/editr.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/frame.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/moxel.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/rgproc.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/seven.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/txtedt.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/type32.lib")
#pragma comment (lib,HEADER1C_PATH "/libs/userdef.lib")