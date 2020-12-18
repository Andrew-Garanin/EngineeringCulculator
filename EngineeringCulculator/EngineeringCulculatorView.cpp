﻿
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
	if (oper == "*")
	{
		CString str;
		str.Format(L"%f", Num1 * Num2);
		return str;
	}
}
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
ON_BN_CLICKED(IDC_LEFTBRACKET, &CEngineeringCulculatorView::OnBnClickedLeftbracket)
ON_BN_CLICKED(IDC_RIGTHBRACKET, &CEngineeringCulculatorView::OnBnClickedRigthbracket)
ON_BN_CLICKED(IDC_BTNSQRT, &CEngineeringCulculatorView::OnBnClickedBtnsqrt)
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
	wasPushAnotherOp = 0;
	if (action)
	{
		if (action == 1)
		{
			GetDocument()->PushElement(L"+", 2);//Кладем знак операии в стек
			prior = 1;
		}
		if (action == 3)
		{
			GetDocument()->PushElement(L"*", 2);//Кладем знак операии в стек
			prior = 2;
		}
		action = 0;
		numberStr = L"0";
		currentStr = L"0";
	}

	if (numberStr == L"0") 
		{
			numberStr = L"1";
			currentStr = L"1";
			isCommaInNumber = 0;
		}
	else 
		{
			//numberStr = L"";????????????
			currentStr.Append(L"1");
			numberStr.Append(L"1");
			//action = 0;
			

			if (wasIql)
				{
					wasIql = 0;
					numberStr = L"1";
					currentStr = L"1";
				}
			//numberStr.Append(L"1");
			//currentStr.Append(L"1");
		}
	m_Number.SetWindowTextW(numberStr);
}


void CEngineeringCulculatorView::OnBnClickedBtn2()
{
	// TODO: добавьте свой код обработчика уведомлений
	wasPushAnotherOp = 0;
	if (action)
	{
		if (action == 1)
		{
			GetDocument()->PushElement(L"+", 2);//Кладем знак операии в стек
			prior = 1;
		}
		if (action == 3)
		{
			GetDocument()->PushElement(L"*", 2);//Кладем знак операии в стек
			prior = 2;
		}
		action = 0;
		numberStr = L"0";
		currentStr = L"0";
	}

	if (numberStr == L"0")
	{
		numberStr = L"2";
		currentStr = L"2";
		isCommaInNumber = 0;
	}
	else
	{
		//numberStr = L"";????????????
		currentStr.Append(L"2");
		numberStr.Append(L"2");
		//action = 0;


		if (wasIql)
		{
			wasIql = 0;
			numberStr = L"2";
			currentStr = L"2";
		}
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
			//wasPushRightBracket = 0;
			GetDocument()->PushElement(currentStr, 1);
			enterStr.Append(numberStr);
		}
		wasPushRightBracket = 0;
		wasPushAnotherOp = 0;
		//enterStr.Append(numberStr);
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
				GetDocument()->PushElement(rez, 1);
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
		enterStr = enterStr.Mid(0, enterStr.GetLength() - 1);
		enterStr.Append(L"+");
		m_Edit.SetWindowTextW(enterStr);
		action = 1;
		/*if (prior <= 1)
		{
			enterStr.Append(L")");
			for (int i = enterStr.GetLength() - 1; i >= 0; i--)
				enterStr.SetAt(i+1,enterStr.GetAt(i));
			enterStr.SetAt(0,*"(");
		}*/
	}
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
				GetDocument()->PushElement(rez, 1);
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
		enterStr = enterStr.Mid(0, enterStr.GetLength() - 1);
		//enterStr.Append(L"*");
		m_Edit.SetWindowTextW(enterStr);
		action = 3;
		if (prior <= 2)
		{
			enterStr.Append(L")t");
			for (int i = enterStr.GetLength() - 1; i > 0; i--)
				enterStr.SetAt(i, enterStr.GetAt(i-1));
			enterStr.SetAt(0, *"(");
			enterStr.Append(L"*");
			//currentStr = enterStr;
			m_Edit.SetWindowTextW(enterStr);
		}
	}
}


void CEngineeringCulculatorView::OnBnClickedBtndivide()
{
	// TODO: добавьте свой код обработчика уведомлений
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
		if (action == 1)
		{
			GetDocument()->PushElement(L"+", 2);//Кладем знак операии в стек
			prior = 1;
		}
		if (action == 3)
		{
			GetDocument()->PushElement(L"*", 2);//Кладем знак операии в стек
			prior = 2;
		}
		action = 0;
	}

	if (currentStr != "" && !wasPushRightBracket &&!wasPushAnotherOp)
		GetDocument()->PushElement(currentStr, 1);

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
		GetDocument()->PushElement(rez, 1);
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
	wasPushLeftBracket = 1;
	bracketCount++;
	if (action)
	{
		if (action == 1)
		{
			GetDocument()->PushElement(L"+", 2);//Кладем знак операии в стек
			prior = 1;
		}
		if (action == 3)
		{
			GetDocument()->PushElement(L"*", 2);//Кладем знак операии в стек
			prior = 2;
		}
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
	//wasPushRightBracket = 1;
	if (!bracketCount)
	{
		return;
	}
	bracketCount--;
	if (action)
	{
		if (action == 1)
		{
			GetDocument()->PushElement(L"+", 2);//Кладем знак операии в стек
			prior = 1;
		}
		if (action == 3)
		{
			GetDocument()->PushElement(L"*", 2);//Кладем знак операии в стек
			prior = 2;
		}
		action = 0;
	}

	if (!wasPushRightBracket && !wasPushAnotherOp) {
		GetDocument()->PushElement(currentStr, 1);
		enterStr.Append(numberStr);
	}
	currentStr = L"";
	//enterStr.Append(numberStr);
	enterStr.Append(L")");
	action = 0;                                                      //ПОка хз что с этим делать
	//prior = 3;
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
			GetDocument()->PushElement(rez, 1);
			++Index;
		}
	}
	wasPushRightBracket = 1;
}


void CEngineeringCulculatorView::OnBnClickedBtnsqrt()
{
	// TODO: добавьте свой код обработчика уведомлений
	//action = 0;
	if (action)
	{
		if (action == 1)
		{
			GetDocument()->PushElement(L"+", 2);//Кладем знак операии в стек
			prior = 1;
		}
		if (action == 3)
		{
			GetDocument()->PushElement(L"*", 2);//Кладем знак операии в стек
			prior = 2;
		}
		//action = 0;
	}
	//if (currentStr != "" && !wasPushRightBracket && !wasPushAnotherOp && wasPushLeftBracket) //&& action)
	//	GetDocument()->PushElement(currentStr, 1);
	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = sqrt(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);
	}
	else {
		GetDocument()->PushElement(currentStr, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = sqrt(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);
	}
}
