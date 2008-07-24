// 1cheaders.h
/*
������ ���� ������������ ��� ��� ��������� � stdafx.h ������������� ��������,
����������� � ������� � 1� dll'���.
*/
#ifndef _1C_HEADERS_H
#define _1C_HEADERS_H

#define IMPORT_1C __declspec(dllimport)

#include <afxcview.h> 
#include <comdef.h>
#include <afxctl.h>
#include <afxtempl.h>
#include <functional>
#include <set>
#include <vector>
#include <map>

/*
// kms
// ��� CGetDoc77 - ��� CHintStruct77

struct CHintStruct77
{
	int m_null;
	int m_CtrlNumber;
	char* m_HintText;
};
*/

// ��������� ��������� �����
#define CS_EX_DONOTTAB         0x00000004L //���������� ��� �����
#define CS_EX_QUICKCHOICE      0x00000008L //������� �����
#define CS_EX_USEDESCRIPTION   0x00000010L //������������ ��������, ��� ���������
#define CS_EX_HAVEBUTTON       0x00000020L //����� ������ ������
#define CS_EX_FORMFONT         0x00000040L //����� �� ���������
#define CS_EX_ACCEL            0x00000100L //������ �����������
#define CS_EX_VISIBLE          0x00002000L //���������
#define CS_EX_READONLY         0x00004000L //�����������
#define CS_EX_TRANSPARENT      0x00010000L //���������� ���
#define CS_EX_NOTSTORE         0x01000000L //�� ��������� ��� ���������� ���������
#define CS_EX_REDNEGATIVE      0x04000000L //������������� �������
#define CS_EX_DONOTEDIT        0x10000000L //��������� ��������������

#define C_BROWSE_STYLE_EX_DONOT_VISIBLE        0x1000000L //�����������

struct  CFormCtrlSet // ��� CControlID
{
public:
	int m_ID;
	int m_TypeCtrl;
	int buf1[2];
	int m_Kind; // ��� �������
	int m_Type; // ��� �������
	int m_Left;
	int m_Top;
	int m_Right;
	int m_Bottom;
	char* m_Caption;
	char* m_Label;
	char* m_Formula;
	DWORD m_Style;
	int buf2[2];
	DWORD m_StyleEx; // ������� ����� (���������, ����������� � �.�.)
	int m_ListFormID; // ���������� ������������� ����� ��� ������ ���������
	char* m_Mask;
	char* m_Hint;
	char* m_Description;
	int buf3[21];
	char* m_LayerName;
	int buf4[5];
};

class CGetDoc7; // artbear
class IMPORT_1C CFormCtrl:public CObject // ��� CGetField
{
public:
	int m_Flag1;
	int m_Flag2;
	int m_Flag3;
	//CGetDoc77* m_GetDoc; // ���� - ��������� �� �������� ������ GetDoc7
	CGetDoc7* m_GetDoc; // ���� - ��������� �� �������� ������ GetDoc7 // artbear

	int m_ID;
	CFormCtrlSet* m_Set;
	int buf[26];
	int m_RefFlag;
	int m_Flag4;
	int m_ReadOnly;
	int m_Visible;
};

// ������� ������ 1� �������
#include "type32.h"
#include "types.h"
#include "br32.h"
#include "bkend.h"
#include "frame.h"
#include "blang.h"
#include "seven.h"
#include "editr.h"
#include "basic.h"
#include "dbeng32.h"
#include "moxel.h"
#include "rgproc.h"
#include "txtedt.h"
#include "userdef.h"

using namespace std;
// ������� ��������� �������� ���������� ��������
extern CApp7*			pMainApp;
extern CBkEndUI*		pBkEndUI;
extern CMetaDataCont*	pMetaDataCont;
extern HINSTANCE		h1CResource;
extern SECMDIFrameWnd*	pMainFrame;

#include "ext_header.h"

#endif