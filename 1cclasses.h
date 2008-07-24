#include <windef.h>

class CValue;
//class CPtrArray;
#define IMPORT_1C __declspec(dllimport)

//typedef CTypedPtrArray<CPtrArray, CValue*> CValuePtrArray;

class IMPORT_1C CType
{
public:
	DWORD m_length;
	DWORD m_mdid;
	WORD type;
	BYTE m_prec;
	BYTE m_flags;	// Для чисел 1-разделять триады, 2 - неотрицательный
	 CType(class CType const &);	//299
	 CType(int);	//300
	 CType(int,int,int);	//301
	 CType(int,int,int,long);	//302
	 CType(int,long);	//303
	 ~CType(void);	//484
	class CType &  operator=(class CType const &);	//578
	int  operator==(class CType const &)const;	//610
	int  operator!=(class CType const &)const;	//617
//	void  `default constructor closure'(void);	//784
	void  AssignWithoutFormat(class CType const &);	//904
	static int  C2TypeCode(char);	//925
	char  GetCTypeCode(void)const;	//1491
	int  GetLength(void)const;	//1880
	int  GetPrecision(void)const;	//2153
	int  GetTypeCode(void)const;	//2500
	long  GetTypeID(void)const;	//2506
	class CString   GetTypeTitle(void);	//2516
	int  IsNumSeparated(void)const;	//2837
	int  IsObjReference(void);	//2845
	int  IsPositiveOnly(void)const;	//2861
	int  IsValid(void);	//2888
	void  LoadTypeFromList(class CItemList const &,int &);	//2963
	void  SaveTypeToList(class CItemList *)const;	//3299
	void  SetFormat(int,int);	//3590
	void  SetNumSeparated(int);	//3654
	void  SetPositiveOnly(int);	//3689
	void  SetTypeCode(int);	//3785
	void  SetTypeID(long);	//3787
};

class IMPORT_1C CNumeric
{
public:
	 CNumeric(CNumeric const &);	//6
	 CNumeric(int);	//7
	 CNumeric(long);	//8
	 CNumeric(double);	//9
	 CNumeric(long double);	//10
	 CNumeric(void);	//11
	 ~CNumeric(void);	//20
	CNumeric &  operator=(CNumeric const &);	//24
	CNumeric &  operator=(int);	//25
	CNumeric &  operator=(long);	//26
	CNumeric &  operator=(double);	//27
	CNumeric &  operator=(long double);	//28
	 operator long(void)const;	//29
	CNumeric   operator*(CNumeric const &)const;	//30
	CNumeric   operator-(CNumeric const &)const;	//31
	CNumeric   operator+(CNumeric const &)const;	//32
	CNumeric   operator/(CNumeric const &)const;	//33
	CNumeric   Abs(void)const;	//35
	int  Compare(CNumeric const &)const;	//42
	int  CompareLong(long)const;	//43
	char *  Convert(char *,int,int)const;	//44
	CNumeric   Floor(void)const;	//58
	CNumeric &  FromString(char const *,char * *);	//60
	long double  GetDouble(void)const;	//64
	static int  GetRoundMode(void);	//84
	CNumeric   Negate(void)const;	//104
	CNumeric   Round(int)const;	//117
	static int  SetRoundMode(int);	//128
	int  Sign(void)const;	//131
protected:
	int m_0;
	int m_nBufferLen;
	int m_nUsedLen;
	int m_nScaleLen;
	short m_Sign;
	int m_ScaleFactor;
	UINT *m_pBuffer;
	UINT m_Buffer[4];
};

class IMPORT_1C CDate
{
public:
	DWORD m_DateNum;
	 CDate(int,int,int);	//2
	CDate   AddMonth(int);	//37
	CDate   BegOfMonth(void)const;	//39
	CDate   BegOfQuart(void)const;	//40
	CDate   BegOfYear(void)const;	//41
	CDate   EndOfMonth(void)const;	//51
	CDate   EndOfQuart(void)const;	//52
	CDate   EndOfYear(void)const;	//53
	char const *  Format(enum CDateFormat,struct SDateFmtInfo const *)const;	//59
	static CDate   GetCurrentDate(void);	//62
	int  GetFormatted(enum CDateFormat,char const *);	//66
	int  GetFormatted(enum CDateFormat,char const *,int,int);	//67
	int  GetMonth(void)const;	//74
	int  GetMonthDay(void)const;	//75
	int  GetWeekDay(void)const;	//87
	int  GetYear(void)const;	//88
	int  GetYearDay(void)const;	//89
};

class IMPORT_1C CDBSign
{
public:
	char Sign[4];
	 CDBSign(char const *);	//87
	 CDBSign(char const *,int);	//88
	class CDBSign &  operator=(class CDBSign const &);	//518
	int  operator==(class CDBSign const &)const;	//605
	int  operator!=(class CDBSign const &)const;	//612
	 operator char const *(void)const;	//623
	int  operator<(class CDBSign const &)const;	//632
	int  operator>(class CDBSign const &)const;	//635
//	void  `default constructor closure'(void);	//763
	class CDBSign const &  Empty(void);	//1286
};

class IMPORT_1C CObjID
{
public:
	long ObjID; // ИД конкретного объекта, например, текущего документа
	class CDBSign DBSign;
	 CObjID(class CObjID const &);	//190
	 CObjID(long,class CDBSign const &);	//191
	 CObjID(void);	//192
	class CObjID &  operator=(class CObjID const &);	//547
	int  operator==(class CObjID const &)const;	//609
	int  operator!=(class CObjID const &)const;	//616
	int  operator<(class CObjID const &)const;	//634
	int  operator>(class CObjID const &)const;	//637
	class CObjID const &  Empty(void);	//1287
	int  FromString(class CString const &);	//1387
	class CDBSign const &  GetDBSign(void)const;	//1613
	static class CDBSign const &  GetDefDBSign(void);	//1638
	class CObjID   GetNextInSequence(void)const;	//2071
	class CObjID   GetPrevInSequence(void)const;	//2173
	class CString   GetString(void)const;	//2448
	long  GetlObjID(void)const;	//2556
	int  IsEmpty(void)const;	//2802
	void  SetDBSign(class CDBSign const &);	//3528
	static void  SetDefDBSign(class CDBSign const &);	//3543
	void  SetlObjID(long);	//3809
};


class IMPORT_1C CObjIDSet
{
public:
	 CObjIDSet(class CObjIDSet const &);	//193
	 CObjIDSet(void);	//194
	 ~CObjIDSet(void);	//433
	class CObjIDSet &  operator=(class CObjIDSet const &);	//549
	int  Find(class CObjID);	//1348
//	int  Find(class CObjID,struct std::__rb_tree_iterator<class CObjID,class CObjID const &,class CObjID const *> &);	//1349
	void  Insert(class CObjID);	//2743
};

class IMPORT_1C CBLContext:public CObject //32 Real - 4 VT = 28=0x1C
{
DECLARE_DYNCREATE(CBLContext)

public:
//Begin def
// +00 VTABLE
// +04 DWORD
	int m_RefCount;
// +08 DWORD param
	int m_FlagAutoDestroy;
// +0C CPtrArray
	CPtrArray m_Array; // массив ссылок на CValue, которые ссылаются на этот CBLContext
	//CValuePtrArray m_Array;  // массив ссылок на CValue, которые ссылаются на этот CBLContext

//	char dump [0x50];
	virtual  ~CBLContext(void);	//352
	CBLContext(int Param = 1);	//24
//	void  `default constructor closure'(void);	//759
protected:
//	CBLContext();
	void  					AddToValues(CValue const *);	//896
public:
	virtual void			IncrRef(void);
	virtual void			DecrRef(void);

	virtual int				GetDestroyUnRefd(void)const; // return m_FlagAutoDestroy; // в этом классе

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

	static CBLContext *		CreateInstance(CType const &);	//1059
	static CBLContext *		CreateInstance(char const *);	//1060
	static unsigned long	GetFirstLoadedContextID(void);	//1751
	static CBLContext *		GetLoadedContext(unsigned long);	//1930
	static unsigned long	GetNextLoadedContextID(unsigned long);	//2072
	
	static void				RegisterContextClass(struct CRuntimeClass *,char const *,CType const &);	//3195
	static void				RegisterOleContextClass(struct CRuntimeClass *);	//3200
	static void				UnRegisterContextClass(struct CRuntimeClass *);	//3945

	unsigned long			GetLoadedID(void)const;	//1931
	char const *			GetPresentMethodName(int)const;	//2170
	char const *			GetPresentPropName(int)const;	//2171
	
	void					HashMethods(int);	//2661
	void					HashProperties(int);	//2662
	void					Load(void)const;	//2924
	void					SetHashID(char const *);	//3605
	void					Unload(void)const;	//3962

private:
	void					RemoveFromValues(CValue const *);	//3223
};

class IMPORT_1C CValue: public CType
{
public:
	// void** pVtable
	class CNumeric m_Number; // числовое значение // align 8
	CStringA m_String; // строковое значение
	class CDate m_Date; // значение даты
	long ValTypeID; //int Flag6;
	CBLContext* /* void* */ m_Context; // значение контекста
	class CObjID m_ObjID; // значение в базе
	// total obj size = 84



	 CValue(class CValue const &);	//312
	 CValue(class CNumeric const &);	//313
	 CValue(class CType const &);	//314
	 CValue(long);	//315
	 CValue(char const *);	//316
	 CValue(class CDate);	//317
	 CValue(void);	//318
	class CValue const &  operator=(class CValue const &);	//588
	class CValue const &  operator=(class CNumeric const &);	//589
	class CValue const &  operator=(long);	//590
	class CValue const &  operator=(char const *);	//591
	class CValue const &  operator=(class CDate);	//592
	int  operator==(class CValue const &)const;	//611
	int  operator!=(class CValue const &)const;	//618
	int  AssignContext(class CBLContext *);	//903
	int  CopyToClipboard(class CWnd *,char const *);	//1051
	int  CreateObject(char const *);	//1064
	int  FastSaveToString(class CString &);	//1338
	char const *  Format(void)const;	//1380
	class CBLContext *  GetContext(void)const;	//1577
	class CDate   GetDate(void)const;	//1623
	static enum CDateFormat   GetDefDateFmt(void);	//1639
	class CNumeric const &  GetNumeric(void)const;	//2085
	class CObjID   GetObjID(void)const;	//2096
	long  GetRealTypeID(void)const;	//2286
	class CString const &  GetString(void)const;	//2449
	char const *  GetTypeString(void)const;	//2515
	long  GetValTypeID(void)const;	//2537
protected:
	void  Init(void);	//2684
public:
	int  IsEmpty(void)const;	//2803
	int  IsExactValue(void)const;	//2809
protected:
	virtual int  IsTypeSafe(void)const;	//2881
public:
	virtual  ~CValue(void);	//489
	void  Link(int,int);	//2894
	int  LinkContext(int);	//2907
	int  LoadFromString(char const *,int);	//2949
	int  LoadValueFromList(class CItemList *,int);	//2964
	void  MakeExactValueFrom(class CValue const *);	//2992
	int  PasteFromClipboard(class CWnd *);	//3089
	void  Reset(void);	//3232
	int  SaveToString(class CString &);	//3297
	int  SaveValueToList(class CItemList *)const;	//3300
	static void  SetDefDateFmt(enum CDateFormat);	//3544
	void  SetObjID(class CObjID);	//3658
	void  SetType(class CType const &);	//3784
	void  SetValTypeID(long);	//3798
	void  UnlinkContext(void);	//3961
	void  ValidateType(void);	//4034
	static unsigned int  cfValueId;	//4193
};
