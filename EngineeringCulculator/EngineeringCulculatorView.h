
// EngineeringCulculatorView.h: интерфейс класса CEngineeringCulculatorView
//

#pragma once

class CEngineeringCulculatorView : public CFormView
{
public:
	CString enterStr=L"";
	CString numberStr = L"0";
	int isCommaInNumber=0;
	int action=0;
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
};

#ifndef _DEBUG  // версия отладки в EngineeringCulculatorView.cpp
inline CEngineeringCulculatorDoc* CEngineeringCulculatorView::GetDocument() const
   { return reinterpret_cast<CEngineeringCulculatorDoc*>(m_pDocument); }
#endif

