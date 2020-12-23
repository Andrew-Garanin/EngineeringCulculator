
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
#define _USE_MATH_DEFINES
#include <math.h>

CString Fact(double z)
{
	CString str;
	if (z < 0)
	{
		str = L"Недопустимый ввод";
		return str;
	}
	int tmp1 = (int)z;
	long rez = 1;
	for (int i = tmp1; i >= 1; i--)
		rez *= i;

	if (tmp1 > 12)
	{
		str = L"Слишком большое число";
	}
	else
	{
		str.Format(L"%d", rez);
	}
	return str;
}

CString Calculate(CString num1, CString oper, CString num2)
{
	double Num1= _wtof( num1 );
	double Num2 = _wtof(num2);
	if (oper == "+")
	{
		CString str;
		str.Format(L"%f", Num1 + Num2);
		return str;
	}
	if (oper == "-")
	{
		CString str;
		str.Format(L"%f", Num2 - Num1);
		return str;
	}
	if (oper == "*")
	{
		CString str;
		str.Format(L"%f", Num1 * Num2);
		return str;
	}
	if (oper == "/")
	{
		if (Num1 == 0)
		{
			return L"Деление на ноль невозможно";
		}
		CString str;
		str.Format(L"%f", Num2 / Num1);
		return str;
	}
	if (oper == "^")
	{
		CString str;
		str.Format(L"%f", pow(Num2,Num1));
		return str;
	}
	if (oper == " mod ")
	{
		CString str;
		str.Format(L"%f", fmod(Num2, Num1));
		return str;
	}
	if (oper == " yroot ")
	{
		if (fmod(Num1, 2) == 0 && Num2<0)
		{
			return L"Недопустимый ввод";
		}
		if (Num1 == 0)
		{
			return L"Деление на ноль невозможно";
		}
		CString str;
		str.Format(L"%f", pow(Num2, 1.0/Num1));
		return str;
	}
}

// CEngineeringCulculatorView
void CEngineeringCulculatorView::BtnClick(CString number)
{
	// TODO: добавьте свой код обработчика уведомлений
	if (wasPushAnotherOp)
	{
		MessageBox(L"Введите операцию");
		return;
	}
	
	if (action)
	{
		PutAction();
		action = 0;
		numberStr = L"0";
		currentStr = L"0";
	}

	if (numberStr == L"0")
	{
		numberStr = number;
		currentStr = number;
		isCommaInNumber = 0;
		wasIql = 0;
		wasMemRead = 0;
	}
	else
	{
		if (wasIql|| wasMemRead )
		{
			wasIql = 0;
			wasMemRead = 0;
			numberStr = number;
			currentStr = number;
			isCommaInNumber = 0;
		}
		else {
			currentStr.Append(number);
			numberStr.Append(number);
		}
	}
	m_Number.SetWindowTextW(numberStr);
}

void CEngineeringCulculatorView::PutAction()
{
	if (action == 1)
	{
		GetDocument()->PushElement(L"+", 2);//Кладем знак операии в стек
		prior = 1;
	}
	if (action == 2)
	{
		GetDocument()->PushElement(L"-", 2);//Кладем знак операии в стек
		prior = 1;
	}
	if (action == 3)
	{
		GetDocument()->PushElement(L"*", 2);//Кладем знак операии в стек
		prior = 2;
	}
	if (action == 4)
	{
		GetDocument()->PushElement(L"/", 2);//Кладем знак операии в стек
		prior = 2;
	}
	if (action == 5)
	{
		GetDocument()->PushElement(L"^", 2);//Кладем знак операии в стек
		prior = 3;
	}
	if (action == 6)
	{
		GetDocument()->PushElement(L" mod ", 2);//Кладем знак операии в стек
		prior = 3;
	}
	if (action == 7)
	{
		GetDocument()->PushElement(L" yroot ", 2);//Кладем знак операии в стек
		prior = 3;
	}
}

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
	ON_BN_CLICKED(IDC_LEFTBRACKET, &CEngineeringCulculatorView::OnBnClickedLeftbracket)
	ON_BN_CLICKED(IDC_RIGTHBRACKET, &CEngineeringCulculatorView::OnBnClickedRigthbracket)
	ON_BN_CLICKED(IDC_BTNSQRT, &CEngineeringCulculatorView::OnBnClickedBtnsqrt)
	ON_BN_CLICKED(IDC_MEMCLEAR, &CEngineeringCulculatorView::OnBnClickedMemclear)
	ON_BN_CLICKED(IDC_MEMREAD, &CEngineeringCulculatorView::OnBnClickedMemread)
	ON_BN_CLICKED(IDC_MEMSAVE, &CEngineeringCulculatorView::OnBnClickedMemsave)
	ON_BN_CLICKED(IDC_MEMMINUS, &CEngineeringCulculatorView::OnBnClickedMemminus)
	ON_BN_CLICKED(IDC_MEMPLUS, &CEngineeringCulculatorView::OnBnClickedMemplus)
	ON_BN_CLICKED(IDC_BTNCLEAR, &CEngineeringCulculatorView::OnBnClickedBtnclear)
	ON_BN_CLICKED(IDC_BTNREVERSE, &CEngineeringCulculatorView::OnBnClickedBtnreverse)
	ON_BN_CLICKED(IDC_BTNCONV, &CEngineeringCulculatorView::OnBnClickedBtnconv)
	ON_BN_CLICKED(IDC_BTNSIN, &CEngineeringCulculatorView::OnBnClickedBtnsin)
	ON_BN_CLICKED(IDC_BTNFACT, &CEngineeringCulculatorView::OnBnClickedBtnfact)
	ON_BN_CLICKED(IDC_BTNCOS, &CEngineeringCulculatorView::OnBnClickedBtncos)
	ON_BN_CLICKED(IDC_BTNTAN, &CEngineeringCulculatorView::OnBnClickedBtntan)
	ON_BN_CLICKED(IDC_BTNPOWTEN, &CEngineeringCulculatorView::OnBnClickedBtnpowten)
	ON_BN_CLICKED(IDC_BTNPOW, &CEngineeringCulculatorView::OnBnClickedBtnpow)
	ON_BN_CLICKED(IDC_BTNMOD, &CEngineeringCulculatorView::OnBnClickedBtnmod)
	ON_BN_CLICKED(IDC_GRAD, &CEngineeringCulculatorView::OnBnClickedGrad)
	ON_BN_CLICKED(IDC_RAD, &CEngineeringCulculatorView::OnBnClickedRad)
	ON_COMMAND(ID_EDIT_COPY, &CEngineeringCulculatorView::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CEngineeringCulculatorView::OnEditPaste)
	ON_COMMAND(ID_FILE_OPEN, &CEngineeringCulculatorView::OnFileOpen)
	ON_BN_CLICKED(IDC_BTNCUBEROOT, &CEngineeringCulculatorView::OnBnClickedBtncuberoot)
	ON_BN_CLICKED(IDC_BTNSQR, &CEngineeringCulculatorView::OnBnClickedBtnsqr)
	ON_BN_CLICKED(IDC_BTNCUBE, &CEngineeringCulculatorView::OnBnClickedBtncube)
	ON_BN_CLICKED(IDC_BTNYROOT, &CEngineeringCulculatorView::OnBnClickedBtnyroot)
	ON_BN_CLICKED(IDC_BTNPI, &CEngineeringCulculatorView::OnBnClickedBtnpi)
	ON_BN_CLICKED(IDC_BTNEXP, &CEngineeringCulculatorView::OnBnClickedBtnexp)
	ON_BN_CLICKED(IDC_BTNLN, &CEngineeringCulculatorView::OnBnClickedBtnln)
	ON_BN_CLICKED(IDC_BTNLOG, &CEngineeringCulculatorView::OnBnClickedBtnlog)
	ON_BN_CLICKED(IDC_BTNINT, &CEngineeringCulculatorView::OnBnClickedBtnint)
	ON_BN_CLICKED(IDC_BTNSINH, &CEngineeringCulculatorView::OnBnClickedBtnsinh)
	ON_BN_CLICKED(IDC_BTNCOSH, &CEngineeringCulculatorView::OnBnClickedBtncosh)
	ON_BN_CLICKED(IDC_BTNTANH, &CEngineeringCulculatorView::OnBnClickedBtntanh)
	ON_BN_CLICKED(IDC_BTNCOT, &CEngineeringCulculatorView::OnBnClickedBtncot)
	ON_BN_CLICKED(IDC_BTNPOWE, &CEngineeringCulculatorView::OnBnClickedBtnpowe)
END_MESSAGE_MAP()

// Создание или уничтожение CEngineeringCulculatorView

CEngineeringCulculatorView::CEngineeringCulculatorView() noexcept
	: CFormView(IDD_ENGINEERINGCULCULATOR_FORM)
{
	// TODO: добавьте код создания
	m_AngleMeasure = INT_DEGREES;
}

CEngineeringCulculatorView::~CEngineeringCulculatorView()
{
}

void CEngineeringCulculatorView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MAINFIELD, m_Edit);
	DDX_Control(pDX, IDC_NUMBER, m_Number);
	DDX_Control(pDX, IDC_M, m_IsMem);
	DDX_Radio(pDX, IDC_GRAD, m_AngleMeasure);
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
	if(GetDocument()->memory->value!=0)
		m_IsMem.ShowWindow(SW_SHOW);//буква M слева от поля ввода
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
	BtnClick(L"1");
}


void CEngineeringCulculatorView::OnBnClickedBtn2()
{
	// TODO: добавьте свой код обработчика уведомлений
	BtnClick(L"2");
}


void CEngineeringCulculatorView::OnBnClickedBtn3()
{
	// TODO: добавьте свой код обработчика уведомлений
	BtnClick(L"3");
}


void CEngineeringCulculatorView::OnBnClickedBtn4()
{
	// TODO: добавьте свой код обработчика уведомлений
	BtnClick(L"4");
}


void CEngineeringCulculatorView::OnBnClickedBtn5()
{
	// TODO: добавьте свой код обработчика уведомлений
	BtnClick(L"5");
}


void CEngineeringCulculatorView::OnBnClickedBtn6()
{
	// TODO: добавьте свой код обработчика уведомлений
	BtnClick(L"6");
}


void CEngineeringCulculatorView::OnBnClickedBtn7()
{
	// TODO: добавьте свой код обработчика уведомлений
	BtnClick(L"7");
}


void CEngineeringCulculatorView::OnBnClickedBtn8()
{
	// TODO: добавьте свой код обработчика уведомлений
	BtnClick(L"8");
}


void CEngineeringCulculatorView::OnBnClickedBtn9()
{
	// TODO: добавьте свой код обработчика уведомлений
	BtnClick(L"9");
}


void CEngineeringCulculatorView::OnBnClickedBtn0()
{
	// TODO: добавьте свой код обработчика уведомлений
	BtnClick(L"0");
}


void CEngineeringCulculatorView::OnBnClickedBtncom()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (numberStr.GetLength()!= 0 && isCommaInNumber == 0)
	{
		numberStr.Append(L".");
		currentStr.Append(L".");
		isCommaInNumber = 1;
		m_Number.SetWindowTextW(numberStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnplus()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!action)
	{
		if (!wasPushRightBracket && !wasPushAnotherOp)
		{
			GetDocument()->PushElement(currentStr, 1);
			enterStr.Append(numberStr);
		}
		wasPushRightBracket = 0;
		wasPushAnotherOp = 0;
		enterStr.Append(L"+");
		action = 1;//запоминаем операцию
		m_Edit.SetWindowTextW(enterStr);

		if (!wasPushLeftBracket && GetDocument()->getCountOfNumbers() != 1)
		{	
			if (prior >= 1)
			{
				//считаем результат и его в стек
				CString num1 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString oper = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString num2 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString rez = Calculate(num1, oper, num2);
				if (rez == "Деление на ноль невозможно")
				{
					MessageBox(L"Деление на ноль невозможно");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				if (rez == "Недопустимый ввод")
				{
					MessageBox(L"Недопустимый ввод");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				GetDocument()->PushElement(rez, 1);
				isCommaInNumber = 1;
				numberStr = L"";
				numberStr.Append(rez);
				m_Number.SetWindowTextW(numberStr);
			}
		}
		else
		{
			wasPushLeftBracket = 0;
		}
	}
	else if (action)//можно без if что делать если произошла замена операции
	{
		int length = 0;
		if (action == 1 || action == 2 || action == 3 || action == 4 || action == 5)
			length = 1;
		if (action == 6)
			length = 5;
		if (action == 7)
			length = 7;
		enterStr = enterStr.Mid(0, enterStr.GetLength() - length);
		enterStr.Append(L"+");
		m_Edit.SetWindowTextW(enterStr);
		action = 1;
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnminus()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!action)
	{
		if (!wasPushRightBracket && !wasPushAnotherOp)
		{
			GetDocument()->PushElement(currentStr, 1);
			enterStr.Append(numberStr);
		}
		wasPushRightBracket = 0;
		wasPushAnotherOp = 0;
		enterStr.Append(L"-");
		action = 2;//запоминаем операцию
		m_Edit.SetWindowTextW(enterStr);

		if (!wasPushLeftBracket && GetDocument()->getCountOfNumbers() != 1)
		{
			if (prior >= 1)
			{
				//считаем результат и его в стек
				CString num1 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString oper = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString num2 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString rez = Calculate(num1, oper, num2);
				if (rez == "Деление на ноль невозможно")
				{
					MessageBox(L"Деление на ноль невозможно");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				if (rez == "Недопустимый ввод")
				{
					MessageBox(L"Недопустимый ввод");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				GetDocument()->PushElement(rez, 1);
				isCommaInNumber = 1;
				numberStr = L"";
				numberStr.Append(rez);
				m_Number.SetWindowTextW(numberStr);
			}
		}
		else
		{
			wasPushLeftBracket = 0;
		}
	}
	else if (action)//можно без if что делать если произошла замена операции
	{
		int length = 0;
		if (action == 1 || action == 2 || action == 3 || action == 4 || action == 5)
			length = 1;
		if (action == 6)
			length = 5;
		if (action == 7)
			length = 7;
		enterStr = enterStr.Mid(0, enterStr.GetLength() - length);
		enterStr.Append(L"-");
		m_Edit.SetWindowTextW(enterStr);
		action = 2;
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnmultiply()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!action)
	{
		if (!wasPushRightBracket && !wasPushAnotherOp)
		{
			GetDocument()->PushElement(currentStr, 1);
			enterStr.Append(numberStr);
		}
		wasPushRightBracket = 0;
		wasPushAnotherOp = 0;
		enterStr.Append(L"*");
		action = 3;//запоминаем операцию
		m_Edit.SetWindowTextW(enterStr);

		if (!wasPushLeftBracket && GetDocument()->getCountOfNumbers() != 1)
		{
			if (prior >= 2)
			{
				//считаем результат и его в стек
				CString num1 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString oper = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString num2 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString rez = Calculate(num1, oper, num2);
				if (rez == "Деление на ноль невозможно")
				{
					MessageBox(L"Деление на ноль невозможно");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				if (rez == "Недопустимый ввод")
				{
					MessageBox(L"Недопустимый ввод");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				GetDocument()->PushElement(rez, 1);
				isCommaInNumber = 1;
				numberStr = L"";
				numberStr.Append(rez);
				m_Number.SetWindowTextW(numberStr);
			}
		}
		else
		{
			wasPushLeftBracket = 0;
		}
	}
	else if (action)//можно без if что делать если произошла замена операции
	{
		int length = 0;
		if (action == 1 || action == 2 || action == 3 || action == 4 || action == 5)
			length = 1;
		if (action == 6)
			length = 5;
		if (action == 7)
			length = 7;
		enterStr = enterStr.Mid(0, enterStr.GetLength() - length);
		m_Edit.SetWindowTextW(enterStr);
		action = 3;
		if (prior <= 2)
		{
			enterStr.Append(L")t");
			for (int i = enterStr.GetLength() - 1; i > 0; i--)
				enterStr.SetAt(i, enterStr.GetAt(i-1));
			enterStr.SetAt(0, *"(");
		}
		enterStr.Append(L"*");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtndivide()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!action)
	{
		if (!wasPushRightBracket && !wasPushAnotherOp)
		{
			GetDocument()->PushElement(currentStr, 1);
			enterStr.Append(numberStr);
		}
		wasPushRightBracket = 0;
		wasPushAnotherOp = 0;
		enterStr.Append(L"/");
		action = 4;//запоминаем операцию
		m_Edit.SetWindowTextW(enterStr);

		if (!wasPushLeftBracket && GetDocument()->getCountOfNumbers() != 1)
		{
			if (prior >= 2)
			{
				//считаем результат и его в стек
				CString num1 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString oper = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString num2 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString rez = Calculate(num1, oper, num2);
				if (rez == "Деление на ноль невозможно")
				{
					MessageBox(L"Деление на ноль невозможно");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				if (rez == "Недопустимый ввод")
				{
					MessageBox(L"Недопустимый ввод");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				GetDocument()->PushElement(rez, 1);
				isCommaInNumber = 1;
				numberStr = L"";
				numberStr.Append(rez);
				m_Number.SetWindowTextW(numberStr);
			}
		}
		else
		{
			wasPushLeftBracket = 0;
		}
	}
	else if (action)//можно без if что делать если произошла замена операции
	{
		int length = 0;
		if (action == 1 || action == 2 || action == 3 || action == 4 || action == 5)
			length = 1;
		if (action == 6)
			length = 5;
		if (action == 7)
			length = 7;
		enterStr = enterStr.Mid(0, enterStr.GetLength() - length);
		m_Edit.SetWindowTextW(enterStr);
		action = 4;
		if (prior <= 2)
		{
			enterStr.Append(L")#");
			for (int i = enterStr.GetLength() - 1; i > 0; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 1));
			enterStr.SetAt(0, *"(");
		}
		enterStr.Append(L"/");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtneql()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (bracketCount)
	{
		MessageBox(L"Не хватает закрывающей скобки");
		return;
	}
	wasIql = 1;
	if (action)
	{
		PutAction();
		action = 0;
	}

	if (!wasPushRightBracket && !wasPushAnotherOp) {
		CString str;
		m_Number.GetWindowTextW(str);
		GetDocument()->PushElement(str, 1);
	}

	enterStr = L"";//Верхняя строка
	action = 0;//происходит ли выполнение операции
	prior = 0;//Приоритет последней операции в стеке
	m_Edit.SetWindowTextW(L"");
	int Index = GetDocument()->getNumElements()-1;
	CString num1;
	CString oper;
	CString num2;
	CString rez= currentStr;
	while (Index>0)
	{
		num1=GetDocument()->PopElement(Index)->getValue();
		--Index;
		oper = GetDocument()->PopElement(Index)->getValue();
		--Index;
		num2 = GetDocument()->PopElement(Index)->getValue();
		--Index;
		rez = Calculate(num1, oper, num2);
		if (rez == "Деление на ноль невозможно")
		{
			MessageBox(L"Деление на ноль невозможно");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		if (rez == "Недопустимый ввод")
		{
			MessageBox(L"Недопустимый ввод");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		++Index;
	}
	m_Number.SetWindowTextW(rez);
	numberStr = rez;//Нижняя строка
	currentStr = rez;//Вводимая в текущий момент строка
	wasPushRightBracket = 0;
	wasPushAnotherOp = 0;
	GetDocument()->PopElement(0);
}


void CEngineeringCulculatorView::OnBnClickedLeftbracket()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (wasPushRightBracket || wasPushAnotherOp)
	{
		MessageBox(L"Введите операцию");
		return;
	}
	wasPushLeftBracket = 1;
	bracketCount++;
	if (action)
	{
		PutAction();
		action = 0;
		numberStr = L"0";
		currentStr = L"0";
	}
	
	GetDocument()->PushElement(L"(", 3);
	enterStr.Append(L"(");
	m_Edit.SetWindowTextW(enterStr);
}


void CEngineeringCulculatorView::OnBnClickedRigthbracket()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!bracketCount)
	{
		return;
	}
	bracketCount--;
	if (action)
	{
		PutAction();
		action = 0;
	}

	if (!wasPushRightBracket && !wasPushAnotherOp) {
		GetDocument()->PushElement(currentStr, 1);
		enterStr.Append(numberStr);
	}
	currentStr = L"";
	enterStr.Append(L")");
	action = 0;                                                      
	m_Edit.SetWindowTextW(enterStr);

	int Index = GetDocument()->getNumElements() - 1;
	CString num1;
	CString oper=L"";
	CString num2;
	CString rez;
	while (oper != '(')
	{
		num1 = GetDocument()->PopElement(Index)->getValue();
		--Index;
		oper = GetDocument()->PopElement(Index)->getValue();
		--Index;
		if (oper == '(')
		{
			GetDocument()->PushElement(num1, 1);
			currentStr = num1;
			numberStr = num1;
			m_Number.SetWindowTextW(numberStr);
		}
		else
		{
			num2 = GetDocument()->PopElement(Index)->getValue();
			--Index;
			rez= Calculate(num1, oper, num2);
			if (rez == "Деление на ноль невозможно")
			{
				MessageBox(L"Деление на ноль невозможно");
				CEngineeringCulculatorView::OnBnClickedBtnclear();
				return;
			}
			if (rez == "Недопустимый ввод")
			{
				MessageBox(L"Недопустимый ввод");
				CEngineeringCulculatorView::OnBnClickedBtnclear();
				return;
			}
			GetDocument()->PushElement(rez, 1);
			isCommaInNumber = 1;
			++Index;
		}
	}
	wasPushRightBracket = 1;
}


void CEngineeringCulculatorView::OnBnClickedBtnsqrt()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		if (_wtof(num) < 0)
		{
			MessageBox(L"Недопустимый ввод");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		double Num = sqrt(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку sqrt(...)
		CString idBracket=L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength()-2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx-1; i>=0; i--)
		{
			idBracket = enterStr.GetAt(i);
		
			if (idBracket == '('|| idBracket == '+'|| idBracket == '-'|| idBracket == '*'|| idBracket == '/'|| i==0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i+1;
					break;
				}
				else 
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить sqrt

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"s");
			enterStr.SetAt(indx + 1, *"q");
			enterStr.SetAt(indx + 2, *"r");
			enterStr.SetAt(indx + 3, *"t");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"s");
			enterStr.SetAt(indx + 1, *"q");
			enterStr.SetAt(indx + 2, *"r");
			enterStr.SetAt(indx + 3, *"t");
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else 
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		if (_wtof(num) < 0)
		{
			MessageBox(L"Недопустимый ввод");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		double Num = sqrt(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"sqrt(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedMemclear()
{
	// TODO: добавьте свой код обработчика уведомлений
	GetDocument()->memory->memoryClear();
	m_IsMem.ShowWindow(SW_HIDE);
}


void CEngineeringCulculatorView::OnBnClickedMemread()
{
	// TODO: добавьте свой код обработчика уведомлений
	CString value;
	value.Format(L"%f", GetDocument()->memory->memoryRead());
	if (action)
	{
		PutAction();
		action = 0;
		numberStr = L"0";
		currentStr = L"0";
	}
	currentStr = value;
	numberStr = value;
	m_Number.SetWindowTextW(numberStr);
	//Вообще это не нужно, т.к. возвращается всегда число с точкой
	if (numberStr.Find('.', 0) != -1)
	{
		isCommaInNumber = 1;
	}
	wasMemRead = 1;
}


void CEngineeringCulculatorView::OnBnClickedMemsave()
{
	// TODO: добавьте свой код обработчика уведомлений
	GetDocument()->memory->memorySave(_tstof(currentStr));
	if(_tstof(currentStr)!=0)
		m_IsMem.ShowWindow(SW_SHOW);
}


void CEngineeringCulculatorView::OnBnClickedMemminus()
{
	// TODO: добавьте свой код обработчика уведомлений
	GetDocument()->memory->memoryMinus(_tstof(currentStr));
}


void CEngineeringCulculatorView::OnBnClickedMemplus()
{
	// TODO: добавьте свой код обработчика уведомлений
	GetDocument()->memory->memoryPlus(_tstof(currentStr));
}


void CEngineeringCulculatorView::OnBnClickedBtnclear()
{
	// TODO: добавьте свой код обработчика уведомлений
	enterStr = L"";//Верхняя строка
	numberStr = L"0";//Нижняя строка
	isCommaInNumber = 0;//Индикатор запятой в числе
	action = 0;//происходит ли выполнение операции и какой
	prior = 0;//Приоритет последней операции в стеке
	wasIql = 0;// была ли нажата кнопка равно
	currentStr = L"0";//Вводимая в текущий момент строка
	wasPushLeftBracket = 0;
	wasPushRightBracket = 0;
	wasPushAnotherOp = 0;
	bracketCount = 0;

	m_Number.SetWindowTextW(numberStr);
	m_Edit.SetWindowTextW(enterStr);
	int size = GetDocument()->stack.GetSize();
	int count = 0;
	for (int i = size-1; i>= 0 ; i--)
	{
		GetDocument()->PopElement(i);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnreverse()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
		//action = 0;
	}
	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = -1*_wtof(num);
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку negate(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i+1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить negate

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"######");
			for (int i = enterStr.GetLength() - 1; i >= indx + 6; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 6));
			enterStr.SetAt(indx, *"n");
			enterStr.SetAt(indx + 1, *"e");
			enterStr.SetAt(indx + 2, *"g");
			enterStr.SetAt(indx + 3, *"a");
			enterStr.SetAt(indx + 4, *"t");
			enterStr.SetAt(indx + 5, *"e");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#######)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 7; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 7));
			enterStr.SetAt(indx, *"n");
			enterStr.SetAt(indx + 1, *"e");
			enterStr.SetAt(indx + 2, *"g");
			enterStr.SetAt(indx + 3, *"a");
			enterStr.SetAt(indx + 4, *"t");
			enterStr.SetAt(indx + 5, *"e");
			enterStr.SetAt(indx + 6, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = -1*_wtof(num);
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"negate(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnconv()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		CString rez= Calculate(num,L"/",L"1");
		if (rez == "Деление на ноль невозможно")
		{
			MessageBox(L"Деление на ноль невозможно");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку reciproc(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить reciproc

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"########");
			for (int i = enterStr.GetLength() - 1; i >= indx + 8; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 8));
			enterStr.SetAt(indx, *"r");
			enterStr.SetAt(indx + 1, *"e");
			enterStr.SetAt(indx + 2, *"c");
			enterStr.SetAt(indx + 3, *"i");
			enterStr.SetAt(indx + 4, *"p");
			enterStr.SetAt(indx + 5, *"r");
			enterStr.SetAt(indx + 6, *"o");
			enterStr.SetAt(indx + 7, *"c");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#########)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 9; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 9));
			enterStr.SetAt(indx, *"r");
			enterStr.SetAt(indx + 1, *"e");
			enterStr.SetAt(indx + 2, *"c");
			enterStr.SetAt(indx + 3, *"i");
			enterStr.SetAt(indx + 4, *"p");
			enterStr.SetAt(indx + 5, *"r");
			enterStr.SetAt(indx + 6, *"o");
			enterStr.SetAt(indx + 7, *"c");
			enterStr.SetAt(indx + 8, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		CString rez = Calculate(num, L"/", L"1");
		if (rez == "Деление на ноль невозможно")
		{
			MessageBox(L"Деление на ноль невозможно");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"reciproc(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnsin()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		if(m_AngleMeasure == INT_DEGREES)
		{
			Num = Num * (180 / M_PI);
		}
		Num = sin(Num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку sin(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить sin

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"s");
			enterStr.SetAt(indx + 1, *"i");
			enterStr.SetAt(indx + 2, *"n");
			if (m_AngleMeasure == INT_DEGREES)
			{
				enterStr.SetAt(indx + 3, *"d");
			}
			else
			{
				enterStr.SetAt(indx + 3, *"r");
			}
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"s");
			enterStr.SetAt(indx + 1, *"i");
			enterStr.SetAt(indx + 2, *"n");
			if (m_AngleMeasure == INT_DEGREES)
			{
				enterStr.SetAt(indx + 3, *"d");
			}
			else
			{
				enterStr.SetAt(indx + 3, *"r");
			}
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		if (m_AngleMeasure == INT_DEGREES)
		{
			Num = Num * (M_PI / 180);
		}
		Num = sin(Num);
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);
		if (m_AngleMeasure == INT_DEGREES)
		{
			enterStr.Append(L"sind(" + num + ")");
		}
		else
		{
			enterStr.Append(L"sinr(" + num + ")");
		}
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnfact()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		CString rez= Fact(_wtof(num));
		if (rez == "Слишком большое число")
		{
			MessageBox(L"Слишком большое число");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		if (rez == "Недопустимый ввод")
		{
			MessageBox(L"Недопустимый ввод");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку fact(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить fact

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"f");
			enterStr.SetAt(indx + 1, *"a");
			enterStr.SetAt(indx + 2, *"c");
			enterStr.SetAt(indx + 3, *"t");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"f");
			enterStr.SetAt(indx + 1, *"a");
			enterStr.SetAt(indx + 2, *"c");
			enterStr.SetAt(indx + 3, *"t");
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		CString rez =Fact(_wtof(num));
		if (rez == "Слишком большое число")
		{
			MessageBox(L"Слишком большое число");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		if (rez == "Недопустимый ввод")
		{
			MessageBox(L"Недопустимый ввод");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"fact(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtncos()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		if (m_AngleMeasure == INT_DEGREES)
		{
			Num = Num * (M_PI / 180);
		}
		Num = cos(Num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку cos(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить cos

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"s");
			if (m_AngleMeasure == INT_DEGREES)
			{
				enterStr.SetAt(indx + 3, *"d");
			}
			else
			{
				enterStr.SetAt(indx + 3, *"r");
			}
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"s");
			if (m_AngleMeasure == INT_DEGREES)
			{
				enterStr.SetAt(indx + 3, *"d");
			}
			else
			{
				enterStr.SetAt(indx + 3, *"r");
			}
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		if (m_AngleMeasure == INT_DEGREES)
		{
			Num = Num * (M_PI / 180);
		}
		Num = cos(Num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);
		if (m_AngleMeasure == INT_DEGREES)
		{
			enterStr.Append(L"cosd(" + num + ")");
		}
		else
		{
			enterStr.Append(L"cosr(" + num + ")");
		}
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtntan()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		if (m_AngleMeasure == INT_DEGREES)
		{
			Num = Num * (M_PI / 180);
		}
		Num = tan(Num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку tan(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить tan

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"t");
			enterStr.SetAt(indx + 1, *"a");
			enterStr.SetAt(indx + 2, *"n");
			if (m_AngleMeasure == INT_DEGREES)
			{
				enterStr.SetAt(indx + 3, *"d");
			}
			else
			{
				enterStr.SetAt(indx + 3, *"r");
			}
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"t");
			enterStr.SetAt(indx + 1, *"a");
			enterStr.SetAt(indx + 2, *"n");
			if (m_AngleMeasure == INT_DEGREES)
			{
				enterStr.SetAt(indx + 3, *"d");
			}
			else
			{
				enterStr.SetAt(indx + 3, *"r");
			}
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		if (m_AngleMeasure == INT_DEGREES)
		{
			Num = Num * (M_PI / 180);
		}
		Num = tan(Num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);
		if (m_AngleMeasure == INT_DEGREES)
		{
			enterStr.Append(L"tand(" + num + ")");
		}
		else
		{
			enterStr.Append(L"tanr(" + num + ")");
		}
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnpowten()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;
		CString rez;
		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		if (_wtof(num) > 22)
		{
			MessageBox(L"Слишком большое число");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		double Num = pow(10,_wtof(num));
		
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку powten(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить powten

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"######");
			for (int i = enterStr.GetLength() - 1; i >= indx + 6; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 6));
			enterStr.SetAt(indx, *"p");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"w");
			enterStr.SetAt(indx + 3, *"t");
			enterStr.SetAt(indx + 4, *"e");
			enterStr.SetAt(indx + 5, *"n");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#######)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 7; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 7));
			enterStr.SetAt(indx, *"p");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"w");
			enterStr.SetAt(indx + 3, *"t");
			enterStr.SetAt(indx + 4, *"e");
			enterStr.SetAt(indx + 5, *"n");
			enterStr.SetAt(indx + 6, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		if (_wtof(num) > 22)
		{
			MessageBox(L"Слишком большое число");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		double Num = pow(10,_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"powten(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnpow()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!action)
	{
		if (!wasPushRightBracket && !wasPushAnotherOp)
		{
			GetDocument()->PushElement(currentStr, 1);
			enterStr.Append(numberStr);
		}
		wasPushRightBracket = 0;
		wasPushAnotherOp = 0;
		enterStr.Append(L"^");
		action = 5;//запоминаем операцию
		m_Edit.SetWindowTextW(enterStr);

		if (!wasPushLeftBracket && GetDocument()->getCountOfNumbers() != 1)
		{
			if (prior >= 3)
			{
				//считаем результат и его в стек
				CString num1 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString oper = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString num2 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString rez = Calculate(num1, oper, num2);
				if (rez == "Деление на ноль невозможно")
				{
					MessageBox(L"Деление на ноль невозможно");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				if (rez == "Недопустимый ввод")
				{
					MessageBox(L"Недопустимый ввод");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				GetDocument()->PushElement(rez, 1);
				isCommaInNumber = 1;
				numberStr = L"";
				numberStr.Append(rez);
				m_Number.SetWindowTextW(numberStr);
			}
		}
		else
		{
			wasPushLeftBracket = 0;
		}
	}
	else if (action)//можно без if что делать если произошла замена операции
	{
		int length = 0;
		if (action == 1 || action == 2 || action == 3 || action == 4 || action == 5)
			length = 1;
		if (action == 6)
			length = 5;
		if (action == 7)
			length = 7;
		enterStr = enterStr.Mid(0, enterStr.GetLength() - length);
		m_Edit.SetWindowTextW(enterStr);
		action = 5;
		if (prior <= 3)
		{
			enterStr.Append(L")#");
			for (int i = enterStr.GetLength() - 1; i > 0; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 1));
			enterStr.SetAt(0, *"(");
		}
		enterStr.Append(L"^");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnmod()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!action)
	{
		if (!wasPushRightBracket && !wasPushAnotherOp)
		{
			//wasPushRightBracket = 0;
			GetDocument()->PushElement(currentStr, 1);
			enterStr.Append(numberStr);
		}
		wasPushRightBracket = 0;
		wasPushAnotherOp = 0;
		//enterStr.Append(numberStr);
		enterStr.Append(L" mod ");
		action = 6;//запоминаем операцию
		m_Edit.SetWindowTextW(enterStr);

		if (!wasPushLeftBracket && GetDocument()->getCountOfNumbers() != 1)
		{
			if (prior >= 3)
			{
				//считаем результат и его в стек
				CString num1 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString oper = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString num2 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString rez = Calculate(num1, oper, num2);
				if (rez == "Деление на ноль невозможно")
				{
					MessageBox(L"Деление на ноль невозможно");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				if (rez == "Недопустимый ввод")
				{
					MessageBox(L"Недопустимый ввод");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				GetDocument()->PushElement(rez, 1);
				isCommaInNumber = 1;
				numberStr = L"";
				numberStr.Append(rez);
				m_Number.SetWindowTextW(numberStr);
			}
		}
		else
		{
			wasPushLeftBracket = 0;
		}
	}
	else if (action)//можно без if что делать если произошла замена операции
	{
		int length=0;
		if (action == 1 || action == 2 || action == 3 || action == 4 || action == 5)
			length = 1;
		if(action==6)
			length = 5;
		if (action == 7)
			length = 7;
		enterStr = enterStr.Mid(0, enterStr.GetLength() - length);
		//enterStr.Append(L"*");
		m_Edit.SetWindowTextW(enterStr);
		action = 6;
		if (prior <= 3)
		{
			enterStr.Append(L")#");
			for (int i = enterStr.GetLength() - 1; i > 0; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 1));
			enterStr.SetAt(0, *"(");
		}
		enterStr.Append(L" mod ");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnEditCopy()
{
	// TODO: добавьте свой код обработчика команд
	m_Number.SetSel(0, m_Number.GetWindowTextLengthW());
	m_Number.Copy();
}

void CEngineeringCulculatorView::OnEditPaste()
{
	// TODO: добавьте свой код обработчика команд
	CString fromClipboard;//в эту переменную сохраним текст из буфера обмена
	if (OpenClipboard())//открываем буфер обмена
	{
		HANDLE hData = GetClipboardData(CF_TEXT);//извлекаем текст из буфера обмена
		char* chBuffer = (char*)GlobalLock(hData);//блокируем память
		fromClipboard = chBuffer;
		GlobalUnlock(hData);//разблокируем память
		CloseClipboard();//закрываем буфер обмена
	}
	int countComma = 0;
	for (int i = 0; i < fromClipboard.GetLength(); i++)
	{
		if (!isdigit(fromClipboard[i]) && fromClipboard[i]!='.')
		{
			return;
		}
		if (fromClipboard[i] == '.')
			countComma++;
	}
	if (countComma > 1)
		return;

	m_Number.SetReadOnly(FALSE);
	m_Number.SetWindowTextW(L"");
	if (action)
	{
		PutAction();
		action = 0;
		numberStr = L"0";
		currentStr = L"0";
	}
	m_Number.Paste();
	m_Number.GetWindowTextW(currentStr);
	m_Number.GetWindowTextW(numberStr);
	if (numberStr.Find('.', 0)!=-1)
	{
		isCommaInNumber = 1;
	}
	m_Number.SetReadOnly(TRUE);
}

void CEngineeringCulculatorView::OnFileOpen()
{
	// TODO: добавьте свой код обработчика команд
	GetDocument()->OnNewDocument();//Необходимо для того, чтобы в документ можно было записать данные,
	theApp.ResetFile();            //а затем загрузить их из того же документа
}

/*Кажется нет никакого способа передать ключевые события в CFormView, 
  поэтому я решил переопределить виртуальную функцию PreTranslateMessage(MSG* pMsg)
  и ловить события нажатия клавиши на клавиатуре в ней.*/
BOOL CEngineeringCulculatorView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: добавьте специализированный код или вызов базового класса
	if (pMsg->message == WM_KEYDOWN) {
		if(pMsg->wParam== VK_NUMPAD1|| pMsg->wParam == '1'){
				BtnClick(L"1");	
		}
		if(pMsg->wParam== VK_NUMPAD2|| pMsg->wParam == '2'){
				BtnClick(L"2");	
		}
		if(pMsg->wParam== VK_NUMPAD3|| pMsg->wParam == '3'){
				BtnClick(L"3");	
		}
		if(pMsg->wParam== VK_NUMPAD4|| pMsg->wParam == '4'){
				BtnClick(L"4");	
		}
		if(pMsg->wParam== VK_NUMPAD5|| pMsg->wParam == '5'){
				BtnClick(L"5");	
		}
		if(pMsg->wParam== VK_NUMPAD6|| pMsg->wParam == '6'){
				BtnClick(L"6");	
		}
		if(pMsg->wParam== VK_NUMPAD7|| pMsg->wParam == '7'){
				BtnClick(L"7");	
		}
		if((pMsg->wParam== VK_NUMPAD8|| pMsg->wParam == '8')&& !::GetAsyncKeyState(VK_SHIFT)){
				BtnClick(L"8");	
		}
		if((pMsg->wParam== VK_NUMPAD9|| pMsg->wParam == '9') && !::GetAsyncKeyState(VK_SHIFT)){
				BtnClick(L"9");	
		}
		if((pMsg->wParam== VK_NUMPAD0|| pMsg->wParam == '0') && !::GetAsyncKeyState(VK_SHIFT)){
				BtnClick(L"0");	
		}
		if ((pMsg->wParam == '8' && ::GetAsyncKeyState (VK_SHIFT))|| pMsg->wParam == 106) {
			OnBnClickedBtnmultiply();
		}
		if (pMsg->wParam == '9' && ::GetAsyncKeyState(VK_SHIFT)) {
			OnBnClickedLeftbracket();
		}
		if (pMsg->wParam == '0' && ::GetAsyncKeyState(VK_SHIFT)) {
			OnBnClickedRigthbracket();
		}
		if (pMsg->wParam == 189 || pMsg->wParam == 109) {
			OnBnClickedBtnminus();
		}
		if ((pMsg->wParam == 187 && ::GetAsyncKeyState(VK_SHIFT)) || pMsg->wParam == 107) {
			OnBnClickedBtnplus();
		}
		if (pMsg->wParam == 191 || pMsg->wParam == 111) {
			OnBnClickedBtndivide();
		}
		if (pMsg->wParam == 191 || pMsg->wParam == 111) {
			OnBnClickedBtndivide();
		}
		if ((pMsg->wParam == 187 && !::GetAsyncKeyState(VK_SHIFT) )|| pMsg->wParam == 13) {
			OnBnClickedBtneql();
		}
		return TRUE;
	}
	else if (pMsg->message == WM_KEYUP)
		return TRUE;
	else
	return CFormView::PreTranslateMessage(pMsg);
}

void  CEngineeringCulculatorView::OnBnClickedGrad()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (IsDlgButtonChecked(IDC_GRAD))
	{
		m_AngleMeasure = INT_DEGREES;
	}
}

void  CEngineeringCulculatorView::OnBnClickedRad()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (IsDlgButtonChecked(IDC_RAD))
	{
		m_AngleMeasure = INT_RADIANS;
	}
}

void CEngineeringCulculatorView::OnBnClickedBtncuberoot()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = pow(_wtof(num), (1.0 / 3.0));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку coberoot(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить coberoot

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"########");
			for (int i = enterStr.GetLength() - 1; i >= indx + 8; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 8));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"u");
			enterStr.SetAt(indx + 2, *"b");
			enterStr.SetAt(indx + 3, *"e");
			enterStr.SetAt(indx + 4, *"r");
			enterStr.SetAt(indx + 5, *"o");
			enterStr.SetAt(indx + 6, *"o");
			enterStr.SetAt(indx + 7, *"t");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#########)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 9; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 9));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"u");
			enterStr.SetAt(indx + 2, *"b");
			enterStr.SetAt(indx + 3, *"e");
			enterStr.SetAt(indx + 4, *"r");
			enterStr.SetAt(indx + 5, *"o");
			enterStr.SetAt(indx + 6, *"o");
			enterStr.SetAt(indx + 7, *"t");
			enterStr.SetAt(indx + 8, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = pow(_wtof(num),(1.0/3.0));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"cuberoot(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}

void CEngineeringCulculatorView::OnBnClickedBtnsqr()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num)* _wtof(num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку sqr(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить sqr

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"###");
			for (int i = enterStr.GetLength() - 1; i >= indx + 3; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 3));
			enterStr.SetAt(indx, *"s");
			enterStr.SetAt(indx + 1, *"q");
			enterStr.SetAt(indx + 2, *"r");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"s");
			enterStr.SetAt(indx + 1, *"q");
			enterStr.SetAt(indx + 2, *"r");
			enterStr.SetAt(indx + 3, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num)* _wtof(num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"sqr(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}

void CEngineeringCulculatorView::OnBnClickedBtncube()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num) * _wtof(num)* _wtof(num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку cube(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить cube

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"u");
			enterStr.SetAt(indx + 2, *"b");
			enterStr.SetAt(indx + 3, *"e");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"u");
			enterStr.SetAt(indx + 2, *"b");
			enterStr.SetAt(indx + 3, *"e");
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num) * _wtof(num)* _wtof(num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"cube(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnyroot()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!action)
	{
		if (!wasPushRightBracket && !wasPushAnotherOp)
		{
			//wasPushRightBracket = 0;
			GetDocument()->PushElement(currentStr, 1);
			enterStr.Append(numberStr);
		}
		wasPushRightBracket = 0;
		wasPushAnotherOp = 0;
		//enterStr.Append(numberStr);
		enterStr.Append(L" yroot ");
		action = 7;//запоминаем операцию
		m_Edit.SetWindowTextW(enterStr);

		if (!wasPushLeftBracket && GetDocument()->getCountOfNumbers() != 1)
		{
			if (prior >= 3)
			{
				//считаем результат и его в стек
				CString num1 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString oper = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString num2 = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
				CString rez = Calculate(num1, oper, num2);
				if (rez == "Недопустимый ввод")
				{
					MessageBox(L"Недопустимый ввод");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				if (rez == "Деление на ноль невозможно")
				{
					MessageBox(L"Деление на ноль невозможно");
					CEngineeringCulculatorView::OnBnClickedBtnclear();
					return;
				}
				GetDocument()->PushElement(rez, 1);
				isCommaInNumber = 1;
				numberStr = L"";
				numberStr.Append(rez);
				m_Number.SetWindowTextW(numberStr);
			}
		}
		else
		{
			wasPushLeftBracket = 0;
		}
	}
	else if (action)//можно без if что делать если произошла замена операции
	{
		int length = 0;
		if (action == 1 || action == 2 || action == 3 || action == 4 || action == 5)
			length = 1;
		if (action == 6)
			length = 5;
		if (action == 7)
			length = 7;
		enterStr = enterStr.Mid(0, enterStr.GetLength() - length);
		m_Edit.SetWindowTextW(enterStr);
		action = 7;
		if (prior <= 3)
		{
			enterStr.Append(L")#");
			for (int i = enterStr.GetLength() - 1; i > 0; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 1));
			enterStr.SetAt(0, *"(");
		}
		enterStr.Append(L" yroot ");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnpi()
{
	// TODO: добавьте свой код обработчика уведомлений
	CString strPI;
	strPI.Format(L"%f", M_PI);
	if (wasPushAnotherOp)
	{
		MessageBox(L"Введите операцию");
		return;
	}

	if (action)
	{
		PutAction();
		action = 0;
		numberStr = L"0";
		currentStr = L"0";
	}

	if (numberStr == L"0")
	{
		numberStr = strPI;
		currentStr = strPI;
		isCommaInNumber = 1;
		wasIql = 0;
		wasMemRead = 0;
	}
	else
	{
		if (wasIql || wasMemRead)
		{
			wasIql = 0;
			wasMemRead = 0;
			numberStr = strPI;
			currentStr = strPI;
			isCommaInNumber = 1;
		}
		else
		{
			numberStr = strPI;
			currentStr = strPI;
			isCommaInNumber = 1;
		}
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtnexp()
{
	// TODO: добавьте свой код обработчика уведомлений
	CString strE;
	strE.Format(L"%f", M_E);
	if (wasPushAnotherOp)
	{
		MessageBox(L"Введите операцию");
		return;
	}

	if (action)
	{
		PutAction();
		action = 0;
		numberStr = L"0";
		currentStr = L"0";
	}

	if (numberStr == L"0")
	{
		numberStr = strE;
		currentStr = strE;
		isCommaInNumber = 1;
		wasIql = 0;
		wasMemRead = 0;
	}
	else
	{
		if (wasIql || wasMemRead)
		{
			wasIql = 0;
			wasMemRead = 0;
			numberStr = strE;
			currentStr = strE;
			isCommaInNumber = 1;
		}
		else {
			numberStr = strE;
			currentStr = strE;
			isCommaInNumber = 1;
		}
	}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtnln()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		if (_wtof(num) <= 0)
		{
			MessageBox(L"Недопустимый ввод");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		double Num = log(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку ln(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить ln

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"##");
			for (int i = enterStr.GetLength() - 1; i >= indx + 2; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 2));
			enterStr.SetAt(indx, *"l");
			enterStr.SetAt(indx + 1, *"n");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"###)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 3; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 3));
			enterStr.SetAt(indx, *"l");
			enterStr.SetAt(indx + 1, *"n");
			enterStr.SetAt(indx + 2, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		if (_wtof(num) <= 0)
		{
			MessageBox(L"Недопустимый ввод");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		double Num = log(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"ln(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnlog()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		if (_wtof(num) <= 0)
		{
			MessageBox(L"Недопустимый ввод");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		double Num = log10(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку log(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить log

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"###");
			for (int i = enterStr.GetLength() - 1; i >= indx + 3; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 3));
			enterStr.SetAt(indx, *"l");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"g");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"l");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"g");
			enterStr.SetAt(indx + 3, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		if (_wtof(num) <= 0)
		{
			MessageBox(L"Недопустимый ввод");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		double Num = log10(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"log(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnint()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		int Num = (int)_wtof(num);
		CString rez;
		rez.Format(L"%d", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 0;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку Int(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить Int

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"###");
			for (int i = enterStr.GetLength() - 1; i >= indx + 3; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 3));
			enterStr.SetAt(indx, *"I");
			enterStr.SetAt(indx + 1, *"n");
			enterStr.SetAt(indx + 2, *"t");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"I");
			enterStr.SetAt(indx + 1, *"n");
			enterStr.SetAt(indx + 2, *"t");
			enterStr.SetAt(indx + 3, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		int Num = (int)_wtof(num);
		CString rez;
		rez.Format(L"%d", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 0;

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"Int(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnsinh()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		Num = sinh(Num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку sinh(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить sinh

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"s");
			enterStr.SetAt(indx + 1, *"i");
			enterStr.SetAt(indx + 2, *"n");
			enterStr.SetAt(indx + 3, *"h");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"s");
			enterStr.SetAt(indx + 1, *"i");
			enterStr.SetAt(indx + 2, *"n");
			enterStr.SetAt(indx + 3, *"h");
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		Num = sinh(Num);
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);
		enterStr.Append(L"sinh(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtncosh()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		Num = cosh(Num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку cosh(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить cosh

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"s");
			enterStr.SetAt(indx + 3, *"h");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"s");
			enterStr.SetAt(indx + 3, *"h");
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		Num = cosh(Num);
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);
		enterStr.Append(L"cosh(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtntanh()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		Num = tanh(Num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку tanh(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить tanh

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"t");
			enterStr.SetAt(indx + 1, *"a");
			enterStr.SetAt(indx + 2, *"n");
			enterStr.SetAt(indx + 3, *"h");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"t");
			enterStr.SetAt(indx + 1, *"a");
			enterStr.SetAt(indx + 2, *"n");
			enterStr.SetAt(indx + 3, *"h");
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		Num = tanh(Num);
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);
		enterStr.Append(L"tanh(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtncot()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		if (m_AngleMeasure == INT_DEGREES)
		{
			Num = Num * (M_PI / 180);
		}
		Num = tan((M_PI/2.0) - Num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку cot(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить cot

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"t");
			if (m_AngleMeasure == INT_DEGREES)
			{
				enterStr.SetAt(indx + 3, *"d");
			}
			else
			{
				enterStr.SetAt(indx + 3, *"r");
			}
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"t");
			if (m_AngleMeasure == INT_DEGREES)
			{
				enterStr.SetAt(indx + 3, *"d");
			}
			else
			{
				enterStr.SetAt(indx + 3, *"r");
			}
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = _wtof(num);
		if (m_AngleMeasure == INT_DEGREES)
		{
			Num = Num * (M_PI / 180);
		}
		Num = tan((M_PI / 2.0) - Num);
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
		isCommaInNumber = 1;

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);
		if (m_AngleMeasure == INT_DEGREES)
		{
			enterStr.Append(L"cotd(" + num + ")");
		}
		else
		{
			enterStr.Append(L"cotr(" + num + ")");
		}
		m_Edit.SetWindowTextW(enterStr);
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnpowe()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (action)
	{
		PutAction();
	}

	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = pow(M_E,_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);
		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		//Добавление в основную строку powe(...)
		CString idBracket = L"";
		int bracketCount = 1;
		int indx;//Искомый индекс
		for (indx = enterStr.GetLength() - 2; 1; indx--)
		{
			idBracket = enterStr.GetAt(indx);
			if (idBracket == ')')
				bracketCount++;
			if (idBracket == '(')
				bracketCount--;
			if (idBracket == '(' && bracketCount == 0)
				break;
		}
		//indx==индексу на котором стоит искомая парная скобка
		idBracket = "";

		int ifFoundFirstly = 1;
		for (int i = indx - 1; i >= 0; i--)
		{
			idBracket = enterStr.GetAt(i);

			if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/' || i == 0)
			{
				if (idBracket == '(' || idBracket == '+' || idBracket == '-' || idBracket == '*' || idBracket == '/')
				{
					indx = i + 1;
					break;
				}
				else
				{
					indx = i;
					break;
				}
			}
			ifFoundFirstly++;
		}
		//indx==место в которое нужно вставить powe

		if (ifFoundFirstly == 1)
		{
			enterStr.Append(L"####");
			for (int i = enterStr.GetLength() - 1; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"p");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"w");
			enterStr.SetAt(indx + 3, *"e");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"#####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 5; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 5));
			enterStr.SetAt(indx, *"p");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"w");
			enterStr.SetAt(indx + 3, *"e");
			enterStr.SetAt(indx + 4, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		CString numberFromNumberField;
		m_Number.GetWindowTextW(numberFromNumberField);
		GetDocument()->PushElement(numberFromNumberField, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = pow(M_E, _wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		isCommaInNumber = 1;
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"powe(" + num + ")");
		m_Edit.SetWindowTextW(enterStr);
	}
}
