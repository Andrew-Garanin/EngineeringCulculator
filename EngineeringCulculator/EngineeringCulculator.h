
// EngineeringCulculator.h: основной файл заголовка для приложения EngineeringCulculator
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CEngineeringCulculatorApp:
// Сведения о реализации этого класса: EngineeringCulculator.cpp
//

class CEngineeringCulculatorApp : public CWinApp
{
public:
	CEngineeringCulculatorApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEngineeringCulculatorApp theApp;
