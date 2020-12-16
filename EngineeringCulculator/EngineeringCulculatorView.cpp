
// EngineeringCulculatorView.cpp: реализация класса CEngineeringCulculatorView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "EngineeringCulculator.h"
#endif

#include "EngineeringCulculatorDoc.h"
#include "EngineeringCulculatorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEngineeringCulculatorView

IMPLEMENT_DYNCREATE(CEngineeringCulculatorView, CFormView)

BEGIN_MESSAGE_MAP(CEngineeringCulculatorView, CFormView)
	ON_EN_CHANGE(IDC_MAINFIELD, &CEngineeringCulculatorView::OnEnChangeMainfield)
	ON_BN_CLICKED(IDC_BTN1, &CEngineeringCulculatorView::OnBnClickedBtn1)
	ON_BN_CLICKED(IDC_BTN2, &CEngineeringCulculatorView::OnBnClickedBtn2)
	ON_BN_CLICKED(IDC_BTN3, &CEngineeringCulculatorView::OnBnClickedBtn3)
	ON_BN_CLICKED(IDC_BTN4, &CEngineeringCulculatorView::OnBnClickedBtn4)
	ON_BN_CLICKED(IDC_BTN5, &CEngineeringCulculatorView::OnBnClickedBtn5)
	ON_BN_CLICKED(IDC_BTN6, &CEngineeringCulculatorView::OnBnClickedBtn6)
	ON_BN_CLICKED(IDC_BTN7, &CEngineeringCulculatorView::OnBnClickedBtn7)
	ON_BN_CLICKED(IDC_BTN8, &CEngineeringCulculatorView::OnBnClickedBtn8)
	ON_BN_CLICKED(IDC_BTN9, &CEngineeringCulculatorView::OnBnClickedBtn9)
	ON_BN_CLICKED(IDC_BTN0, &CEngineeringCulculatorView::OnBnClickedBtn0)
	ON_BN_CLICKED(IDC_BTNCOM, &CEngineeringCulculatorView::OnBnClickedBtncom)
ON_BN_CLICKED(IDC_BTNPLUS, &CEngineeringCulculatorView::OnBnClickedBtnplus)
ON_BN_CLICKED(IDC_BTNMINUS, &CEngineeringCulculatorView::OnBnClickedBtnminus)
ON_BN_CLICKED(IDC_BTNMULTIPLY, &CEngineeringCulculatorView::OnBnClickedBtnmultiply)
ON_BN_CLICKED(IDC_BTNDIVIDE, &CEngineeringCulculatorView::OnBnClickedBtndivide)
ON_BN_CLICKED(IDC_BTNEQL, &CEngineeringCulculatorView::OnBnClickedBtneql)
END_MESSAGE_MAP()

// Создание или уничтожение CEngineeringCulculatorView

CEngineeringCulculatorView::CEngineeringCulculatorView() noexcept
	: CFormView(IDD_ENGINEERINGCULCULATOR_FORM)
{
	// TODO: добавьте код создания
}

CEngineeringCulculatorView::~CEngineeringCulculatorView()
{
}

void CEngineeringCulculatorView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MAINFIELD, m_Edit);
	DDX_Control(pDX, IDC_NUMBER, m_Number);
}

BOOL CEngineeringCulculatorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CEngineeringCulculatorView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_Number.SetWindowTextW(L"0");
}


// Диагностика CEngineeringCulculatorView

#ifdef _DEBUG
void CEngineeringCulculatorView::AssertValid() const
{
	CFormView::AssertValid();
}

void CEngineeringCulculatorView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CEngineeringCulculatorDoc* CEngineeringCulculatorView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEngineeringCulculatorDoc)));
	return (CEngineeringCulculatorDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CEngineeringCulculatorView


void CEngineeringCulculatorView::OnEnChangeMainfield()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CFormView::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CEngineeringCulculatorView::OnBnClickedBtn1()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr == L"0") 
	{
		numberStr = L"1";
	}
	else if (action)
	{
		numberStr = L"";
		numberStr.Append(L"1");
		action = 0;
		isCommaInNumber = 0;
	}
	else
	{
		numberStr.Append(L"1");
	}
	m_Number.SetWindowTextW(numberStr);
	currentStr.Append(L"1");
	/*CString MyString;
	GetDocument()->addElement(L"-", 1);

	MyString = GetDocument()->getElement(GetDocument()->getNumElements() - 1)->getValue();
	MessageBox(MyString);*/
}


void CEngineeringCulculatorView::OnBnClickedBtn2()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr == L"0")
	{
		numberStr = L"2";
	}
	else if (action)
	{
		numberStr = L"";
		numberStr.Append(L"2");
		action = 0;
		isCommaInNumber = 0;
	}
	else
	{
		numberStr.Append(L"2");
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtn3()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr == L"0")
	{
		numberStr = L"3";
	}
	else if (action)
	{
		numberStr = L"";
		numberStr.Append(L"3");
		action = 0;
		isCommaInNumber = 0;
	}
	else
	{
		numberStr.Append(L"3");
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtn4()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr == L"0")
	{
		numberStr = L"4";
	}
	else if (action)
	{
		numberStr = L"";
		numberStr.Append(L"4");
		action = 0;
		isCommaInNumber = 0;
	}
	else
	{
		numberStr.Append(L"4");
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtn5()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr == L"0")
	{
		numberStr = L"5";
	}
	else if (action)
	{
		numberStr = L"";
		numberStr.Append(L"5");
		action = 0;
		isCommaInNumber = 0;
	}
	else
	{
		numberStr.Append(L"5");
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtn6()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr == L"0")
	{
		numberStr = L"6";
	}
	else if (action)
	{
		numberStr = L"";
		numberStr.Append(L"6");
		action = 0;
		isCommaInNumber = 0;
	}
	else
	{
		numberStr.Append(L"6");
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtn7()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr == L"0")
	{
		numberStr = L"7";
	}
	else if (action)
	{
		numberStr = L"";
		numberStr.Append(L"7");
		action = 0;
		isCommaInNumber = 0;
	}
	else
	{
		numberStr.Append(L"7");
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtn8()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr == L"0") 
	{
		numberStr = L"8";
	}
	else if (action)
	{
		numberStr = L"";
		numberStr.Append(L"8");
		action = 0;
		isCommaInNumber = 0;
	}
	else
	{
		numberStr.Append(L"8");
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtn9()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr == L"0")
	{
		numberStr = L"9";
	}
	else if (action)
	{
		numberStr = L"";
		numberStr.Append(L"9");
		action = 0;
		isCommaInNumber = 0;
	}
	else
	{
		numberStr.Append(L"9");
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtn0()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr == L"0")
	{
		numberStr = L"0";
	}
	else if (action)
	{
		numberStr = L"";
		numberStr.Append(L"0");
		action = 0;
		isCommaInNumber = 0;
	}
	else
	{
		numberStr.Append(L"0");
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtncom()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr.GetLength()!= 0 && isCommaInNumber == 0)
	{
		numberStr.Append(L",");
		isCommaInNumber = 1;
		m_Number.SetWindowTextW(numberStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnplus()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!action)
	{
		enterStr.Append(numberStr);
		enterStr.Append(L"+");
		action = 1;
		m_Edit.SetWindowTextW(enterStr);
	}
	if (action)
	{
		enterStr = enterStr.Mid(0, enterStr.GetLength() - 1);
		enterStr.Append(L"+");
		m_Edit.SetWindowTextW(enterStr);
	}
	CString MyString;
	GetDocument()->PushElement(currentStr, 1);

	MyString = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
	MessageBox(MyString);
}


void CEngineeringCulculatorView::OnBnClickedBtnminus()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!action)
	{
		enterStr.Append(numberStr);
		enterStr.Append(L"-");
		action = 1;
		m_Edit.SetWindowTextW(enterStr);
	}
	if (action)
	{
		enterStr = enterStr.Mid(0, enterStr.GetLength() - 1);
		enterStr.Append(L"-");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnmultiply()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CEngineeringCulculatorView::OnBnClickedBtndivide()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CEngineeringCulculatorView::OnBnClickedBtneql()
{
	// TODO: добавьте свой код обработчика уведомлений
}
