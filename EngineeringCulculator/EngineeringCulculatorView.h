
// EngineeringCulculatorView.h: интерфейс класса CEngineeringCulculatorView
//

#pragma once

class CEngineeringCulculatorView : public CFormView
{
public:
	CString enterStr=L"";//Верхняя строка
	CString numberStr = L"0";//Нижняя строка
	int isCommaInNumber=0;//Индикатор запятой в числе
	int action=0;//происходит ли выполнение операции и какой
	int prior = 0;//Приоритет последней операции в стеке
	int wasIql = 0;// была ли нажата кнопка равно
	CString currentStr=L"0";//Вводимая в текущий момент строка
	int wasPushLeftBracket = 0;
	int wasPushRightBracket = 0;
	int wasPushAnotherOp = 0;
	int bracketCount = 0;
	int wasDevideZero = 0;
	int wasMemRead = 0;
	//Memory *memory= new Memory();
	void BtnClick(CString number);
	void PutAction();
protected: // создать только из сериализации
	CEngineeringCulculatorView() noexcept;
	DECLARE_DYNCREATE(CEngineeringCulculatorView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ENGINEERINGCULCULATOR_FORM };
#endif

// Атрибуты
public:
	CEngineeringCulculatorDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CEngineeringCulculatorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit;
	afx_msg void OnEnChangeMainfield();
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedBtncom();
	afx_msg void OnBnClickedBtnplus();
	afx_msg void OnBnClickedBtnminus();
	afx_msg void OnBnClickedBtnmultiply();
	afx_msg void OnBnClickedBtndivide();
	afx_msg void OnBnClickedBtneql();
	CEdit m_Number;
	afx_msg void OnBnClickedLeftbracket();
	afx_msg void OnBnClickedRigthbracket();
	afx_msg void OnBnClickedBtnsqrt();
	afx_msg void OnBnClickedMemclear();
	afx_msg void OnBnClickedMemread();
	afx_msg void OnBnClickedMemsave();
	afx_msg void OnBnClickedMemminus();
	afx_msg void OnBnClickedMemplus();
	afx_msg void OnBnClickedBtnclear();
	afx_msg void OnBnClickedBtnreverse();
	CEdit m_IsMem;
	afx_msg void OnBnClickedBtnconv();
	afx_msg void OnBnClickedBtnsin();
	afx_msg void OnBnClickedBtnfact();
	afx_msg void OnBnClickedBtncos();
	afx_msg void OnBnClickedBtntan();
	afx_msg void OnBnClickedBtnpowten();
	afx_msg void OnBnClickedBtnpow();
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBtnmod();
};

#ifndef _DEBUG  // версия отладки в EngineeringCulculatorView.cpp
inline CEngineeringCulculatorDoc* CEngineeringCulculatorView::GetDocument() const
   { return reinterpret_cast<CEngineeringCulculatorDoc*>(m_pDocument); }
#endif

