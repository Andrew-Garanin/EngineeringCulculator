
// EngineeringCulculatorView.h: интерфейс класса CEngineeringCulculatorView
//

#pragma once

//class Element : public CObject
//{
//protected:
//	CString value;
//	int whatThis;
//public:
//	Element(CString Val, int WhatThis)
//	{
//		value = Val;
//		whatThis = WhatThis;
//	}
//	CString getValue()
//	{
//		return this->value;
//	}
//	int getWhatThis()
//	{
//		return this->whatThis;
//	}
//};
//class Stack : CObArray
//{
//protected:
//	CArray<Element, Element>  m_Array;
//public:
//	Stack()
//	{
//		m_Array.SetSize(1000);
//	}
//
//	Element getElement(int index)
//	{
//		return m_Array.GetAt(index);
//	}
//};

class CEngineeringCulculatorView : public CFormView
{
public:
	CString enterStr=L"";//Верхняя строка
	CString numberStr = L"0";//Нижняя строка
	int isCommaInNumber=0;//Индикатор запятой в числе
	int action=0;//происходит ли выполнение операции и какой
	int prior = 0;//Приоритет последней операции в стеке
	int wasIql = 0;// было ли нажата кнопка равно
	CString currentStr=L"0";//Вводимая в текущий момент строка
	int wasPushLeftBracket = 0;
	int wasPushRightBracket = 0;
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
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBtnplus();
	afx_msg void OnBnClickedBtnminus();
	afx_msg void OnBnClickedBtnmultiply();
	afx_msg void OnBnClickedBtndivide();
	afx_msg void OnBnClickedBtneql();
	CEdit m_Number;
	afx_msg void OnBnClickedLeftbracket();
	afx_msg void OnBnClickedRigthbracket();
};

#ifndef _DEBUG  // версия отладки в EngineeringCulculatorView.cpp
inline CEngineeringCulculatorDoc* CEngineeringCulculatorView::GetDocument() const
   { return reinterpret_cast<CEngineeringCulculatorDoc*>(m_pDocument); }
#endif

