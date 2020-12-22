
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
	int wasPushLeftBracket = 0;//Была ли нажата левая скобка
	int wasPushRightBracket = 0;//Была ли нажата правая скобка
	int wasPushAnotherOp = 0;//Была ли вызвана унарная операция
	int bracketCount = 0;//Контроль скобок
	int wasDevideZero = 0;
	int wasMemRead = 0;//Было ли чтение из памяти
	enum { INT_DEGREES, INT_RADIANS };
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
	void BtnClick(CString number);//Функция, вызываемая при нажатии на цифру
	void PutAction();//кладет знак операции в стек

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
	afx_msg void OnBnClickedBtnmod();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnFileOpen();
	afx_msg void OnBnClickedRad();
	afx_msg void OnBnClickedGrad();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_AngleMeasure;
	afx_msg void OnBnClickedBtncuberoot();
	afx_msg void OnBnClickedBtnsqr();
	afx_msg void OnBnClickedBtncube();
	afx_msg void OnBnClickedBtnyroot();
	afx_msg void OnBnClickedBtnpi();
	afx_msg void OnBnClickedBtnexp();
	afx_msg void OnBnClickedBtnln();
};

#ifndef _DEBUG  // версия отладки в EngineeringCulculatorView.cpp
inline CEngineeringCulculatorDoc* CEngineeringCulculatorView::GetDocument() const
   { return reinterpret_cast<CEngineeringCulculatorDoc*>(m_pDocument); }
#endif

