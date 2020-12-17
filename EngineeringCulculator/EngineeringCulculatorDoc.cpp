
// EngineeringCulculatorDoc.cpp: реализация класса CEngineeringCulculatorDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "EngineeringCulculator.h"
#endif

#include "EngineeringCulculatorDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CEngineeringCulculatorDoc

IMPLEMENT_DYNCREATE(CEngineeringCulculatorDoc, CDocument)

BEGIN_MESSAGE_MAP(CEngineeringCulculatorDoc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CEngineeringCulculatorDoc

CEngineeringCulculatorDoc::CEngineeringCulculatorDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CEngineeringCulculatorDoc::~CEngineeringCulculatorDoc()
{
}

BOOL CEngineeringCulculatorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CEngineeringCulculatorDoc

void CEngineeringCulculatorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CEngineeringCulculatorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CEngineeringCulculatorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CEngineeringCulculatorDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CEngineeringCulculatorDoc

#ifdef _DEBUG
void CEngineeringCulculatorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEngineeringCulculatorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CEngineeringCulculatorDoc
void CEngineeringCulculatorDoc::PushElement(CString Val, int WhatThis)
{
	Element* el = new Element(Val, WhatThis);
	stack.Add(el);
}

Element* CEngineeringCulculatorDoc::PopElement(int index)
{
	if (index < 0 || index > stack.GetUpperBound())
		return 0;
	else
	{
		Element* el = stack.GetAt(index);
		stack.RemoveAt(index);
		return el;
	}
}

int CEngineeringCulculatorDoc::getNumElements()
{
	return stack.GetSize();
}

int CEngineeringCulculatorDoc::getCountOfNumbers()
{
	int size=stack.GetSize();
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (stack.GetAt(i)->getWhatThis() == 1)
			count++;
	}
	return count;
}
