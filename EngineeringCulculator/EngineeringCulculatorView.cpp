
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
		str.Format(L"%d", rez);
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
}

// CEngineeringCulculatorView
void CEngineeringCulculatorView::BtnClick(CString number)
{
	// TODO: добавьте свой код обработчика уведомлений
	wasPushAnotherOp = 0;
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
		prior = 2;
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
	DDX_Control(pDX, IDC_M, m_IsMem);
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
	}
}


void CEngineeringCulculatorView::OnBnClickedBtnminus()
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
		action = 4;
		if (prior <= 2)
		{
			enterStr.Append(L")#");
			for (int i = enterStr.GetLength() - 1; i > 0; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 1));
			enterStr.SetAt(0, *"(");
			enterStr.Append(L"/");
			//currentStr = enterStr;
			m_Edit.SetWindowTextW(enterStr);
		}
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
		if (rez == "Деление на ноль невозможно")
		{
			MessageBox(L"Деление на ноль невозможно");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
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
	//wasPushRightBracket = 1;
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
			if (rez == "Деление на ноль невозможно")
			{
				MessageBox(L"Деление на ноль невозможно");
				CEngineeringCulculatorView::OnBnClickedBtnclear();
				return;
			}
			GetDocument()->PushElement(rez, 1);
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
		double Num = sqrt(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
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
	currentStr = value;
	numberStr = value;
	m_Number.SetWindowTextW(numberStr);
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
	//if (currentStr != "" && !wasPushRightBracket && !wasPushAnotherOp && wasPushLeftBracket) //&& action)
	//	GetDocument()->PushElement(currentStr, 1);
	if (wasPushRightBracket || wasPushAnotherOp)
	{
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = -1*_wtof(num);
		CString rez;
		rez.Format(L"%f", Num);
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
		GetDocument()->PushElement(currentStr, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = -1*_wtof(num);
		CString rez;
		rez.Format(L"%f", Num);
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
		//double Num 
		CString rez= Calculate(num,L"/",L"1");
		if (rez == "Деление на ноль невозможно")
		{
			MessageBox(L"Деление на ноль невозможно");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		//rez.Format(L"%f", Num);
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
		GetDocument()->PushElement(currentStr, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		//double Num = sqrt(_wtof(num));
		CString rez = Calculate(num, L"/", L"1");
		if (rez == "Деление на ноль невозможно")
		{
			MessageBox(L"Деление на ноль невозможно");
			CEngineeringCulculatorView::OnBnClickedBtnclear();
			return;
		}
		//rez.Format(L"%f", Num);
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
		double Num = sin(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
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
			enterStr.Append(L"###");
			for (int i = enterStr.GetLength() - 1; i >= indx + 3; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 3));
			enterStr.SetAt(indx, *"s");
			enterStr.SetAt(indx + 1, *"i");
			enterStr.SetAt(indx + 2, *"n");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"s");
			enterStr.SetAt(indx + 1, *"i");
			enterStr.SetAt(indx + 2, *"n");
			enterStr.SetAt(indx + 3, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		GetDocument()->PushElement(currentStr, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = sin(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"sin(" + num + ")");
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
		//double Num ;
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
		//rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
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
		GetDocument()->PushElement(currentStr, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		//double Num = Fact(_wtof(num));
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
		//rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);

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
		double Num = cos(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
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
			enterStr.Append(L"###");
			for (int i = enterStr.GetLength() - 1; i >= indx + 3; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 3));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"s");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"c");
			enterStr.SetAt(indx + 1, *"o");
			enterStr.SetAt(indx + 2, *"s");
			enterStr.SetAt(indx + 3, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		GetDocument()->PushElement(currentStr, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = cos(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"cos(" + num + ")");
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
		double Num = tan(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);
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
			enterStr.Append(L"###");
			for (int i = enterStr.GetLength() - 1; i >= indx + 3; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 3));
			enterStr.SetAt(indx, *"t");
			enterStr.SetAt(indx + 1, *"a");
			enterStr.SetAt(indx + 2, *"n");
			m_Edit.SetWindowTextW(enterStr);
		}
		else {
			enterStr.Append(L"####)");
			for (int i = enterStr.GetLength() - 2; i >= indx + 4; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 4));
			enterStr.SetAt(indx, *"t");
			enterStr.SetAt(indx + 1, *"a");
			enterStr.SetAt(indx + 2, *"n");
			enterStr.SetAt(indx + 3, *"(");
			m_Edit.SetWindowTextW(enterStr);
		}
	}
	else
	{
		GetDocument()->PushElement(currentStr, 1);
		action = 0;
		wasPushAnotherOp = 1;
		wasPushRightBracket = 0;

		CString num = GetDocument()->PopElement(GetDocument()->getNumElements() - 1)->getValue();
		double Num = tan(_wtof(num));
		CString rez;
		rez.Format(L"%f", Num);
		GetDocument()->PushElement(rez, 1);

		numberStr = rez;
		currentStr = rez;
		m_Number.SetWindowTextW(numberStr);

		enterStr.Append(L"tan(" + num + ")");
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
		GetDocument()->PushElement(currentStr, 1);
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
			//wasPushRightBracket = 0;
			GetDocument()->PushElement(currentStr, 1);
			enterStr.Append(numberStr);
		}
		wasPushRightBracket = 0;
		wasPushAnotherOp = 0;
		//enterStr.Append(numberStr);
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
		action = 5;
		if (prior <= 3)
		{
			enterStr.Append(L")#");
			for (int i = enterStr.GetLength() - 1; i > 0; i--)
				enterStr.SetAt(i, enterStr.GetAt(i - 1));
			enterStr.SetAt(0, *"(");
			enterStr.Append(L"^");
			//currentStr = enterStr;
			m_Edit.SetWindowTextW(enterStr);
		}
	}
}
