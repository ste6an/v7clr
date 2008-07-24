// Begin forward declarations
class CGetDoc;
class CDocBoost;
class CGroupContextWrap; // ��� ������ InitTransacter
class CFormEx;

// Begin class descriptions
/*
; const CGetDoc7::`vftable'
??_7CGetDoc7@@6B@ dd offset ?GetRuntimeClass@CGetDoc7@@UBEPAUCRuntimeClass@@XZ
; DATA XREF: CGetDoc7::CGetDoc7(void)+1B6.o
; CGetDoc7::~CGetDoc7(void)+20.o
; CGetDoc7::GetRuntimeClass(void)
*/
struct SNotifyActivateOperForm
{
public:
	 SNotifyActivateOperForm(struct SNotifyActivateOperForm const &);	//52
	 SNotifyActivateOperForm(void);	//53
	 ~SNotifyActivateOperForm(void);	//99
	struct SNotifyActivateOperForm &  operator=(struct SNotifyActivateOperForm const &);	//105
};
struct SNotifyUpdateDoc
{
public:
	 SNotifyUpdateDoc(struct SNotifyUpdateDoc const &);	//54
	 SNotifyUpdateDoc(void);	//55
	struct SNotifyUpdateDoc &  operator=(struct SNotifyUpdateDoc const &);	//106
};

class IMPORT_1C CAccContext:public CBLContext
{
DECLARE_DYNCREATE(CAccContext)

public:
	 CAccContext(void);	//1
	virtual  ~CAccContext(void);	//56
	virtual int  CallAsFunc(int,class CValue &,class CValue * *);	//173
	virtual int  CallAsProc(int,class CValue * *);	//182
	class CAccSet *  GetAccSet(void);	//278
	virtual char const *  GetCode(void)const;	//289
	int  GetEnableChangeParent(void)const;	//324
	virtual void  GetExactValue(class CValue &);	//326
	int  GetFlagChoiseGroup(void)const;	//338
	virtual class CObjID   GetID(void)const;	//349
private:
	class CTypedValue *  GetPValue(int)const;	//410
public:
	virtual int  GetPropVal(int,class CValue &)const;	//424
	virtual long  GetTypeID(void)const;	//471
	class CObjID   GetUseParent(void)const;	//480
	virtual class CType   GetValueType(void)const;	//481
	virtual void  InitObject(class CType const &);	//505
	virtual void  InitObject(char const *);	//506
	void  InitOnModify(int *);	//514
	virtual int  IsExactValue(void)const;	//529
	int  IsReadOnly(void)const;	//539
	void  OnModify(void);	//685
	static void  Register(void);	//820
	virtual void  SelectByID(class CObjID,long);	//835
private:
	void  SendNotify(void);	//840
public:
	void  SetAccSet(class CAccSet *);	//842
	void  SetEnableChangeParent(int);	//872
	void  SetParent(class CObjID);	//909
	virtual int  SetPropVal(int,class CValue const &);	//914
	void  SetReadOnly(int);	//922
	void  SetStartFlagChoiseGroup(int);	//932
	void  SetUseParent(class CObjID);	//947
	static void  UnRegister(void);	//972
};


class IMPORT_1C CAllRegsContext:public CBLContext
{
DECLARE_DYNCREATE(CAllRegsContext);

//	DECLARE_DYNAMIC(CAllRegsContext)
//public:
//	static const AFX_DATA CRuntimeClass classCAllRegsContext;
//	virtual CRuntimeClass* GetRuntimeClass() const;


//	static CObject* PASCAL CreateObject();


public:
	 CAllRegsContext(void);	//2
	virtual  ~CAllRegsContext(void);	//57
	virtual int  CallAsFunc(int,class CValue &,class CValue * *);	//174
	virtual int  CallAsProc(int,class CValue * *);	//183
	virtual char const *  GetMethodName(int,int)const;	//382
	virtual int  GetNMethods(void)const;	//388
	virtual int  GetNParams(int)const;	//393
	virtual int  GetNProps(void)const;	//398
	virtual int  GetParamDefValue(int,int,class CValue *)const;	//415
	virtual char const *  GetPropName(int,int)const;	//421
	virtual int  GetPropVal(int,class CValue &)const;	//425
	virtual int  HasRetVal(int)const;	//486
	void  InitContext(void);	//496
	virtual void  InitObject(char const *);	//507
	virtual int  IsPropReadable(int)const;	//534
	virtual int  IsPropWritable(int)const;	//536
	static void  Register(void);	//821
	void  SetPostState(struct SDocPostState *);	//912
	virtual int  SetPropVal(int,class CValue const &);	//915
	int  TranPropPos(int &)const;	//966
	static void  UnRegister(void);	//973
};


class IMPORT_1C CBasicProfile
{
public:
	 CBasicProfile(void);	//3
	virtual  ~CBasicProfile(void);	//58
	class CDate   GetJournalBeg(void);	//357
	class CDate   GetJournalEnd(void);	//358
	int  GetRangeVarBeg(void);	//432
	int  GetRangeVarEnd(void);	//433
protected:
	static struct CProfileEntry7 *  s_Entries;	//1092
};


class IMPORT_1C CBrowseView7:public CBrowseView //CWnd //CObject
{
DECLARE_DYNCREATE(CBrowseView7)

public:
	DWORD buf[0x05];
	HWND hBrowse;
protected:
	 CBrowseView7(int,unsigned int);	//4
	 CBrowseView7(void);	//5
public:
	virtual  ~CBrowseView7(void);	//59
	class CGetDoc7 *  GetDocument(void)const;	//320
protected:
	void  OnControlWhatIsIt(void);	//619
	int  OnCreate(struct tagCREATESTRUCTA *);	//623
	void  OnDestroy(void);	//638
	int  OnEraseBkgnd(class CDC *);	//654
	virtual void  OnInitialUpdate(void);	//678
	long  OnPrivateSetFocus(unsigned int,long);	//723
	void  OnSStringNeedText(struct tagNMHDR *,long *);	//727
	long  OnSayAboutControl(unsigned int,long);	//728
	void  OnSetFocus(class CWnd *);	//737
	void  OnSize(unsigned int,int,int);	//744
	void  OnToolBarNeedText(struct tagNMHDR *,long *);	//763
	long  OnWMUpdateUI(unsigned int,long);	//778
	void  OnWinIniChange(char const *);	//779
	void  OnWindowPosChanging(struct tagWINDOWPOS *);	//780
public:
	void  UpdateValue(class CRect const &);	//985
protected:
	void  Update_F4_Key(class CCmdUI *);	//988

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CCalcVarSelDlg:public CDialog
{
public:
	 CCalcVarSelDlg(class CWnd *);	//6
	virtual  ~CCalcVarSelDlg(void);	//60
//	void  `default constructor closure'(void);	//144
protected:
	virtual void  DoDataExchange(class CDataExchange *);	//236
	virtual int  OnInitDialog(void);	//665
	virtual void  OnOK(void);	//697
public:
	void  SetStartType(long);	//933

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CCorrectProvContext:public CObject
{
DECLARE_DYNCREATE(CCorrectProvContext)

public:
	 CCorrectProvContext(void);	//7
	virtual  ~CCorrectProvContext(void);	//61
	virtual int  CallAsFunc(int,class CValue &,class CValue * *);	//175
	virtual int  CallAsProc(int,class CValue * *);	//184
	virtual char const *  GetMethodName(int,int)const;	//383
	virtual int  GetNMethods(void)const;	//389
	virtual int  GetNParams(int)const;	//394
	virtual int  GetNProps(void)const;	//399
	virtual int  GetParamDefValue(int,int,class CValue *)const;	//416
	virtual char const *  GetPropName(int,int)const;	//422
	virtual int  GetPropVal(int,class CValue &)const;	//426
	virtual char const *  GetTypeString(void)const;	//473
	virtual int  HasRetVal(int)const;	//487
	virtual int  IsPropReadable(int)const;	//535
	virtual int  IsPropWritable(int)const;	//537
private:
	void  P_Delete(class CValue &,class CValue * *);	//784
	void  P_Get(class CValue &,class CValue * *);	//785
	void  P_IsOK(class CValue &,class CValue * *);	//787
	void  P_New(class CValue * *);	//789
	void  P_Select(class CValue &,class CValue * *);	//792
	void  P_SelectByAcc(class CValue &,class CValue * *);	//793
	void  P_Write(class CValue &,class CValue * *);	//799
public:
	static void  Register(void);	//822
	virtual int  SetPropVal(int,class CValue const &);	//916
	static void  UnRegister(void);	//974
};


class IMPORT_1C CDocActModule: public CBLModule7
{
	// sizeof (CDocActModule) == 108h
public:
	// ���� ���������� � ������ ���������� ��������� ����������� ������� �������������������
	// = -1 - �������� ��� �� ����
	// = 1  - ���� � ������ ���������� ��������� ���� ��������� ������������������� ��� Posting
	// = 0  - ��������� �����������
	DWORD m_FlagHavingPostingProc; // +0x28

	CDocContext* pDocContext; // +0x2C

	 CDocActModule(void);	//8
	virtual  ~CDocActModule(void);	//62
	class CDocContext *  GetDocContext(void);	//315 // ������ ���������� pDocContext

	// ���������, ���� �� � ������ ���������� ��������� ���������� ������� �������������������
	// ������� ���� �������� ����� m_FlagHavingPostingProc, ���� �� �� ����� -1, �������� �� �����������
	// ���� ��������� ����, ��������������� ���� m_FlagHavingPostingProc = 1 ����� 0
	int  TestIsPostingProc(void);	//964
};


class IMPORT_1C CDocContext : public CDocContextDef
{
public:
	//DWORD buf1[7]; // 2Ch
	DWORD buf1[3]; // 2Ch
	DWORD m_dwDocIsSelect; // 38h // 0 ��� 4 - �������� �� ������
	DWORD buf2[3];
	CDocTransacter* m_pDocTransacter; // 48h
	//DWORD buf3[16];
	DWORD buf3[14];
	COperSet* m_pOperSet; // 84h
	DWORD buf4[1];
	CDocSet* m_pDocSet; // 8Ch
	DWORD data1;

DECLARE_DYNCREATE(CDocContext)

public:
friend CDocBoost;
friend CGroupContextWrap; // ��� ������ InitTransacter
//	CDocDef* pDocDef;
//	DWORD buf[100];

	 CDocContext(void);	//9
	virtual  ~CDocContext(void);	//63
	virtual int  CallAsFunc(int,class CValue &,class CValue * *);	//176
	virtual int  CallAsProc(int,class CValue * *);	//185
protected:
	virtual class CDocDef *  CurDocDef(void)const;	//219
public:
	virtual char const *  GetCode(void)const;	//290
	int  GetCurLineIdx(void)const;	//300
	virtual void  GetExactValue(class CValue &);	//327
	int  GetFlagAutoTime(void);	//337
	virtual class CObjID   GetID(void)const;	//350
private:
	class CTypedValue *  GetPTypedValue(int,int)const;	//408
public:
	virtual int  GetPropVal(int,class CValue &)const;	//427
	int  GetSelectType(void);	//455
	virtual long  GetTypeID(void)const;	//472
	class CString   GetUseKindsForChoise(void);	//478
	class CString   GetUseNumPrefix(void);	//479
	virtual class CType   GetValueType(void)const;	//482
	void  InitContext(void);	//497
	virtual void  InitObject(class CType const &);	//508
	virtual void  InitObject(char const *);	//509
	void  InitOnModify(int *,int *);	//515
	void  InitOperVal(class COperSet *);	//516
private:
	// ������� ������, �������������� ����������/������ ���������� ���������, ���� �� �� ��� ������ �����
	// � �.�. ������� ������ ���������� ���������
	void  InitTransacter(void);	//519
protected:
	int  IsDocAvailable(void)const;	//527
public:
	virtual int  IsExactValue(void)const;	//530
	int  IsNewNumSetted(void)const;	//533
	int  IsReadOnly(void)const;	//540
	void  OnModify(int)const;	//686
	static void  Register(void);	//823
	virtual void  SelectByID(class CObjID,long);	//836
private:
	void  SendNotify(void);	//841
public:
	void  SetCalcTotals(int);	//846
	void  SetCurLineIdx(int);	//858
	void  SetDocSet(class CDocSet *);	//868
	void  SetEnableDateChanging(int);	//874
	void  SetEnableNewLine(int);	//876
	void  SetFlagAutoTime(int);	//882
	void  SetOper(class CBLContext *,class COperSet *);	//905
	virtual int  SetPropVal(int,class CValue const &);	//917
	void  SetReadOnly(int);	//923
	void  SetSelectType(int);	//927
private:
	int  SkipByFilter(void);	//953
public:
	void  SyncWithOperPos(void)const;	//958
	static void  UnRegister(void);	//975
};


class IMPORT_1C CDocEnvironContext:public CBLContext
{
DECLARE_DYNCREATE(CDocEnvironContext)

public:
	 CDocEnvironContext(void);	//10
	virtual  ~CDocEnvironContext(void);	//64
	void  AfterPost(void);	//167
	void  BeforePost(void);	//169
	virtual int  CallAsFunc(int,class CValue &,class CValue * *);	//177
	virtual int  CallAsProc(int,class CValue * *);	//186
	class CAllRegsContext *  GetAllRegs(void);	//282
	int  GetFlagNotCloseDoc(void);	//340
	struct SDocPostState *  GetPostState(void);	//420
	virtual int  GetPropVal(int,class CValue &)const;	//428
	void  InitContext(void);	//498
	void  SetFlagGroupProcess(int);	//884
	void  SetFlagTotalsActual(int);	//887
	void  SetRepeatToTM(int);	//926
};


class IMPORT_1C CDocFindDlg: public CDialog
{
public:
	 CDocFindDlg(class CWnd *);	//11
	virtual  ~CDocFindDlg(void);	//65
//	void  `default constructor closure'(void);	//145
protected:
	virtual void  DoDataExchange(class CDataExchange *);	//237
private:
	void  EnableCtrls(void);	//255
protected:
	void  OnChangeDocNum(void);	//600
	void  OnDblclkDoclist(void);	//628
	void  OnDblclkDoclistFinded(void);	//629
	virtual int  OnInitDialog(void);	//666
	virtual void  OnOK(void);	//698
	void  OnOnlyInJournalRange(void);	//710
	void  OnSelchangeDoclist(void);	//731
	void  OnSelectAll(void);	//734
	void  OnStartFind(void);	//752
	void  OnUnSelectAll(void);	//766
public:
	void  SetEnv(long,class CDate,class CDate,long,class CString,long);	//877
	void  SetOnlyBookKeeping(int);	//904
	void  SetSpecTitle(class CString);	//929

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CGetField: public CObject // ������ ������ 0xA8
{
public:
	CValue* m_pValue; //0x04
	CTypedValue* m_pTypedValue; //0x08
	CMetaDataTypedObj * m_pDef; //0x0C
	CGetDoc7* m_GetDoc; //0x10
	UINT m_ID; //0x14
	CControlID* m_Set; //0x18
	int m_InTable; //0x1C // artbear - ���� ���������� ������� � ��������� �����, � ���� ������ ����� ����� ������ CBrowse
	CDate* m_PDate; //0x20
	int m_FlagSkipping; //0x24
	int m_Flag03; //0x28
	int m_Flag04; //0x2C
	int m_EnableChoiseFolder;
	int m_FixKind;
	int m_HideStateEnable;
	int m_BrOldStateEnable;
	int m_SkipMessageNotFindAcc;
	CString m_strUnk1; //0x44
	int m_Flag0B; //0x48
	int m_Flag0C; //0x4C
	int m_Flag0D; //0x50
	int m_Flag0E; //0x54

	// artbear
	// m_ParamNo - ��� ����� ����������� �������
	// ��������, ���� � ����� ���������� 2 ����������� ������� ��1 � ��2, �����
	// ���� ��������� 0, � �������� ������ �������� ����� ����� �������� �� ��1,
	// � ���� 1, �� �� ��2
	// ��������� ����� �� ������� � ���������� ���������
	int m_ParamNo; // 58h

	int m_Flag10; //0x5C
	int m_Flag11; //0x60
	CString m_strWindowName; //64h
	CString m_strCtrlTitle; //CControlID::m_Title //68h
	int m_Flag14; //0x6C
	int m_Flag15; //0x70
	int m_Flag16; //0x74
	int m_Flag17; //0x78
	int m_Flag18; //0x7C
	int m_Flag19; //0x80
	int m_RefFlag;
	int m_Flag4; //0x88
	int m_ReadOnly;
	int m_Visible;
	int m_Flag000; //0x94
	int m_Flag001; //0x98
	int m_Flag002; //0x9C
	int m_Flag003; //0xA0
	int m_QuickChoice;
//	int buf[0x0A8];
	 CGetField(void);	//22
	virtual  ~CGetField(void);	//74
	int  AvtoActivate(void);	//168
	int  CheckLinkValue(class CString,int);	//194
	int  Clear(void);	//197
	class CBLContext *  GetBLContext(void);	//285
	unsigned int  GetCtrlID(void);	//294
	class CControlID *  GetCtrlInfo(void);	//296
	class CType   GetCtrlType(void)const;	//298
	class CDate   GetDate(void);	//305
	class CMetaDataTypedObj *  GetDef(void);	//308
	class CGetDoc7 *  GetDoc(void);	//314
	int  GetEnableChoiseFolder(void);	//325
	int  GetFixKind(void);	//335
	int  GetFlagSkipping(void);	//342
	int  GetInTable(void);	//355
	class CDate *  GetPDate(void);	//407
	class CTypedValue *  GetPTypedValue(void);	//409 // return m_pTypedValue;
	class CValue *  GetPValue(void);	//411 // return m_pValue;
	int  GetParamNo(void);	//418
	int  GetQuickChoice(void)const;	//430
	virtual int  GetReadOnly(void);	//434
	int  GetUse(unsigned int,class CValue *);	//475
	int  IsBrOldStateEnable(void);	//525
	int  IsHideStateEnable(void);	//532
	int  IsStatic(void);	//544
	int  MakeUse(class CValue *,class CValue *);	//564
	void  ReCreateValue(class CType const &);	//810
	void  SetBrOldStateEnable(int);	//844
	void  SetCellReadOnly(int);	//847
	void  SetCtrlID(unsigned int);	//854
	void  SetCtrlInfo(class CControlID *);	//855
	void  SetCtrlType(class CType &);	//857
	void  SetDef(class CMetaDataTypedObj *);	//860
	void  SetDoc(class CGetDoc7 *);	//863
	void  SetEnableChoiseFolder(int);	//873
	void  SetFixKind(int);	//880
	void  SetFlagSkipping(int);	//886
	void  SetHideStateEnable(int);	//895
	void  SetInTable(int);	//898
	void  SetInternalValue(class CType const &);	//900
	void  SetPDate(class CDate *);	//906
	void  SetPValue(class CValue *);	//907
	void  SetParamNo(int);	//908
	void  SetQuickChoice(int);	//920
	void  SetReadOnly(int);	//924
	void  SetSkipMessageNotFindAcc(int);	//928
	int  TestCanClear(void);	//962
	int  TranslateType(void);	//968
	int  UpdateMask(void);	//983
	void  UpdateState(void);	//984
	int  WhantCheckLinkValue(void);	//992
};


// class IMPORT_1C CGetFieldsArray: public CObArray
// {
// public:
// 	 CGetFieldsArray(void);	//23
// 	 ~CGetFieldsArray(void);	//75
// 	class CGetField *  operator[](int)const;	//107
// 	int  AddItem(class CGetField *);	//166
// 	class CGetField *  GetAt(int)const;	//284
// 	class CGetField *  GetFieldByCtrl(unsigned int);	//330
// 	int  GetSize(void)const;	//456
// 	class CGetField *  NewItem(void);	//569
// 	void  RemoveAt(int);	//827
// };


/*
// ����. �����, ��������� ����-��
// ��� ������ �������� ������ GetDoc7, ���������� � ��������� �����. ��������� :)

// kms
// ���������� �������� � �������� CGetDoc7

class CGetDoc77:public CDocument
{
public:
	// m_Attr_01h_54h
	int m_Flag;

	// m_CtrlArray
	CObArray m_PropArray;

	int buf1[67];

	// m_cMapStringToPtr.m_pHashTable
	CHintStruct77** m_Hints;

	// m_cMapStringToPtr.m_pHashTableSize
	int m_AttrNum;

	// m_cMapStringToPtr.m_nCount
	int m_HintNum;

	int buf2[81];

	// m_cControlID1.m_Place.right
	int m_Width;

	// m_cControlID1.m_Place.bottom
	int m_Height;

	int buf4[8];

	// m_cControlID1.m_SDependParam
	char* m_Caption;

	int buf5[78];

	// m_cGetFieldsArray1
	CObArray m_Array; // ������ ���������� �������� �����
};
// end ����
*/

class IMPORT_1C CGetDoc7:public CGetDoc //CCmdTarget //CObject //CGetDoc //CGetDoc77 (����)
{
DECLARE_DYNCREATE(CGetDoc7)
public:
friend class CFormEx;

	enum MsgType {msgtOne};
//	CString mm_strTitle;
//	CString mm_strPathName;
//	CDocTemplate* mm_pDocTemplate;
//	CPtrList mm_viewList;
//	BOOL mm_bModified;
//	BOOL mm_bAutoDelete;
//	BOOL mm_bEmbedded;
//	int m_buf1;
//	CObArray mm_ctrlList;

	CString* m_pString;
	DWORD m_Flag1;
	DWORD m_Flag2;
	DWORD m_Flag3;
	DWORD m_Flag4;
	DWORD m_Flag5;
	DWORD m_Flag6;
	DWORD m_Flag7;
	DWORD m_Flag8;
	DWORD m_Flag9;
	DWORD m_Flag10;
	DWORD m_Flag11;
	DWORD m_Flag12; // D0h
	DWORD m_Flag13;
	BOOL m_Flag_DoNotSaveOpenForm; //DWORD m_Flag14;
	DWORD m_Flag15;
	DWORD m_Flag16;
	BOOL m_Flag_IsFormInsideCloseProcess; // DWORD m_Flag17;
	DWORD m_ID; // (?)
	CValueListContext* m_VTContList; //ECh

	// ����. 2 ���� m_pSavingWorkBookDoc � m_pSavingDocId ������������ � SetTableSourceForms
	CWorkBookDoc* m_pSavingWorkBookDoc; // m_pWorkBookDoc1 //F0h
	DWORD m_pSavingDocId; //DWORD m_Flag21; //F4h

	CImageList m_cImageList;
	DWORD m_Flag24;
	DWORD m_Flag25;
	DWORD m_Flag26;
	DWORD m_Flag27;
	DWORD m_Flag28;
	DWORD m_Flag29;
	DWORD m_Flag30; // 118h
	DWORD m_Flag31;
	DWORD m_Flag32;
	DWORD m_Flag33;
	CFormContext* m_pFormContext; //128h
	CGroupContext* m_pGroupContext;
	DWORD m_Flag36;
	CToolTip7 m_cToolTip7;
	DWORD m_Flag46;
	DWORD m_Flag47;
	DWORD m_Flag48;
	DWORD m_Flag49;
	DWORD m_Flag50;
	DWORD m_Flag51;
	DWORD m_Flag52;
	CMapStringToPtr m_cMapStringToPtr;
	DWORD m_Flag60;
	DWORD m_Flag61;
	DWORD m_Flag62;
	COnLineHelp m_cOnLineHelp;
	DWORD m_Flag86;
	CFntHolder7 m_cFntHolder7;
	DWORD m_Flag94;
	CAccelTable7 m_cAccelTable7;
	DWORD m_Flag96;
	CValue m_cValue;
	DWORD m_Flag119;
	DWORD m_Flag120; // 280h
	DWORD m_Flag121;
	DWORD m_Flag122;
	DWORD m_Flag123;
	DWORD m_Flag124;
	DWORD m_Flag125;
	DWORD m_Flag126;
	CTypedCont* m_pTypedCont;
	DWORD m_Flag128; // 2A0h
	DWORD m_Flag129; // 2A4h
	CControlID m_cControlID1; //2A8h
	CControlID m_cControlID2;
	CControlList m_cControlList; //0x400h // ������ - ��� CControlID*
	CEditDoc* m_pEditDoc; //[224]
	CFont m_cFont;
	CGetFieldsArray m_cGetFieldsArray1; // +42ch //������ ������ �� ��� ���� (CGetField*) ��������� (CGetDoc7)
	CGetFieldsArray m_cGetFieldsArray2; // +444h //������ ������ �� ��� ����, ����� ����� ��� �����, �����, ������
	DWORD m_Flag237;
	
 	// artbear � ��� ������ ������ ���������� CGetField-�� ������� ����� �����������
	CGetField** m_pArray_EvalStatics; // + 458h //������ ������ �� ���� ���� ����� ������� �������
	int m_nSize_pArray_EvalStatics;
	
 	//DWORD m_Flag238; // CGetDoc7:: + 458h
 	//DWORD m_Flag239; // n_size

 	DWORD m_Flag240;
 	DWORD m_Flag241;
	
	DWORD m_Flag242;
 	
	// artbear � ��� ������ ��� ���� ������ ���������� CGetField-�� ������� ����� �����������
	CGetField** m_pArray_BrowseEvalColumns; // + 46�h
	int m_nSize_pArray_BrowseEvalColumns; //470
	//DWORD m_Flag243;//
	//DWORD m_Flag244;

	DWORD m_Flag245;
	DWORD m_Flag246;
	
	DWORD m_Flag247;
	UINT m_uiToolBarPos;
	CWorkBookDoc* m_pWorkBookDoc; //484h
	ULONG m_ObjectID;
	CString m_String1;
	DWORD m_Flag252;
	DWORD m_Flag253;
	DWORD m_Flag254;
	DWORD m_Flag255;
	DWORD m_Flag256;
	CString m_ContName; //+4A4
	DWORD m_Flag258;
	DWORD m_Flag259;
	DWORD m_Flag260;
	DWORD m_Flag261;
	DWORD m_Flag262;
	DWORD m_Flag263;
	DWORD m_Flag264;
	CString m_String2;
	DWORD m_Flag266; //4C8h
	DWORD m_Flag267; //4CCh
	//DWORD m_Flag268; // 4D0h
	//DWORD m_Flag269; //4D4h
	CObject* m_pArrayOfObject; // 4D0h // artbear
	DWORD m_nSizeArrayOfObject; //4D4h // artbear

	DWORD m_Flag270;
	DWORD m_Flag271;
	CBLModule7 m_cBLModule7;
	CBLModule7* m_pBLModule; // 0x4E0 //0x11B

	DWORD bufGetDoc7[0x01]; // 0x50c //��������� ��� ������� � ��������� ����������� �� CGetDoc7
/*
+0F8h = buf[22] = CImageList
+***h = buf[34] = CFormContext*
+***h = buf[35] = CGroupContext*
+134h = buf[37] = CToolTip7
+19Ch = buf[63] = COnLineHelp
+1FCh = buf[87] = CFntHolder7
+21Ch = buf[95] = CAccelTable7
+228h = buf[98] = CValue
+2A8h = buf[130] = CControlID
+354h = buf[173] = CControlID
+404h = buf[217] = CPtrList
+424h = buf[225] = CFont
+42Ch = buf[227] = CGetFieldsArray
+480h = buf[248] = CApp7::GetToolBarPos()
+48Ch = buf[251] = CString
+4A4h = buf[257] = CString
+4C4h = buf[265] = CString
+4E0h = buf[272] = CBLModule7

+***h = buf[53]-[59] = CMapStringToPtr
+***h = buf[88]-[94] = CPtrList
+***h = buf[127] = CTypedCont*
+***h = buf[138] = ������ �� ����������� �� ���������� ��������
+***h = buf[139] = ������ �� ��������� �� ���������� ��������
+***h = buf[148] = ��������� �����
+***h = buf[168] = CPictureHolder7
+***h = buf[211] = CPictureHolder7
+***h = buf[224] = CEditDoc*
+***h = buf[225] = CFont
+***h = buf[227] = CObArray
+***h = buf[249] = CWorkBookDoc*
+***h = buf[250] = id �������
+***h = buf[257] = ������������ ������ � md
+***h = buf[282] = CBLModule7*
*/
protected:
	virtual  ~CGetDoc7(void);
	DECLARE_MESSAGE_MAP()

public:
	virtual void  SetPathName(char const *,int);	//910
	virtual int  OnNewDocument(void);	//692
	virtual int  OnOpenDocument(char const *);	//715
	virtual void  OnCloseDocument(void);	//613
	virtual int  CanCloseFrame(class CFrameWnd *);	//189
	virtual int  SaveModified(void);	//829
protected:
	virtual HACCEL  GetDefaultAccelerator(void);	//310
	virtual void  OnIdle(void);	//662
public:
	virtual class CWnd *  GetForm(void);	//343
	virtual unsigned int  OnMakeUse(unsigned int);	//683
	virtual void  OnAbortUse(void);	//570
	virtual int  UpdateData(int,unsigned int);	//980
protected:
	virtual void  OnActivateCtrl(unsigned int);	//573
public:
	virtual void  SetModify(int);	//901
	virtual int  PreTranslateMessage(struct tagMSG *);	//806
	virtual int  DataExchange(class CGetExchange *);	//221
//---------------------------------
	virtual void  UpdateDefCommand(void);	//981
protected:
	virtual void  ReallyRefresh(void);	//814
public:
	virtual void  DescribeToolBar(class CWnd *,class CToolBar7 *,unsigned int const *,int);	//229

	// ��� ������ � ������ OnStartBatch/OnEndBatch ������ ������������ ������ CExecBatchHelper � CBatchGuard
	// ���
	//	virtual void CGetDoc7::OnStartBatch(void)
		// {
		// 	m_Flag120 = 1; //mov	 dword ptr [this+280h], 1
		// 	m_Flag129 = 0;
		// 	m_pFormContext->SetEnableActivateField(1);
		// 	m_pFormContext->SetFlagsRefreshContext(2);
		// 	m_pFormContext->InitExecProcedure();
		// 	SetTableSourceForms(m_pWorkBookDoc, GetDocID());
		// 	VTSetCurrentRow();
		// }
	virtual void  OnStartBatch(void);	//751

	// OnEndBatch � ���������� 1, ��� �������� � ������ ��������� ������ �� �����.
	// OnEndBatch � ���������� 0, ��� �������� � �������� ��������� ������ �� �����.
	// ���
// 2A073F10 public: virtual void __thiscall CGetDoc7::OnEndBatch(int) proc	near
// 2A073F10
// 2A073F10 var_7C		 = dword ptr -7Ch
// 2A073F10 var_18		 = dword ptr -18h
// 2A073F10
// 2A073F10		 ;push	 esi
// 2A073F11		 ;mov	 esi, ecx
// 2A073F13		 push	 edi
// 2A073F14		 ;mov	 eax, [esi+4B8h] ; // if (!m_Flag262) goto loc_2A073FD9
// 2A073F1A		 ;test	 eax, eax	 ; Logical Compare
// 2A073F1C		 ;jz	 loc_2A073FD9	 ; Jump	if Zero	(ZF=1)
// 2A073F22		 call	 GetBrowse(void) ;  CBrowse *pBrowse = GetBrowse(); //eax
// 2A073F27		 test	 eax, eax	 ; if (!pBrowse) goto loc_2A073FD9
// 2A073F29		 jz	 loc_2A073FD9
// 2A073F2F		 ;mov	 ecx, esi
// 2A073F31		 ;call	 GetBrowse(void) ; CBrowse *pBrowse = GetBrowse(); //eax
// 2A073F36		 ;mov	 eax, [eax+20h] ; eax = pBrowse->m_hWnd;
// 2A073F39		 ;push	 eax
// 2A073F3A		 ;call	 ds:IsWindowVisible ; eax = IsWindowVisible(pBrowse->m_hWnd)
// 2A073F40		 mov	 ecx, [esi+0B8h]
// 2A073F46		 cmp	 eax, ecx	 ; Compare Two Operands
// 2A073F48		 jz	 short loc_2A073F62 ; Jump if Zero (ZF=1)
// 2A073F4A		 test	 ecx, ecx	 ; Logical Compare
// 2A073F4C		 jz	 short loc_2A073F52 ; Jump if Zero (ZF=1)
// 2A073F4E		 push	 5 ; SW_SHOW
// 2A073F50		 jmp	 short loc_2A073F54 ; Jump
// 2A073F52 ; ---------------------------------------------------------------------------
// 2A073F52
// 2A073F52 loc_2A073F52:
// 2A073F52		 push	 0 ; SW_HIDE
// 2A073F54
// 2A073F54 loc_2A073F54:
// 2A073F54		 mov	 ecx, esi
// 2A073F56		 ;call	 GetBrowse(void) ;  CBrowse *pBrowse = GetBrowse(); //eax
// 2A073F5B		 ;mov	 ecx, eax
// 2A073F5D		 ;call	 CWnd::ShowWindow(int) ; pBrowse->ShowWindow(?SW_HIDE ��� SW_SHOW?);
// 2A073F62
// 2A073F62 loc_2A073F62:
// 2A073F62		 mov	 eax, [esi+4D4h] ; if (!m_Flag269) goto loc_2A073FD9
// 2A073F68		 test	 eax, eax	 ; Logical Compare
// 2A073F6A		 jz	 short loc_2A073FD9 ; Jump if Zero (ZF=1)
// 2A073F6C		 mov	 dword ptr [esi+4C8h], 1 ; m_Flag266 = 1
// 2A073F76		 mov	 eax, [esi+4D4h] ; m_Flag269
// 2A073F7C		 xor	 edi, edi	 ; edi = 0 ������� = 0
// 2A073F7E		 test	 eax, eax	 ; Logical Compare
				// ����� � ���� �� ������
// 2A073F80		 jle	 short loc_2A073FC0 ; if (m_Flag269<=0) goto loc_2A073FC0; Jump if Less or Equal (ZF=1 | SF!=OF)
// 2A073F82
// 2A073F82 loc_2A073F82: // ������ ����� do �� �������� ������������� �����
// 2A073F82		 mov	 ecx, [esi+4D0h] ; m_Flag268
// 2A073F88		 mov	 eax, [ecx+edi*4]
// 2A073F8B		 mov	 ecx, [eax+90h]
// 2A073F91		 mov	 eax, [eax+14h]
// 2A073F94		 test	 ecx, ecx	 ; Logical Compare
// 2A073F96		 push	 eax
// 2A073F97		 ;mov	 ecx, esi
// 2A073F99		 jz	 short loc_2A073FA9 ; Jump if Zero (ZF=1)
// 2A073F9B		 ;call	 GetBrowse(void) ;  CBrowse *pBrowse = GetBrowse(); //eax
// 2A073FA0		 ;mov	 ecx, eax
// 2A073FA2		 call	 pBrowse->ShowColumn(uint)
// 2A073FA7		 jmp	 short loc_2A073FB5 ; Jump
// 2A073FA9 ; ---------------------------------------------------------------------------
// 2A073FA9
// 2A073FA9 loc_2A073FA9:
// 2A073FA9		 call	 GetBrowse(void) ;  CBrowse *pBrowse = GetBrowse(); //eax
// 2A073FAE		 mov	 ecx, eax
// 2A073FB0		 call	 pBrowse->HideColumn(uint)
// 2A073FB5
// 2A073FB5 loc_2A073FB5: while (++count < m_Flag269) // ����� �����
// 2A073FB5		 ;mov	 eax, [esi+4D4h] ; m_Flag269
// 2A073FBB		 ;inc	 edi		 ; Increment by	1
// 2A073FBC		 ;cmp	 edi, eax	 ; Compare Two Operands
// 2A073FBE		 ;jl	 short loc_2A073F82 ; Jump if Less (SF!=OF)
// 2A073FC0
// 2A073FC0 loc_2A073FC0:
// 2A073FC0		 push	 0FFFFFFFFh
// 2A073FC2		 push	 0
// 2A073FC4		 lea	 ecx, [esi+4CCh] ; m_Flag267
// 2A073FCA		 m_Flag266 = 0; //mov	 dword ptr [esi+4C8h], 0
// 2A073FD4		 call	 sub_2A035F60
// 2A073FD9
// 2A073FD9 loc_2A073FD9:
// 2A073FD9		 mov	 eax, [esp+0Ch]
// 2A073FDD		 test	 eax, eax	 ; Logical Compare
// 2A073FDF		 jz	 short loc_2A074030 ; Jump if Zero (ZF=1)
// 2A073FE1		 ;mov	 eax, [esi+4B8h] ; if(!m_Flag262) goto loc_2A074010
// 2A073FE7		 ;test	 eax, eax	 ; Logical Compare
// 2A073FE9		 ;jz	 short loc_2A074010 ; Jump if Zero (ZF=1)
// 2A073FEB		 mov	 edx, [esi]
// 2A073FED		 mov	 ecx, esi
// 2A073FEF		 call	 dword ptr [edx+60h] ;  ;	CGetDoc7::virtual
// 2A073FF2		 test	 eax, eax	 ; Logical Compare
// 2A073FF4		 jz	 short loc_2A074000 ; Jump if Zero (ZF=1)
// 2A073FF6		 ;mov	 eax, [esi+118h] ; if(!m_Flag30) goto loc_2A074010
// 2A073FFC		 ;test	 eax, eax	 ; Logical Compare
// 2A073FFE		 ;jz	 short loc_2A074010 ; Jump if Zero (ZF=1)
// 2A074000
// 2A074000 loc_2A074000:
// 2A074000		 ;mov	 ecx, esi
// 2A074002		 ;call	 GetBrowse(void) ;  CBrowse *pBrowse = GetBrowse(); //eax
// 2A074007		 ;mov	 ecx, eax
// 2A074009		 ;call	 pBrowse->RefreshAll(void)
// 2A07400E		 jmp	 short loc_2A074030 ; Jump
// 2A074010 ; ---------------------------------------------------------------------------
// 2A074010
// 2A074010 loc_2A074010:
// 2A074010		 mov	 eax, [esi]
// 2A074012		 push	 0
// 2A074014		 push	 0
// 2A074016		 push	 1
// 2A074018		 push	 1
// 2A07401A		 mov	 ecx, esi ; this
// 2A07401C		 call	 dword ptr [eax+18Ch] ;	CGetDoc7::virtual
// 2A074022		 mov	 edx, [esi]
// 2A074024		 push	 0
// 2A074026		 push	 0
// 2A074028		 mov	 ecx, esi
// 2A07402A		 call	 dword ptr [edx+0E0h] ;	Indirect Call Near Procedure
// 2A074030
// 2A074030 loc_2A074030:
// 2A074030		 ;push	 0
// 2A074032		 ;push	 0
// 2A074034		 ;mov	 ecx, esi
// 2A074036		 m_Flag120 = 0; //;mov	 dword ptr [esi+280h], 0
// 2A074040		 call	 SetTableSourceForms(NULL, 0)
// 2A074045		 ;mov	 eax, [esi+2A4h] ; if(!m_Flag129) goto loc_2A074070
// 2A07404B		 ;test	 eax, eax	 ; Logical Compare
// 2A07404D		 ;jz	 short loc_2A074070 ; Jump if Zero (ZF=1)
// 2A07404F		 ;mov	 eax, [esi+2A0h] ; m_Flag128
// 2A074055		 ;push	 eax
// 2A074056		 call	 CTemplate7::GetDocument(m_Flag128) ; CDocument * pDoc
// 2A07405B		 add	 esp, 4		 ; Add
// 2A07405E		 ;test	 eax, eax	 ; Logical Compare
// 2A074060		 ;jz	 short loc_2A074070 ; if (pDoc) pDocOrThisDoc = pDoc else pDocOrThisDoc = this
// 2A074062		 ;mov	 ecx, eax
// 2A074064		 ;call	 GetBrowse(void) ;  CBrowse *pBrowse = pDocOrThisDoc->GetBrowse(); //eax
// 2A074069		 ;mov	 ecx, eax
// 2A07406B		 call	 pBrowse->RefreshAll()
// 2A074070
// 2A074070 loc_2A074070:
// 2A074070		 ;mov	 ecx, [esi+128h] ; m_pFormContext
// 2A074076		 ;push	 0
// 2A074078		 call	 m_pFormContext->SetEnableActivateField(0) ; Call Procedure
// 2A07407D		 ;mov	 ecx, [esi+128h] ; m_pFormContext
// 2A074083		 ;push	 1
// 2A074085		 call	 m_pFormContext->SetFlagsRefreshContext(1) ; Call Procedure
// 2A07408A		 mov	 eax, [esi+128h] ; m_pFormContext
// 2A074090		 cmp	 word ptr [eax+8Ch], 0 ; Compare Two Operands
// 2A074098		 jz	 short loc_2A0740C8 ; Jump if Zero (ZF=1)
// 2A07409A		 mov	 ecx, [eax+0D8h]
// 2A0740A0		 mov	 edx, [eax+0D4h]
// 2A0740A6		 push	 ecx
// 2A0740A7		 push	 edx
// 2A0740A8		 push	 0
// 2A0740AA		 add	 eax, 80h	 ; Add
// 2A0740AF		 sub	 esp, 54h	 ; Integer Subtraction
// 2A0740B2		 mov	 ecx, esp
// 2A0740B4		 mov	 [esp+84h+var_18], esp
// 2A0740B8		 push	 eax
// 2A0740B9		 call	 CValue::CValue(CValue const &)
// 2A0740BE		 mov	 eax, [esi]
// 2A0740C0		 mov	 ecx, esi
// 2A0740C2		 call	 dword ptr [eax+188h] ;	Indirect Call Near Procedure
// 2A0740C8
// 2A0740C8 loc_2A0740C8:
// 2A0740C8		 mov	 edx, [esi+128h]
// 2A0740CE		 push	 1
// 2A0740D0		 push	 ecx
// 2A0740D1		 add	 edx, 0DCh	 ; Add
// 2A0740D7		 mov	 ecx, esp
// 2A0740D9		 mov	 [esp+90h+var_7C], esp
// 2A0740DD		 push	 edx
// 2A0740DE		 call	 CString::CString(CString const	&) ; Call Procedure
// 2A0740E3		 mov	 ecx, esi
// 2A0740E5		 call	 CGetDoc7::TrySetFocusOnCtrl(CString,int) ; Call Procedure
// 2A0740EA		 pop	 edi
// 2A0740EB		 pop	 esi
// 2A0740EC		 retn	 4		 ; Return Near from Procedure

	virtual void  OnEndBatch(int);	//645

	virtual void  OnStartRunModule(class CGetField *);	//756
	virtual void  OnEndRunModule(class CGetField *);	//648
	virtual int  MakeUseHandling(void);	//565
	virtual int  GetUseHandling(class CGetDoc7 *,class CValue *);	//477
	virtual int  OnSelectLine(void);	//736
	virtual void  DetermineDefCommand(void);	//231
	virtual void  ExternEventProcess(char const *);	//263
	virtual int  FillUseValue(class CValue *);	//274
	virtual class CDate *  GetPDate(void);	//406
	virtual int  OnGetUse(unsigned int,unsigned int,class CValue *);	//658
	virtual int  OnPermanentChoise(class CGetDoc7 *,class CValue *);	//722
	virtual void  SetDocTitle(void);	//870
	virtual int  LoadAsExternalForm(class CWorkBookDoc *,class CTemplate7 *,int,int);	//553
protected:
	virtual void  ValidateMenu(class CMenu *);	//991
	virtual int  PrepareModule(class CTxtModuleReader *);	//807
public:
	//virtual void  EmptyVirtual(void) {};
	virtual void  SetDocModify(int);	//865
	virtual class CGetField *  GetField(unsigned int);	//328
	virtual class CGetField *  GetField(char const *);	//329
	virtual class CWnd *  GetFieldWnd(class CGetField *);	//332
	virtual int  UpdateFieldValue(unsigned int,int,int);	//982
	virtual int  OnCreateFrame(class CFrameWnd *,struct CCreateContext *);	//626
	virtual class CGetField *  GetEditedValueField(void);	//322
	virtual void  PostClearField(void);	//800
	virtual void  OnButton(unsigned int);	//588
	virtual void  OnEnyChanged(unsigned int,int);	//653
	virtual int  PreCloseDoc(int);	//803
	virtual int  OnCloseForm(void);	//614
	virtual int  ActivateObj(class CValue,int,int,int);	//160
	virtual void  UpdateWatchs(int,int,int,class CGetField *);	//987
	virtual void  LinkAllFormEdits(void);	//551
	virtual int  EvalFormula(class CGetField *);	//261
	virtual int  EvalFormula(unsigned int);	//260
	virtual int  LayoutForm(class CFormView *);	//550
	virtual int  OnMessageInModalMode(struct tagMSG *);	//684
	virtual int  OnToolTipNeedText(unsigned int,class CString &);	//764
	virtual int  OnStatusBarNeedText(unsigned int,class CString &);	//757
	virtual void  OnAdjusteMenu(unsigned int,class CMenu *);	//574
	virtual int  ChangeDeleteStr(int &);	//190

protected:
	 CGetDoc7(void);	//21
	void  EnableRefresh(int);	//259
	void  GetMsgString(enum CGetDoc7::MsgType,unsigned int,class CString &);	//387
	long  GetParam(void);	//414
	int  InitStandartFields(class CGetField *,class CControlID *);	//518
	int  IsRefreshEnabled(void);	//541
	int  IsRefreshNeeded(void)const;	//542
	int  LoadDialog(long,char const *);	//554
	int  LoadForm(long,char const *);	//555
	void  OnAccelControl(unsigned int);	//571
	void  OnBrContextMenu(void);	//582
	void  OnBrowseWantChPos(void);	//586
	void  OnCancel(void);	//595
	void  OnChangeFont(class CMessage7 *,long *);	//601
	void  OnClearField(void);	//609
	void  OnCmdDoUse(void);	//615
	void  OnCmdGetUse(class CMessage7 *,long *);	//616
	void  OnEditCopy(void);	//641
	void  OnEditCut(void);	//642
	void  OnEditPaste(void);	//643
	void  OnEnter(void);	//651
	void  OnHelpTopic(void);	//661
	void  OnNotify(class CMessage7 *,long *);	//696
	void  OnOtherDocClosed(class CMessage7 *,long *);	//720
	void  OnSpecCloseDocument(void);	//749
	void  OnTabPageChanged(struct tagNMHDR *,long *);	//760
	void  OnTabPageChanging(struct tagNMHDR *,long *);	//761
	void  OnUpdateCmdButtons(class CCmdUI *);	//770
	void  RefreshStdList(void);	//819

	// ���������� �� CGetDoc7::PrepareModule c ����������� this->m_pWorkBookDoc, this->GetDocID()
	// ���������� �� CGetDoc7::PrepareModule c ����������� NULL, 0
	// ���������� �� CGetDoc7::OnStartBatch c ����������� this->m_pWorkBookDoc, this->GetDocID()
	// ���������� �� CGetDoc7::OnEndBatch c ����������� NULL, 0
	// ������������ ��� ���������� ���� m_pSavingWorkBookDoc � m_pSavingDocId
	// ����� ������ ���������:
	// � CGetDoc7 ���� 2 ������-�����: static_pSavingWorkBookDoc � static_pSavingDocId
	// � ����������� ���
	//
	// 	void  CGetDoc7::SetTableSourceForms(class CWorkBookDoc * pCWorkBookDoc, unsigned int uintDocID)
	// 	{
	// 		if (!pCWorkBookDoc)
	// 		{
	//			// �������������� ������.����� �� ����� ����������� � ������
	// 			CGetDoc7::static_pSavingWorkBookDoc = m_pSavingWorkBookDoc;
	// 			CGetDoc7::static_pSavingDocId = m_pSavingDocId;
	// 			return;
	// 		}
	//
	//		// �������� ������.����� � ����� ������
	// 		m_pSavingWorkBookDoc = CGetDoc7::static_pSavingWorkBookDoc;
	// 		m_pSavingDocId = CGetDoc7::static_pSavingDocId;
	//
	//		// ������������ ������.����� �� �����
	// 		CGetDoc7::static_pSavingWorkBookDoc = pCWorkBookDoc;
	// 		CGetDoc7::static_pSavingDocId = uintDocID;
	// 	}
	void  SetTableSourceForms(class CWorkBookDoc *,unsigned int uintDocID);	//940

	int  TestInFormulaForm(unsigned int,int &,int &);	//963
private:
	void  RedirectMessageToParentFrame(struct tagMSG *);	//816
public:
	void  CorrectActiveCtrl(void);	//201
	class CWnd *  CreateControl(class CGetField *,unsigned int,class CRect const &,class CWnd *,unsigned long,unsigned long);	//203

	// ��� DoCloseForm
	// 	{
	// 		m_Flag12 = 0;
	// 		if (m_Flag_IsFormInsideCloseProcess)
	// 			return 1;
	//
	// 		PostMessageA(GetFrame()->m_hWnd, WM_CLOSE, 0, 0);
	// 		m_Flag_IsFormInsideCloseProcess = 1;
	// 		return 1;
	// 	}
	int  DoCloseForm(void);	//235

	int  DoUse(class CValue *);	//250
	int  ExistWindow(void);	//262
	class CGetField *  GetActiveField(void);	//280
	int  GetDefButtonIndex(void);	//309
	unsigned int  GetDocID(void);	//317
	unsigned int  GetDocOwner(void);	//318
	unsigned int  GetDocOwnerCtrl(void);	//319
	class CGetField *  GetEditedField(void);	//321
	static class CGetField *  GetFieldInMakeUseHadling(void);	//331
	int  GetFlagAutoClose(void);	//336
	class CFormContext *  GetFormContext(void);	//344
	class CValue *  GetFormParam(void);	//345
	class CWnd *  GetFrame(void);	//346
	class CGroupContext *  GetGroupContext(void);	//347
	int  GetHardReadOnly(void);	//348
	class CIdleHandler *  GetIdleHandler(void);	//353
	class CImageList const &  GetImageList(void)const;	//354
	class COnLineHelp &  GetOnLineHelp(void);	//401
	int  GetOpenForChoise(void);	//402
	int  GetOpenForPermanentChoise(void);	//403
	unsigned int  GetPermanentChoise(void);	//419
	int  GetTabCtrlUsed(void);	//467
	class CToolTip7 &  GetToolTipCtrl(void);	//468
	int  HasBrowse(void)const;	//485
	void  InitControlsState(void);	//500
	void  InitFieldsState(void);	//504
	int  IsAutoSize(void);	//522
	int  IsBatchStarted(void);	//523
	int  IsBigForm(void)const;	//524
	int  IsBrowseVisible(void)const;	//526
	int  IsDocLayouted(void);	//528
	int  IsFunctionRun(void);	//531
	int  LayoutControl(class CFormView *,class CGetField *);	//547 // ��������� �������� �� �����
	int  LayoutDialog(class CFormView *);	//548
	void  OnUseLayerCalled(void);	//775
	void  ProcessSecondOpen(class CValue *);	//808
	void  Refresh(void);	//817
	void  SetBrowseVisible(int,int);	//845
	void  SetDefButtonIndex(int);	//861
	void  SetDocOwner(unsigned int,unsigned int);	//866
	void  SetFlagAutoClose(int);	//881
	void  SetFlipFlop(void);	//889
	void  SetFormParam(class CValue *);	//891
	void  SetHardReadOnly(int);	//892
	void  SetModifyFlagsByCtrl(unsigned int);	//902
	void  SetPermanentChoise(unsigned int);	//911
	void  SetTabCtrlUsed(int);	//936
	void  SetTabCtrlVisible(int);	//938
	void  SetWantActivate(int);	//948

	// ���
	// 	void  SetWantClose(int param1, BOOL Flag_DoNotSaveOpenForm)
	// 	{
	// 		m_Flag12 = param1;
	// 		m_Flag_DoNotSaveOpenForm = Flag_DoNotSaveOpenForm;
	// 	}
	void  SetWantClose(int,int);	//949

	void  SetWndCaption(char const *);	//950
	int  TestAskOnClose(void);	//960
	int  TestCanActivate(unsigned int);	//961
	void  TrySetFocusOnCtrl(class CGetField *,int);	//969
	void  TrySetFocusOnCtrl(class CString,int);	//970
	void  UDFCaption(class CString &);	//971
	void  VTSetCurrentRow(void);	//989
};

// ������ ������ 18h
class IMPORT_1C CGroupColumns
{
public:
	DWORD m_buf[5];

	CGroupColumns(void);	//25
	virtual  ~CGroupColumns(void);	//77
	void  Init(class CJournalDef *);	//493
};

struct CInternalParamsForDocForm // artbear
{
	DWORD m_Flag0;
	CValue** pValueArray; // �������� ������� �������� m_ParamNo � CGetField
};

// ������ ������ 0AA8h - artbear
class IMPORT_1C CDocForm:public CGetDoc7 //CObject
{
DECLARE_DYNCREATE(CDocForm)

	// artbear �������� �� ������ 0x4e8
	//DWORD m_buff[0x94];
	DWORD m_buff[0x71];
	CDocDataLineArray pDocDataLineArray;//6D8

	DWORD m_buff2[0x17];

	// artbear ����� �������� �������
	CGetField** m_pArrayOfEvalBrowse_Columns_GetFields; // 0x760
	int m_nArrayOfEvalBrowse_Columns_GetFields; // 0x764

	DWORD m_buff_768[0x3];

	CInternalParamsForDocForm* m_pArray; // 0x774 // �������� �������� ���� m_Field818
	DWORD m_buff_778[0x94]; // 0x778

	DWORD m_Field818; //+818h
	
protected:
	 CDocForm(void);	//12
	virtual  ~CDocForm(void);	//66
	virtual int  BufferExchange(int);	//171
public:
	virtual int  DataExchange(class CGetExchange *);	//220
	virtual void  DescribeToolBar(class CWnd *,class CToolBar7 *,unsigned int const *,int);	//228
	int  DoWriteDoc(int,int,int,class CValue *,class CString *);	//251
	int  GetChangeLineOrder(void)const;	//288
protected:
	virtual HMENU  GetDefaultMenu(void);	//311
	virtual class CDate *  GetPDate(void);	//405
	class CDocSkipper *  GetSkipper(void);	//458
public:
	void  InitTransacter(void);	//520
	virtual int  LayoutForm(class CFormView *);	//549
protected:
	virtual void  OnActivateCtrl(unsigned int);	//572
	void  OnBrChangePos(void);	//581
	void  OnBrowseAppendStart(void);	//583
	void  OnBrowseScan(void);	//584
	void  OnBrowseSetFocus(void);	//585
	virtual void  OnButton(unsigned int);	//587
	void  OnCancel(void);	//593
	virtual int  OnCancelEdit(void);	//598
	void  OnChildDocs(void);	//607
	void  OnCopy(void);	//620
	void  OnCopyOtherKind(void);	//621
	virtual void  OnCopyRec(long);	//622
	virtual int  OnDeleteRec(void);	//635
	void  OnEdit(void);	//640
public:
	virtual void  OnEndBatch(int);	//644
	virtual void  OnEndRunModule(class CGetField *);	//647
protected:
	void  OnEnter(void);	//650
public:
	virtual void  OnEnyChanged(unsigned int,int);	//652
protected:
	virtual int  OnGetUse(unsigned int,unsigned int,class CValue *);	//657
	void  OnGotoOper(void);	//659
	void  OnGotoProv(void);	//660
	void  OnInsertRec(void);	//679
	virtual unsigned int  OnMakeUse(unsigned int);	//682
	void  OnMoveLineDown(void);	//688
	void  OnMoveLineUp(void);	//689
	void  OnNewCommand(void);	//690
	virtual int  OnNewDocument(void);	//691
	virtual void  OnNewRec(void);	//694
	void  OnNotify(class CMessage7 *,long *);	//695
	void  OnOpenActs(void);	//712
public:
	virtual int  OnOpenDocument(char const *);	//714
protected:
	void  OnOpenOper(void);	//717
	void  OnOpenProvs(void);	//718
	virtual void  OnRead(int);	//725
	void  OnRenumber(void);	//726
	void  OnSortDescLines(void);	//747
	void  OnSortLines(void);	//748
public:
	virtual void  OnStartBatch(void);	//750
	virtual void  OnStartRunModule(class CGetField *);	//755
protected:
	virtual int  OnStoreRec(void);	//758
	void  OnUpdateCmdButtons(class CCmdUI *);	//769
	void  OnWrite(void);	//781
public:
	virtual int  PreCloseDoc(int);	//802
	virtual void  ReallyRefresh(void);	//813
	void  SetChangeLineOrder(int);	//848
	void  SetChanges(class CGetField *);	//849
	virtual void  SetDocTitle(void);	//869
protected:
	void  SortLines(int);	//954
	void  SpecNewRec(void);	//955
public:
	virtual void  UpdateWatchs(int,int,int,class CGetField *);	//986
protected:
	virtual void  ValidateMenu(class CMenu *);	//990

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CDocListPos
{
public:
	 CDocListPos(class CDocListPos const &);	//13
	 CDocListPos(void);	//14
	 ~CDocListPos(void);	//67
	class CDocListPos &  operator=(class CDocListPos const &);	//100
};


class IMPORT_1C CDocSetSelectDlg:public CDialog
{
public:
	 CDocSetSelectDlg(class CWnd *);	//15
	virtual  ~CDocSetSelectDlg(void);	//68
//	void  `default constructor closure'(void);	//146
protected:
	virtual void  DoDataExchange(class CDataExchange *);	//238
	void  EnableCtrls(void);	//256
public:
	class CSelState *  GetState(long);	//460
protected:
	virtual void  InitDialog(int &,class CString);	//501
	void  OnAutoScan(void);	//575
	void  OnButtonClickedValue(void);	//589
	void  OnButtonClickedValueBeg(void);	//591
	void  OnButtonClickedValueEnd(void);	//592
	virtual void  OnCancel(void);	//594
	void  OnClearSelect(void);	//610
	void  OnDblclkRekvList(void);	//631
	void  OnDblclkValueList(void);	//633
	virtual int  OnInitDialog(void);	//667
	virtual void  OnOK(void);	//699
	void  OnOkValue(void);	//708
	void  OnOnlyInJournalRange(void);	//711
	virtual void  OnSelSelectType(void);	//729
	void  OnSelchangeRekvList(void);	//732
	void  OnStartFind(void);	//753
	void  OnUseRange(void);	//776
	void  OnUseValue(void);	//777
public:
	void  SetEnv(long,class CValue,long *,class CValue *,class CDate,class CDate,class CString);	//878
protected:
	virtual int  StartFind(void);	//956
public:
	static class CSelStateArray  m_StateArray;	//1070

	DECLARE_MESSAGE_MAP()
};


// �����, �������������� ����������/������ ���������� ���������
//
class IMPORT_1C CDocTransacter
{
public:
	//DWORD buf[3];
	//CDocActions m_DocActions; // 0Ch

	 CDocTransacter(class CDocSet *,class COperSet *);	//16
	 ~CDocTransacter(void);	//69
//	void  `default constructor closure'(void);	//147
	int  ClearDocPosting(int);	//198
	int  DeleteDocActs(void);	//224
	int  DoMakeTransactions(int,class CValue *,int);	//249

	// � GetAt ���������� -1 ������ �������� ���������, 0-n ������ ���� ���������� ������������ �� ������ ����������
	class CDocActModule *  GetAt(int);	//283

	// ���������� GetAt(-1)->pDocContext
	class CDocContext *  GetDocContext(void);	// ??

	static struct SDocPostState *  GetCurrentPostState(void);	//303
	int  GetLastPostingType(void);	//360
	int  Init(int);	//491
	int  InitAll(void);	//495
	void  InitContexts(void);	//499
private:
	int  MakeActionsDocAddToStream(int);	//560
	int  MakeActionsDocBeforeTM(int);	//561
public:
	int  MakePosting(void);	//562
	int  MakeUnPosting(void);	//563
private:
	void  Message(class CString);	//566
public:
	void  SetDocFormID(unsigned int);	//864
	void  SetDocOwnerID(unsigned int);	//867
	void  SetFlagNewDoc(int);	//885
	void  SetInteractive(int);	//899
	void  SetPostingInStream(int);	//913
	void  SetRePostingInStream(int);	//921
	static int  flPosting;	//1068
	static class CObjID  sCurrentDocIDForCalc;	//1091
private:
	static struct SDocPostState *  s_pCurrentPostState;	//1093
};

class IMPORT_1C CFormCtrlContext:public CBLContext
{
DECLARE_DYNCREATE(CFormCtrlContext)

public:
	CGetField* m_pGetField; //20h //CFormCtrl* m_Ctrl; //��������� �� ������������� ������� �����

	//CGetDoc77* m_GetDoc; //24h // ���� - ��������� �� �������� ������ GetDoc7
	CGetDoc7* m_GetDoc; // ���� - ��������� �� �������� ������ GetDoc7 artbear

	int m_Flag;
};

// artbear ������ ������ 4x50h - basic.dll ����� 2A039046
class IMPORT_1C CFormAllCtrlsContext:public CBLContext
{
DECLARE_DYNCREATE(CFormAllCtrlsContext)

public:
	CFormCtrlContext** m_Data1; // ��������� �� ������ ��������� ����� // +24h
	void* m_Data2; // +28h
	CValueListContext *m_TabCtrlListContext; // +2Ch
	void* m_Data4; // +30h

	// �� ���������� ������ �� ����-� � �������� ���������� 1�++ ��� ��������� �� GetDoc7
	//CGetDoc77* m_GetDoc; // ���� - ��������� �� �������� ������ GetDoc7
	CGetDoc7* m_GetDoc; // ���� - ��������� �� �������� ������ GetDoc7  // +34h
	//CPtrArray m_PropArray; // ������ ���������� �� ������������� �������� �����
	CGetFieldsArray m_GetFieldsArray; //  // +38h
	int m_Flag1;
	int m_Flag2;
};

// kms
class IMPORT_1C CFormContext:public CBLContext
{
DECLARE_DYNCREATE(CFormContext)

public:
	CStringArray m_StringArray;
	CByteArray m_ByteArray;
	CFormAllCtrlsContext* m_pForm;
	CGetDoc7 *m_pDocFC; // CReportForm / CSubcForm //4Ch

	// artbear
// 	DWORD m_object1; // 50h
// 	CGetField** m_pGetFieldsArray; // ���������� ����� new
// 	DWORD m_sizeFieldsArray; //58h
// 	DWORD m_dummy_5C; // ������������ ���������� ����-�� 
// 	DWORD m_dummy_60;
	CGetFieldsArray m_GetFieldsArray;
	 
	CDWordArray m_DWordArray; //64h // � �������� �������� ������������ ������ � m_pDoc->m_CGetFieldsArray2

	// �������� ������� ����� ���� 1 ��� 2
	int* m_pArrayOfFlagsRefresh; // �� 0 �� m_sizeFieldsArray-1 // 78h
	// end

	// Trad
	BOOL m_EnableActivateField;
	DWORD data1[15];
	CString m_str1;
	DWORD data2[7];
	CString m_str2;

public:
	CFormContext(void);	//17
	virtual  ~CFormContext(void);	//70

//	virtual int  CallAsFunc(int,class CValue &,class CValue * *);	//178
//	virtual int  CallAsProc(int,class CValue * *);	//187
//	virtual int  GetNProps(void)const;	//400
//	virtual char const *  GetPropName(int,int)const;	//423
//	virtual int  GetPropVal(int,class CValue &)const;	//429
//	class CValueListContext *  GetTabCtrlListContext(void);	//466
//	virtual int  IsPropWritable(int)const;	//538
//	virtual int  SetPropVal(int,class CValue const &);	//918

	int  GetEnableActivateField(void);	//323
	int  InitExecProcedure(void);	//503
	void  OnInitForm(void);	//677
	int  SetEnableActivateField(int);	//871
	void  SetFlagsRefreshContext(int);	//888

protected:
	// ��������� �������
	virtual int  TranPropPos(int &)const;	//967
	virtual void SetForm(class CGetDoc7 *);	//890
};

// trad - ��� ������� � ��� DECLARE_DYNCREATE(CFormContextForDoc)
// class CFormContextForDoc : public CBLContext
// artbear ������ ������ 4x0E4h - basic.dll ����� 2A038E56
class IMPORT_1C CFormContextForDoc:public CBLContext
{
DECLARE_DYNCREATE(CFormContextForDoc)
public:
	CStringArray m_StringArray;
	CByteArray m_ByteArray;
	CFormAllCtrlsContext* m_pForm;
	CDocForm* m_pDocForm; // CGetDoc7 *m_pDocFC; // CDocForm
	CArray<void*, void*> m_UnkArray;
	CDWordArray m_DWordArray;
	DWORD m_data1;
	DWORD m_data2;
	CValue m_value;
	DWORD m_data3;
	DWORD m_data4;
	CString m_str;
	CDocContext* m_pDocContext;

public:
	CFormContextForDoc(void);
	virtual  ~CFormContextForDoc(void);
/*
	virtual void			IncrRef(void);
	virtual void			DecrRef(void);
	virtual int				GetDestroyUnRefd(void)const;
	virtual int				IsOleContext(void)const;
	virtual CType			GetValueType(void)const;	//2547
	virtual long			GetTypeID(void)const;	//2505
	virtual CObjID			GetID(void)const;	//1804
	virtual char const *	GetCode(void)const;	//1544
	virtual int				IsExactValue(void)const;	//2808
	virtual void			InitObject(char const *);	//2722
	virtual void			InitObject(class CType const &);	//2721
	virtual void			SelectByID(CObjID,long);	//3350
	virtual char const *	GetTypeString(void)const;	//2513
	virtual int				GetNProps(void)const;	//2015
	virtual int				FindProp(char const *)const;	//1369
	virtual char const *	GetPropName(int,int)const;	//2187
	virtual int				GetPropVal(int,CValue &)const;	//2221
	virtual int				SetPropVal(int,CValue const &);	//3694
	virtual int				IsPropReadable(int)const;	//2863
	virtual int				IsPropWritable(int)const;	//2865
	virtual int				GetNMethods(void)const;	//2005
	virtual int				FindMethod(char const *)const;	//1366
	virtual char const *	GetMethodName(int,int)const;	//1964
	virtual int				GetNParams(int)const;	//2008
	virtual int				GetParamDefValue(int,int,CValue *)const;	//2122
	virtual int				HasRetVal(int)const;	//2657
	virtual int				CallAsProc(int,CValue * *);	//937
	virtual int				CallAsFunc(int,CValue &,CValue * *);	//935
	virtual int				IsSerializable(void);	//2874
	virtual int				SaveToString(CString &);	//3295
	virtual class			CBLContextInternalData *  GetInternalData(void);	//1826
	virtual void			GetExactValue(CValue &);	//1708
*/
protected:
	virtual int	TranPropPos(int &)const;	//967
	virtual void SetForm(class CGetDoc7 *);	//890
};


class IMPORT_1C CGenericTAControl
{
public:
	 CGenericTAControl(class CGenericTAControl const &);	//18
	 CGenericTAControl(void);	//19
	virtual  ~CGenericTAControl(void);	//71
	class CGenericTAControl &  operator=(class CGenericTAControl const &);	//101
	virtual int  ChangeTA(class CDate,class CEventTime,int,int *,int *,int,int *);	//192
	static class CGenericTAControl *  GetTAControl(void);	//463
	static void  SetTAControl(class CGenericTAControl *);	//935
private:
	static class CGenericTAControl *  s_pTAControl;	//1094
};


class IMPORT_1C CGetDlg:public CDialog //CObject
{
DECLARE_DYNAMIC(CGetDlg)

public:
	CValue* m_pValue;
	DWORD bufGetDlg[0x80]; //+60h
	UINT m_TemplID;
	DWORD m_dwFlag1;
	DWORD m_dwFlag2;
	CString m_cStr;
	CGetDoc7* m_pDoc;
	DWORD m_dwFlag3;
	DWORD m_dwFlag4;

	virtual  ~CGetDlg(void);	//72
	virtual int  OnCmdMsg(unsigned int,int,void *,struct AFX_CMDHANDLERINFO *);	//617

	DECLARE_MESSAGE_MAP()

protected:
	virtual void  DoDataExchange(class CDataExchange *);	//239
	void OnNotifyGetDoc7TabCtrlSize(class CMessage7 *,long *);
public:
	virtual int  PreTranslateMessage(struct tagMSG *);	//805
protected:
	virtual int  OnInitDialog(void);	//668

	void  OnClose(void);	//612
	void  OnDestroy(void);	//639
	long  OnKickIdle(unsigned int,long);	//681
	void  OnSetFocus(class CWnd *);	//738
	void  OnSize(unsigned int,int,int);	//745
	void  OnTabPageBack(void);	//759
	void  OnTabPageForward(void);	//762
	static long  m_lParam;	//1072
public:
	 CGetDlg(unsigned int,class CWnd *);	//20
	void  FlipToolBar(int);	//275
	static long  GetLParam(void);	//359
	class CTabCtrl *  GetTabControl(void);	//464
	static class CGetDoc7 *  GetTopmostDocunent(void);	//469
	int  IsTabCtrlVisible(void);	//545
	static void  OpenDocumentFileEx(unsigned int,char const *,long,class CValue *,unsigned int,unsigned int,unsigned int,unsigned int);	//782
	void  SetTabCtrlVisible(int);	//937

	friend class CService;
};

class IMPORT_1C CGroupColumn
{
public:
	 CGroupColumn(void);	//24
	 ~CGroupColumn(void);	//76
	class CGroupColumn &  operator=(class CGroupColumn const &);	//102
	class CTypedValue *  Connect(class CDocSet *);	//199
	int  GetAlign(void)const;	//281
	unsigned int  GetCtrlID(void)const;	//295
	class CTypedValue *  GetPValue(void)const;	//412
	void  Init(class CMetaDataRefObj *,unsigned int);	//492
};

class IMPORT_1C CInputSbKindDlg
{
public:
	 CInputSbKindDlg(class CWnd *);	//26
	virtual  ~CInputSbKindDlg(void);	//78
//	void  `default constructor closure'(void);	//149
protected:
	virtual void  DoDataExchange(class CDataExchange *);	//240
	virtual int  OnInitDialog(void);	//669
	virtual void  OnOK(void);	//700
public:
	void  SetStart(class CObjID,long,class CString);	//930

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CJournalOptDlg: public CDialog
{
public:
	 CJournalOptDlg(class CWnd *);	//27
	virtual  ~CJournalOptDlg(void);	//79
//	void  `default constructor closure'(void);	//150
protected:
	virtual void  DoDataExchange(class CDataExchange *);	//241
	void  OnBegdateButton(void);	//578
	void  OnEnddateButton(void);	//649
	virtual int  OnInitDialog(void);	//670
	virtual void  OnOK(void);	//701

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CJournalSelDlg
{
public:
	 CJournalSelDlg(class CWnd *);	//28
	virtual  ~CJournalSelDlg(void);	//80
//	void  `default constructor closure'(void);	//151
protected:
	virtual void  DoDataExchange(class CDataExchange *);	//242
	virtual int  OnInitDialog(void);	//671
	virtual void  OnOK(void);	//702
public:
	void  SetStartType(long);	//934

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CPictureColumn:public CObject
{
DECLARE_DYNAMIC(CPictureColumn)

public:
	 CPictureColumn(class CGetDoc7 *,unsigned int,char const *,int);	//29
	virtual  ~CPictureColumn(void);	//81
	virtual int  DrawItem(class CDC &,class CRect &,class CString &,int);	//253
};


class IMPORT_1C CPlanKindContext:public CObject
{
DECLARE_DYNCREATE(CPlanKindContext)

public:
	 CPlanKindContext(void);	//30
	virtual  ~CPlanKindContext(void);	//82
	virtual int  CallAsFunc(int,class CValue &,class CValue * *);	//179
	virtual char const *  GetCode(void)const;	//291
	virtual class CObjID   GetID(void)const;	//351
	virtual char const *  GetMethodName(int,int)const;	//384
	virtual int  GetNMethods(void)const;	//390
	virtual int  GetNParams(int)const;	//395
	virtual class CType   GetValueType(void)const;	//483
	virtual int  HasRetVal(int)const;	//488
	virtual void  InitObject(class CType const &);	//510
	virtual void  InitObject(char const *);	//511
	static void  Register(void);	//824
	virtual void  SelectByID(class CObjID,long);	//837
	static void  UnRegister(void);	//976
};


class IMPORT_1C CPlanSelDlg
{
public:
	 CPlanSelDlg(class CWnd *);	//31
	virtual  ~CPlanSelDlg(void);	//83
//	void  `default constructor closure'(void);	//152
protected:
	virtual void  DoDataExchange(class CDataExchange *);	//243
	virtual int  OnInitDialog(void);	//672
	virtual void  OnOK(void);	//703
public:
	void  SetStart(long,int,class CString);	//931

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CRefIntegDlg
{
public:
	 CRefIntegDlg(class CRefIntegrity *);	//32
	virtual  ~CRefIntegDlg(void);	//84
	virtual int  DestroyWindow(void);	//230
protected:
	virtual void  DoDataExchange(class CDataExchange *);	//244
	virtual void  OnCancel(void);	//596
	void  OnCheckRef(void);	//606
	void  OnChkChangedDelDoc(void);	//608
	void  OnDblclkDelDocList(struct tagNMHDR *,long *);	//627
	void  OnDblclkRefdocList(struct tagNMHDR *,long *);	//630
	void  OnGetMinMaxInfo(struct tagMINMAXINFO *);	//656
	virtual int  OnInitDialog(void);	//673
	void  OnItemchangedDeldocList(struct tagNMHDR *,long *);	//680
	virtual void  OnOK(void);	//704
	void  OnOpenDel(void);	//713
	void  OnOpenRef(void);	//719
	void  OnSelectAll(void);	//735
	void  OnShowDelCheck(void);	//741
	void  OnShowNondelCheck(void);	//742
	void  OnSize(unsigned int,int,int);	//746
	int  OnToolTipNotify(unsigned int,struct tagNMHDR *,long *);	//765
	void  OnUnSelectAll(void);	//767
	virtual void  PostNcDestroy(void);	//801

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CRepHistory
{
public:
	CItemList m_ItemList;
	//long m_Flag;
	CGetDoc7 *m_pDoc;
	CString m_strDefName;
	CString m_strName;
	DWORD m_ID;

	 CRepHistory(long,class CGetDoc7 *);	//33
	 CRepHistory(void);	//34
	 ~CRepHistory(void);	//85
	int  EditName(void);	//254
protected:
	virtual class CString   GetFileName(void);	//333
public:
	int  Init(long,class CGetDoc7 *);	//494
	int  Load(void);	//552
	int  Read(void);	//812
	int  Save(void);	//828
	int  SelectName(void);	//839
	int  Write(void);	//993
};


class IMPORT_1C CSbCntSetSelectDlg
{
public:
	 CSbCntSetSelectDlg(class CWnd *);	//35
	virtual  ~CSbCntSetSelectDlg(void);	//86
//	void  `default constructor closure'(void);	//153
protected:
	virtual void  DoDataExchange(class CDataExchange *);	//245
	void  EnableCtrls(void);	//257
public:
	class CSelState *  GetState(long);	//461
protected:
	virtual void  InitDialog(int &,class CString);	//502
	void  OnAutoScan(void);	//576
	void  OnButtonClickedValue(void);	//590
	virtual void  OnCancel(void);	//597
	void  OnClearSelect(void);	//611
	void  OnDblclkRekvList(void);	//632
	void  OnDblclkValueList(void);	//634
	void  OnInParent(void);	//664
	virtual int  OnInitDialog(void);	//674
	virtual void  OnOK(void);	//705
	void  OnOkValue(void);	//709
	virtual void  OnSelSelectType(void);	//730
	void  OnSelchangeRekvList(void);	//733
	void  OnStartFind(void);	//754
public:
	void  SetEnv(class CSbCntSet *,long,class CValue,long *,class CValue *,class CString);	//879
protected:
	virtual int  StartFind(void);	//957
public:
	static class CSelStateArray  m_StateArray;	//1071

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CSbKindContext:public CBLContext
{
DECLARE_DYNCREATE(CSbKindContext)

public:
	 CSbKindContext(void);	//36
	virtual  ~CSbKindContext(void);	//87
	virtual int  CallAsFunc(int,class CValue &,class CValue * *);	//180
	virtual char const *  GetCode(void)const;	//292
	virtual class CObjID   GetID(void)const;	//352
	virtual char const *  GetMethodName(int,int)const;	//385
	virtual int  GetNMethods(void)const;	//391
	virtual int  GetNParams(int)const;	//396
	class CObjID   GetUseAccount(void);	//476
	virtual class CType   GetValueType(void)const;	//484
	virtual int  HasRetVal(int)const;	//489
	virtual void  InitObject(class CType const &);	//512
	virtual void  InitObject(char const *);	//513
	static void  Register(void);	//825
	virtual void  SelectByID(class CObjID,long);	//838
	void  SetUseAccount(class CObjID);	//946
	static void  UnRegister(void);	//977
};


class IMPORT_1C CSelHistDlg
{
public:
	 CSelHistDlg(class PSelHistItemArray *,class CWnd *);	//37
	virtual  ~CSelHistDlg(void);	//88
protected:
	virtual void  DoDataExchange(class CDataExchange *);	//246
public:
	int  GetSelIdx(void);	//454
protected:
	virtual int  OnInitDialog(void);	//675
	virtual void  OnOK(void);	//706

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CSelHistHolder
{
public:
	 CSelHistHolder(int,class CProfile7 *);	//38
	 CSelHistHolder(class CString);	//39
	 ~CSelHistHolder(void);	//89
	void  Add(long,class CValue &,class CString);	//165
	class CSelHistItem *  Choise(void);	//196
	void  DeleteAt(int);	//222
	int  GetSize(void);	//457
	void  LoadFromString(char const *);	//557
	void  SaveToString(class CString &);	//832
};


class IMPORT_1C CSelHistItem
{
public:
	 CSelHistItem(class CSelHistItem const &);	//40
	 CSelHistItem(void);	//41
	 ~CSelHistItem(void);	//90
	class CSelHistItem &  operator=(class CSelHistItem const &);	//103
};


class IMPORT_1C CSelState
{
public:
	 CSelState(class CSelState const &);	//42
	 CSelState(long,class CType);	//43
	 ~CSelState(void);	//91
	class CSelState &  operator=(class CSelState const &);	//104
//	void  `default constructor closure'(void);	//154
	void  SetType(class CType,int,int,int);	//944
};


class IMPORT_1C CSelStateArray
{
public:
	 CSelStateArray(void);	//44
	 ~CSelStateArray(void);	//92
	class CSelState *  GetState(long);	//462
};


class IMPORT_1C CSetDateRangeDlg:public CObject
{
DECLARE_DYNCREATE(CSetDateRangeDlg)

public:
	 CSetDateRangeDlg(class CDate &,class CDate &,int,class CWnd *);	//45
	 CSetDateRangeDlg(class CWnd *);	//46
	virtual  ~CSetDateRangeDlg(void);	//93
//	void  `default constructor closure'(void);	//155
protected:
	void  CalcRealDate(void);	//172
	void  ChangeRange(int);	//191
	virtual void  DoDataExchange(class CDataExchange *);	//247
public:
	void  GetRange(class CDate &,class CDate &);	//431
	void  InitRange(class CDate &,class CDate &);	//517
protected:
	int  MonthChange(void);	//568
	void  OnBegDateButton(void);	//577
	void  OnChangeData(void);	//599
	void  OnChangeRange(void);	//602
	void  OnCheckBegMonth(void);	//603
	void  OnCheckBegQuart(void);	//604
	void  OnCheckBegYear(void);	//605
	void  OnDeltaposSpinMr(struct tagNMHDR *,long *);	//636
	void  OnDeltaposSpinQr(struct tagNMHDR *,long *);	//637
	void  OnEndDateButton(void);	//646
	virtual int  OnInitDialog(void);	//676
	void  OnMonthChange(void);	//687
	virtual void  OnOK(void);	//707
	void  OnQuartChange(void);	//724
	void  OnSingleDateButton(void);	//743
	int  QuartChange(void);	//809
public:
	void  SetCheckLevel(int);	//850
protected:
	void  SetMonthPresent(void);	//903
	void  SetQuartPresent(void);	//919
	void  SetRealPresent(void);	//925
public:
	void  SetTitle(class CString const &);	//941

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CTabFrame:public CChildFrame7//CObject
{
DECLARE_DYNCREATE(CTabFrame)
public:
	DWORD buff1[0x05]; // (338h - 280h) / 4
	CImageList cImageList;
	DWORD dwFlag1;
	CString strFlag;
	DWORD dwFlag2;
	CFont cFont;
	DWORD buff2[0x22]; // (338h - 280h) / 4
protected:
	 CTabFrame(void);	//47
	virtual  ~CTabFrame(void);	//94
public:
	virtual class CDocument *  GetActiveDocument(void);	//279
	class CTabCtrl *  GetTabControl(void);	//465
	int  IsTabCtrlVisible(void);	//546
protected:
	void  OnBookToPageBack(void);	//579
	void  OnBookToPageForward(void);	//580
public:
	virtual int  OnCmdMsg(unsigned int,int,void *,struct AFX_CMDHANDLERINFO *);	//618
protected:
	int  OnCreate(struct tagCREATESTRUCTA *);	//624
	virtual int  OnCreateClient(struct tagCREATESTRUCTA *,struct CCreateContext *);	//625
	long  OnIdleUpdateCmdUI(unsigned int,long);	//663
	void  OnUpdateBookToPage(class CCmdUI *);	//768
public:
	virtual void  RecalcLayout(int);	//815
	void  SetActiveDocument(class CDocument *);	//843
	void  SetTabCtrlVisible(int);	//939

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CUserHelpTitle:public CObject
{
DECLARE_DYNAMIC(CUserHelpTitle)

public:
	 CUserHelpTitle(void);	//48
	virtual  ~CUserHelpTitle(void);	//95
	virtual int  Create(unsigned long,class CRect const &,class CWnd *);	//202
protected:
	void  OnPaint(void);	//721
	long  OnSetFontToHider(unsigned int,long);	//739
	long  OnSetText(unsigned int,long);	//740
	virtual int  PreCreateWindow(struct tagCREATESTRUCTA &);	//804
public:
	void  SetDark(int,int);	//859
	void  SetImage(int,int);	//896
	void  SetImageList(unsigned int,int);	//897
	void  SetTitle(class CString const &,int);	//942

	DECLARE_MESSAGE_MAP()
};


class IMPORT_1C CUsrHelpDoc:public CObject
{
DECLARE_DYNCREATE(CUsrHelpDoc)

protected:
	 CUsrHelpDoc(void);	//49
public:
	virtual  ~CUsrHelpDoc(void);	//96
	virtual int  DoFileSave(void);	//248
	static unsigned int  DocID;	//252
	class CCycleStack *  GetStack(void);	//459
	static int  InitUserHelp(long,int);	//521
protected:
	void  OnFileClose(void);	//655
	virtual int  OnNewDocument(void);	//693
public:
	virtual int  OnOpenDocument(char const *);	//716
protected:
	void  OnUpdateFileClose(class CCmdUI *);	//771
	void  OnUpdateFileSave(class CCmdUI *);	//772
	void  OnUpdateFileSaveAs(class CCmdUI *);	//773
	void  OnUpdateModified(class CCmdUI *);	//774
public:
	virtual int  SaveModified(void);	//830
	int  SetHelpItem(long);	//893
	void  SetHelpTitle(char const *,class CWnd *);	//894
	virtual void  SetTitle(char const *);	//943
	long  ShowDocument(class CDocTemplate *,int,long);	//951

	DECLARE_MESSAGE_MAP()
};


// ������ ������ � �������� "��������������" ��� � �������� �++, � �� ����� ��������
// ����� ���������� � ������ � 1CPP_ODBCRecordSet.cpp
class IMPORT_1C CValueListContext:public CBLContext //CObject
{
DECLARE_DYNCREATE(CValueListContext)

public:
	char buf1[4];
	HWND m_hListWnd;
	char buf2[8];
	CPtrArray* m_pValueItemList;
	char buf3[12];

	 CValueListContext(void);	//50
	virtual  ~CValueListContext(void);	//97
	virtual int  CallAsFunc(int,class CValue &,class CValue * *);	//181
	virtual int  CallAsProc(int,class CValue * *);	//188
protected:
	class CValue   F_Belong(class CValue * *);	//264
	class CValue   F_Check(class CValue * *);	//265
	class CValue   F_CheckValues(class CValue * *);	//266
	class CValue   F_ChoiseValue(class CValue * *);	//267
	class CValue   F_FindElement(class CValue * *);	//268
	class CValue   F_FromDelimStr(class CValue * *);	//269
	class CValue   F_Get(class CValue * *);	//270
	class CValue   F_GetByTitle(class CValue * *,class CValue &);	//271
	class CValue   F_GetSize(class CValue * *);	//272
	class CValue   F_ToDelimStr(class CValue * *);	//273
public:
	void  FromList(class CItemList const &);	//276
	int  GetCtrlSel(void);	//297
	int  GetCurPosAndValue(class CValue &,class CValue &);	//301
	virtual class CBLContextInternalData *  GetInternalData(void);	//356
	static char const *  GetListFunctor(void);	//361
	virtual char const *  GetMethodName(int,int)const;	//386
	virtual int  GetNMethods(void)const;	//392
	virtual int  GetNParams(int)const;	//397
	//class PValueItem *  GetPValueList(void);	//413
	CArray<class CValueItem *,class CValueItem *>* GetPValueList(void);
	virtual int  GetParamDefValue(int,int,class CValue *)const;	//417
	virtual char const *  GetTypeString(void)const;	//474
	virtual int  HasRetVal(int)const;	//490
	virtual int  IsSerializable(void);	//543
	int  LoadFromList(class CItemList *,int);	//556
protected:
	void  P_Add(class CValue * *);	//783
	void  P_Insert(class CValue * *);	//786
	void  P_MoveValue(class CValue * *);	//788
	void  P_Remove(class CValue * *);	//790
	void  P_RemoveAll(class CValue * *);	//791
	void  P_Set(class CValue * *);	//794
	void  P_SetByTitle(class CValue * *);	//795
	void  P_Sort(class CValue * *);	//796
	void  P_SortByPresent(class CValue * *);	//797
	void  P_Unload(class CValue * *);	//798
public:
	void  RefreshCtrl(void);	//818
	static void  Register(void);	//826
	int  SaveToList(class CItemList *);	//831
	virtual int  SaveToString(class CString &);	//833
	void  SetCtrl(HWND);	//852
	void  SetCtrl(class CWnd *);	//853
	int  SetCtrlSel(int);	//856
	void  SetUpdateChecks(int);	//945
	void  ToList(class CItemList &);	//965
	static void  UnRegister(void);	//978
	void  UpdateChecks(void);	//979

protected:
	class CValue   get_set_CurSel(class CValue * *);	//1069
};


class IMPORT_1C CVarHistory
{
public:
	 CVarHistory(void);	//51
	 ~CVarHistory(void);	//98
protected:
	virtual class CString   GetFileName(void);	//334
};

//this class not in export
class CPictureContext : public CBLContext
{
    DECLARE_DYNCREATE(CPictureContext);
public:
    CPictureHolder7 m_PictureHolder7;
};

// End class descriptions
// Begin free functions definitions
IMPORT_1C class CAccDoc * __cdecl ActivateAccList(long,long,unsigned int,unsigned int,class CObjID,class CDate,int,int,long,int,class CValue *,class CString,int,int,class CString,class CString,class CObjID,int,int,class CObjID const &,int,class CValue *);
IMPORT_1C class CGetDoc7 * __cdecl ActivateDocForm(long,class CObjID,long,unsigned int,class CObjID,long,int,long,int,int,int,int,class CValue *,class CValue *);
IMPORT_1C class CJournalDoc * __cdecl ActivateDocList(long,long,class CObjID,unsigned int,unsigned int,class CObjID,class CString,class CDate,int,int,int,class CValue *,class CString,int,long,long,int,int,class CString,class CValue *);
IMPORT_1C class CGetDoc7 * __cdecl ActivateObj(class CValue *);
IMPORT_1C int __cdecl ActivateRegActDoc(long,class CObjID,int,int);
IMPORT_1C class CReportForm * __cdecl ActivateReportForm(long,class CString,int,unsigned int,unsigned int,int,int,class CString,class CValue *,int *,class CValue *);
IMPORT_1C int __cdecl ActivateSubcActDoc(class CObjID,int,int);
IMPORT_1C class CSbCntDoc * __cdecl ActivateSubkList(long,class CObjID,unsigned int,unsigned int,class CObjID,class CString,class CDate,int,class CObjID,int,long,int,class CValue *,class CString,int,int,int,class CValue *);
IMPORT_1C int __cdecl BrowseScan(class CGetDoc7 *,unsigned int);
IMPORT_1C int __cdecl ChangeTimeDoc(class CDocSet *,long);
IMPORT_1C int __cdecl CheckOnDelete(class CObjID);
IMPORT_1C void __cdecl ConvertDate(class CString &,class CDate,class CDate);
IMPORT_1C int __cdecl DeleteDoc(class CDocSet *,long);
IMPORT_1C int __cdecl DeleteDocActsFromContext(class CDocSet *,class COperSet *);
IMPORT_1C int __cdecl DeleteDocFromContext(class CDocSet *,class COperSet *,int);
IMPORT_1C int __cdecl DeleteDocTransactions(class CDocSet *,long);
IMPORT_1C void __cdecl DlgDXValue(class CDialog *,class CDataExchange *,unsigned int,class CTypedValue *,class CString *);
IMPORT_1C void __cdecl DlgOnButtonClickedValue(class CDialog *,unsigned int,class CTypedValue *,class CString *);
IMPORT_1C void __cdecl DlgSetTypeCtrlValue(class CDialog *,unsigned int,class CTypedValue *);
IMPORT_1C int __cdecl EnableMDIActivate(void);
IMPORT_1C class CString  __cdecl GetAccMaskEdit(class CPlanDef *,int);
IMPORT_1C class CBasicProfile * __cdecl GetBasicProfile(void);
IMPORT_1C int __cdecl GetBrSearchBySort(void);
IMPORT_1C int __cdecl GetContextPropExt(class CBLContext *,class CValue &,class CValue * *);
IMPORT_1C class CString  __cdecl GetCurAccEditMask(long,int,int);
IMPORT_1C class CObjID  __cdecl GetCurrentDocObjID(void);
IMPORT_1C class CObjID  __cdecl GetCurrentSbCntObjID(long);
IMPORT_1C class CString  __cdecl GetDateFldDescr(void);
IMPORT_1C class CString  __cdecl GetDateFldMask(void);
IMPORT_1C class CPlanDef * __cdecl GetDefaultPlanDef(void);
IMPORT_1C int __cdecl GetDeleteMode(void);
IMPORT_1C class CObjID  __cdecl GetDocCurrentID(void);
IMPORT_1C int __cdecl GetFlagHardFinishSystem(void);
IMPORT_1C int __cdecl GetFlagScanOneCol(void);
IMPORT_1C class CString  __cdecl GetMDCodeFromValue(class CValue *);
IMPORT_1C class CMetaDataObj * __cdecl GetMDDefFromValue(class CValue *);
IMPORT_1C int __cdecl GetOpenMode(void);
IMPORT_1C class CObjID  __cdecl GetRefCurrentID(long);
IMPORT_1C class CType  __cdecl GetTypeFromValueExt(class CValue *,int,int,int *,int);

// LoadValueFromString - ���������� ���� ����� "���������������������" �� ����� 1�
// ���� �������� ��������, ����� �� ������ ��� ���������� (DecrRef) !
IMPORT_1C int __cdecl LoadValueFromString(class CValue *,char const *);

IMPORT_1C int __cdecl LockWithMessage(class CObjectSet *);
IMPORT_1C int __cdecl ModalInputTypedValue(class CTypedValue *,class CString,int);
IMPORT_1C int __cdecl ReMakeDocsTransactions(class CDate,class CEventTime,class CDate,class CEventTime,int *,int *,int,int,int &,int *);
IMPORT_1C int __cdecl SaveValueToString(class CValue *,class CString &);
IMPORT_1C int __cdecl SetContextPropExt(class CBLContext *,class CValue * *);
IMPORT_1C void __cdecl SetDefaultPlanDef(class CPlanDef *);
IMPORT_1C int __cdecl SetEnableMDIActivate(int);
IMPORT_1C int __cdecl SetFlagFinishSystem(int);
IMPORT_1C void __cdecl ShowObject(class CMetaDataObj *,class CObjID,long);
IMPORT_1C int __cdecl TestAccess(unsigned int,long,unsigned int,int,int);
IMPORT_1C int __cdecl WriteDocFromContext(class CDocSet *,class COperSet *,int,class CDocContext *);
IMPORT_1C int __cdecl WriteDocFromForm(class CDocSet *,class COperSet *,int,int,class CDocTransacter *,class CValue *,int);
// End free functions definitions
// ??_C@_02OMNH@VL?$AA@

// ������ ������ 8A4
class CJournalDoc : public CGetDoc7 
{
public:
	DWORD m_dwUnknown510; // 0x510
	CGroupColumns m_GroupColumns; // 0x514
	CMenu7* m_pMenu; // 0x52C
	DWORD m_dwUnknown530; // 0x530
	DWORD m_dwUnknown534; // 0x534
	CDWordArray m_DWordArray; // 0x538
	CValue m_Value1; // 0x54C
	DWORD m_dwUnknown5A0;
	DWORD m_dwUnknown5A4;
	DWORD m_dwUnknown5A8;
	CObjID m_objID2; // 0x5AC
	CValue m_Value2; // 0x5b4
	CString m_String1; // 0x608
	CValue m_Value3; // 0x60C
	DWORD m_dwUnknown660;
	DWORD m_dwUnknown664;
	DWORD m_dwUnknown668;
	CString m_String2; // 0x66C
	DWORD m_dwUnknown670;
	DWORD m_dwUnknown674;
	DWORD m_dwUnknown678;
	CString m_String3; // 0x67C
	DWORD m_dwUnknown680;
	CJournalDef * m_pJournalDef; //DWORD m_dwUnknown684;
	DWORD m_dwUnknown688;
	DWORD m_dwUnknown68C;
	DWORD m_dwUnknown690;
	DWORD m_dwUnknown694;
	DWORD m_dwUnknown698;
	CString m_String4; // 0x69C
	DWORD m_dwUnknown6A0;
	CJournalContextDef m_JournalContextDef; //0x6a4
	//CFormContext m_FormContext; //0x6D4
 	DWORD m_buf744[0x1C];
	CGroupContext m_GroupContext; //0x7B4

	DWORD m_dwUnknown7E8;
	DWORD m_dwUnknown7EC;
	DWORD m_dwUnknown7F0;
	DWORD m_dwUnknown7F4;
	DWORD m_dwUnknown7F8;
	DWORD m_dwUnknown7FC;
	DWORD m_dwUnknown800;
	DWORD m_dwUnknown804;
	CObject* m_pObject1; // 0x808
	DWORD m_dwUnknown80C;
	DWORD m_dwUnknown810;
	DWORD m_dwUnknown814;
	DWORD m_dwUnknown818;
	CObject* m_pObject2; // 0x81C
	DWORD m_dwUnknown820;
	DWORD m_dwUnknown824;
	DWORD m_dwUnknown828;
	DWORD m_dwUnknown82c;

	DWORD m_dwUnknown830;
	DWORD m_dwUnknown834;
	DWORD m_dwUnknown838;
	DWORD m_dwUnknown83C;
	DWORD m_dwUnknown840;
	DWORD m_dwUnknown844;
	
};

// artbear ������ 4*0B8h - ����� �� basic.dll �� ������ 2A038426
class IMPORT_1C CDocFormContext:public CDocFormContextDef
{
    DECLARE_DYNCREATE(CFormContext); // � 1� ��� ����� ������ ������������ ������ ����� �����!
public:
	CDocContext* m_pDocContext;// 0x20
	CGetDoc7* m_pDoc; // 0x24
	DWORD m_Flag1;// 0x28
	CAllRegsContext* m_pAllRegsContext; // 0x2C
};
