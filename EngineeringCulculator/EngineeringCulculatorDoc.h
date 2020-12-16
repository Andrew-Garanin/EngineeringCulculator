
// EngineeringCulculatorDoc.h: интерфейс класса CEngineeringCulculatorDoc 
//


#pragma once
class Element : public CObject
{
protected:
	CString value;
	int whatThis;
public:
	Element(CString Val, int WhatThis)
	{
		value = Val;
		whatThis = WhatThis;
	}
	CString getValue()
	{
		return this->value;
	}
	int getWhatThis()
	{
		return this->whatThis;
	}
};

class CEngineeringCulculatorDoc : public CDocument
{
protected:
	CTypedPtrArray <CObArray, Element*> stack;
public:
	void PushElement(CString Val, int WhatThis);
	Element *PopElement(int index);
	int getNumElements();

protected: // создать только из сериализации
	CEngineeringCulculatorDoc() noexcept;
	DECLARE_DYNCREATE(CEngineeringCulculatorDoc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CEngineeringCulculatorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
