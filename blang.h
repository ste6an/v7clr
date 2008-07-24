// Begin forward declarations
class  CBLModule;
class  CBLProcInfo;
class  CBLVarInfo;
class  CStdOleBLContext;
class  CTokensBox;
// End forward declarations
// Begin class descriptions

class CBLModuleConstDescr
{
	public:
		void* vtable;
		CValue val;
};

class CBLModuleProcVarDescr
{
	public:
		//00h
		void* vtable;
		//04h
		CString Name;
		//08h
		int ArraySize; // ������ �������
		//0Ch
		int Flag1;	// 1 - �������
		//10h
		int Type; // 
		//14h
		int Type2; // 
//		char* Proc1(void) {return Name;}; // virtual
};

class CBLModuleProcLabelDescr
{
	public:
		void* vtable;
		char* Name;
		int Addr;
};

class CCompileProcInfo
{
public:
	//00h
	void* vtable;
	//04h
	CString pName;
	//08h
	int Type; // 0 - ����������; 1 - ���������; 2 - �������; 3 - ���� ������
	//0Ch
	int BaseAddr;
	//10h
	int NParams;
	//14h
	void* vtable1;
	//18h
	CTypedPtrArray<CPtrArray,	CBLModuleProcVarDescr*> VarList; //������ ������ �� ���������� ������ // CBLModuleProcVarDescr
	//2Ch
	void* vtable2;
	//30h
	CPtrArray LabelList; //������ ������ �� ����� � ������ // CBLModuleProcLabelDescr
	//3Ch
	void* Flag8;
	//40h
	DWORD Flag9;		//(1 - �������)
	//44h
	int Flag10;
	//48h
	int Flag11;
	//4Ch
	DWORD Flag12;
};

class CCompiledModule
{
public:
	//00h
	void* vtable1;
	//04h
	CTypedPtrArray<CPtrArray, CBLModuleConstDescr*> ConstArray; // ������ �������� � ������ // CBLModuleConstDescr
	//18h
	void* vtable2;
	//1Ch
	CTypedPtrArray<CPtrArray, CCompileProcInfo*> ProcArray; // ������ ������ �� ��������� ������ // CCompileProcInfo
	//30h
	CDWordArray PCode; // ���������������� ���
	//40h
	void* Flag3;
	//44h
	void* Flag4;
};

class CStoreCValue
{
public:
	void* pVTable;
//	CTypedValue cValue;
	CValue cValue;
};

class CUnkArrayClass
{
public:
	void* pVTable;
//	DWORD dwFlag1;
//	filebuf pFilebuf;
	CArray<CStoreCValue*, CStoreCValue*> cPtrArray;
};

class CUnkStoreClass
{
public:
//	void* pVTable;
	// 0x00
	CBLModule7* pModule7;
	// 0x04
	CUnkArrayClass* pArray;
	// 0x08
	DWORD Flag_0x08;
	// 0x0C
	DWORD Flag_0x0C;
	// 0x10
	DWORD Flag_0x10;
	// 0x14
	DWORD Flag_0x14;
	// 0x18
	CValue *m_pValue; // ���� Flag1 = 1, �� ���������� ������ ������������ dwFlag5
};

struct structSTACK
{
	DWORD dwFlag1;
	DWORD dwFlag2;
	DWORD dwFlag3;
	CUnkStoreClass* dwValue;
	DWORD dwFlag5;
};

class CExecutedModule
{
public:
	//00h
	class CBLModule* m_pModule;
	//04h
	class CCompiledModule* m_pCompiledModule;
	//08h
	DWORD val_3;
	//0Ch
	struct structSTACK* pStack; // ������ - ���������� ����
	//10h
	DWORD val_5;
	//14h
	DWORD dwStackSize; // ���������� ���������� � �����
	//18h
	DWORD val_7;
	//1Ch
	DWORD val_8;
	//20h
	DWORD val_9;
	//24h
	DWORD val_10;
	//28h
	DWORD val_11;
	//2Ch
	DWORD val_12;
	//30h
	CDWordArray m_DWordArray1;
	//44h
	CDWordArray m_DWordArray2;
	//58h
	DWORD val_23;
	//5Ch
	DWORD val_24;
	//60h
	DWORD bufExec[0x50];
};
/*
class CExecutedModule // �� ����-�
{
public:
     //00h
     class CBLModule* m_pModule;
     //04h
     class CCompiledModule* m_pCompiledModule;
     //08h
     DWORD val_3;
     //0Ch
     DWORD val_4;
     //10h
     DWORD val_5;
     //14h
     DWORD val_6;
     //18h
     DWORD val_7;
     //1Ch
     DWORD val_8;
     //20h
     DWORD val_9;
     //24h
     DWORD val_10;
     //28h
     DWORD val_11;
     //2Ch
     DWORD val_12;
     //30h
     CDWordArray m_DWordArray1;
     //44h
     CDWordArray m_DWordArray2;
     //58h
     DWORD val_23;
     //5Ch
     DWORD val_24;
};
*/
class IMPORT_1C CBLModuleInternals
{
public:
	//+00h
	class CBLModule* pModule;
	//+04h
	class CBLContext* pGeneralContext; //CGeneralContext
	//+08h
	int Flag3;
	//+0Ch
	CBLSpeller* pBLSpeller;
	//+10h
	int Flag5;
	//+14h
	CString mSource;
	//+18h
	int* StartIDArray;
	//+1Ch
	int* EndIDArray1;
	//+20h
	int* EndIDArray2;
	//+24h
	class CCompiler* pCompiler;
	//+28h
	class CCompiledModule* pCompiledModule;
	//+2Ch
	class CExecutedModule* pExecutedModule;
	//+30h
	//void* Flag13;
	CString* strExecutingProc; //char** Flag13;
};


class IMPORT_1C CBLModule //VF Table OK
{
public:
	class CBLModuleInternals* pIntInfo;		//0x04

	CBLModule(class CBLModule const &);	//1
	CBLModule(class CBLContext *,char const *);	//2

	virtual					~CBLModule(void);	
	virtual int				GetKind(void)const;	
	virtual char const *	GetSyntaxMark(void);	
	virtual int				OnSyntaxError(void);	//128
	virtual int				OnRuntimeError(void);	//124
	virtual int				OnStartExecution(void);	//126
	virtual int				OnNextLine(void);	//123
	virtual void			OnEnterProc(int);	//119
	virtual void			OnExitProc(int);	//121
	virtual void			OnStopExecution(void);	//127
	virtual void			OnErrorMessage(char const *);	//120
	virtual void			OnSetSpeller(class CValue const &);	//125
	virtual int				OnDoMessageBox(char const *,unsigned int,unsigned int);	//118
	virtual void			OnGetErrorDescription(class CString &);	//122

	static void  AddToKeywordColorList(char const *);	//21
	static void  AddToKeywordColorList(class CBLContext const *);	//22
	static int  ColorSourceLine(char const *,class CBLSyntaxColoring &);	//33
	static void  EnableDebugDump(int);	//36
	static class CBLModule *  GetExecutedModule(void);	//53
	static unsigned long  GetFirstLoadedModuleID(void);	//54
	static class CBLModule *  GetLoadedModule(unsigned long);	//59
	static unsigned long  GetNextLoadedModuleID(unsigned long);	//74
	static void  GetSyntaxErrDescr(int,class CString &);	//93
	static int  IsDebugDumpEnabled(void);	//106
	static int  IsLeftAdjFormat(char const *);	//111
	static void  RaiseExtRuntimeError(char const *,int);	//130
	static void  RemoveFromKeywordColorList(char const *);	//131
	static void  RemoveFromKeywordColorList(class CBLContext const *);	//132
	static void  SetOnCommandExceptionHandler(void (__cdecl*)(class CException *,int &));	//136
	static int  TokenizeSourceLine(char const *,int &,class CString *);	//139

	class CBLModule &  operator=(class CBLModule const &);	//11
//	void  `default constructor closure'(void);	//18
	void  AddSourceLine(char const *);	//20
	void  AssignCompiled(class CBLModule const &);	//23
	void  AssignContext(class CBLContext *);	//24
	void  AssignFriendModule(class CBLModule *);	//25
	void  AssignSource(class CBLModule const &);	//26
	void  AssignSource(char const *);	//27
	void  AssignSpeller(class CBLSpeller *);	//28

	//CallAsFunc(int, CValue&, int, CValue** )
	// 1: ����� ���������
	// 2: �������� ���������� �� ��������� �������
	// 3: ���������� ����������, ���� ���, �� 0
	// 4: ������ ���������� �� ���������
	// �������: 0 - ���� ����� �� �������
	int  CallAsFunc(int iFuncNum,class CValue & retValue,int iParamCount,class CValue * *params);	//29

	// CallAsProc(int, int, CValue **) - �������� ��������� ������������������ ������
	// 1: ����� ���������
	// 2: ���������� ����������, ���� ���, �� 0
	// 3: ������ ���������� �� ���������
	// �������: 0 - ���� ����� �� �������
	int  CallAsProc(int iProcNum,int iParamCount,class CValue * *params);	//31
	int  Compile(void);	//34
	int  EvalExpr(char const *,class CValue &,class CValue * *);	//37
	int  Execute(void);	//38
	int  ExecuteBatch(char const *,class CValue * *);	//39
	int  FindFunc(char const *)const;	//40

	// FindProc(const char *, int) - ������� ����� ������� ��� ��������� � ������
	// 1: ������ � ��������� ������� ��� ���������
	// 2: 0 - ���������, 1 - �������
	int  FindProc(char const * szMethodName, int bFunctionFlag) const;	//42

	int  FindStaticVar(char const *)const;	//44
	class CString   FormatValue(class CValue const &,char const *);	//45
	int  GetCallLevelProcInfo(int,class CBLProcInfo &,int &)const;	//46
	int  GetCallStackDepth(void)const;	//47
	int  GetCurSourceLine(int,class CString &)const;	//48
	class CBLModule const *  GetCurrentModule(void)const;	//49
	unsigned long  GetExecutedCmdAddr(void)const;	//51
	int  GetExecutedLineNum(void)const;	//52
	int  GetFirstSrcLineInfo(class CBLSrcLineInfo &)const;	//55
	class CBLModuleInternals *  GetInternalData(void)const;	//56
	unsigned long  GetLoadedID(void)const;	//58
	int  GetNCurSourceLines(void)const;	//63
	int  GetNProcs(void)const;	//67
	int  GetNSourceLines(void)const;	//69
	int  GetNStaticVars(void)const;	//70
	int  GetNextSrcLineInfo(class CBLSrcLineInfo &)const;	//75
	int  GetProcInfo(int,class CBLProcInfo &)const;	//76
	int  GetRuntimeErrCode(void)const;	//82
	void  GetRuntimeErrDescr(int,class CString &)const;	//83
	char const *  GetRuntimeErrIdent(void)const;	//84
	int  GetRuntimeErrLineNum(void)const;	//85
	class CBLModule *  GetRuntimeErrModule(void)const;	//86
	void  GetRuntimeErrSourceLine(class CString &)const;	//87
	int  GetSourceLine(int,class CString &)const;	//88
	class CBLSpeller *  GetSpeller(void)const;	//89
	int  GetStaticVarDescr(int,class CBLVarInfo &)const;	//90
	int  GetStaticVarValue(int,class CValue &,int)const;	//91
	int  GetSyntaxErrCode(void)const;	//92
	char const *  GetSyntaxErrIdent(void)const;	//94
	int  GetSyntaxErrLineNum(void)const;	//95
	char const *  GetSyntaxErrMarkedLine(void)const;	//96
	int  HasSource(void)const;	//104
	int  IsCompiled(void)const;	//105
	int  IsExecuted(void)const;	//107
	int  IsInBatchMode(void)const;	//110
	int  IsLoaded(void)const;	//112
	int  IsValidObject(void)const;	//115
	int  Load(void);	//116
	int  LoadSource(char const *);	//117
	int  PrepareToLoad(void);	//129
	void  Reset(void);	//133
	void  ResetCompiled(void);	//134
	void  ResetExecuted(void);	//135
	int  SetStaticVarValue(int,class CValue const &,int);	//138
	void  Unload(void);	//141
};


class IMPORT_1C CBLVarInfo
{
public:
	CBLModule* pMod;
	int nProcPos;
	int nVarPos;
	DWORD size_buffer[0xFF];
	 CBLVarInfo(void);	//4
	class CBLVarInfo &  operator=(class CBLVarInfo const &);	//13
	int  GetDim(void)const;	//50
	class CBLModule *  GetModule(void)const;	//62
	char const *  GetName(void)const;	//73
	int  GetProcPos(void)const;	//78
	int  GetVarPos(void)const;	//101
	int  IsExported(void)const;	//109
};

class IMPORT_1C CBLProcInfo
{
public:
	//char size_buffer[1000];
	CBLModule* m_Module;
	ULONG m_ProcID;
	DWORD m_Unknown;
	 CBLProcInfo(void);	//3
	class CBLProcInfo &  operator=(class CBLProcInfo const &);	//12
	class CBLModule *  GetModule(void)const;	//61
	int  GetNParams(void)const;	//65
	int  GetNVars(void)const;	//71
	char const *  GetName(void)const;	//72
	int  GetProcPos(void)const;	//77
	int  GetType(void)const;	//98 // ������� 0 - �������, 1 - ���������, -1 - �������
	int  GetVarDescr(int,class CBLVarInfo &)const;	//100
	int  HasRetVal(void)const;	//102
	int  IsExported(void)const;	//108
};


class IMPORT_1C CStdOleBLContext:public COleGenericBLContext
{
DECLARE_DYNCREATE(CStdOleBLContext)

public:
	int        m_int1;      // 4 �����
	int        m_int2;      // 4 �����

//	char buffer[4000];
	 CStdOleBLContext(int);	//5
	virtual  ~CStdOleBLContext(void);	//9
//	void  `default constructor closure'(void);	//19
	virtual int  CallAsFunc(int,class CValue &,class CValue * *);	//30
	virtual int  CallAsProc(int,class CValue * *);	//32
	virtual int  FindMethod(char const *)const;	//41
	virtual int  FindProp(char const *)const;	//43
	virtual char const *  GetMethodName(int,int)const;	//60
	virtual int  GetNMethods(void)const;	//64
	virtual int  GetNParams(int)const;	//66
	virtual int  GetNProps(void)const;	//68
	virtual char const *  GetPropName(int,int)const;	//79
	virtual int  GetPropVal(int,class CValue &)const;	//80
	virtual char const *  GetTypeString(void)const;	//99
	virtual int  HasRetVal(int)const;	//103
	virtual int  IsPropReadable(int)const;	//113
	virtual int  IsPropWritable(int)const;	//114
	virtual int  SetPropVal(int,class CValue const &);	//137
	int  TryFindFriendInterface(void);	//140
};


class IMPORT_1C CTokensBox: public CTermsBox
{
public:
	char buff[512];
	 CTokensBox(class CTokensBox const &);	//6
	 CTokensBox(void);	//7
	 ~CTokensBox(void);	//10
	class CTokensBox &  operator=(class CTokensBox const &);	//14
};

// End class descriptions
// Begin free functions definitions
// End free functions definitions


