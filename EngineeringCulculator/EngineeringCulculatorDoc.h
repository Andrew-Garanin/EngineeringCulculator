
// EngineeringCulculatorDoc.h: интерфейс класса CEngineeringCulculatorDoc 
//


#pragma once
//Класс, описывающий память калькулятора
class Memory : public CObject
{
public:
	virtual void Serialize(CArchive& ar);
	double value;
	Memory()
	{
		value = 0;
	}
	DECLARE_SERIAL(Memory)
	
	void memoryClear()
	{
		value = 0;
	}
	void memoryPlus(double val)
	{
		value+= val;
	}
	void memoryMinus(double val)
	{
		value -= val;
	}
	double memoryRead()
	{
		return value;
	}
	void memorySave(double val)
	{
		value = val;
	}
};

//Класс, описывающий элемент, который кладется в главный стек
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
public:

	CTypedPtrArray <CObArray, Element*> stack;//главный стек для чисел, операций, скобок и т.д.
	Memory* memory = new Memory();//единственный объект типа Memory, являющийся памятью калькулятора

protected: // создать только из сериализации
	CEngineeringCulculatorDoc() noexcept;
	DECLARE_DYNCREATE(CEngineeringCulculatorDoc)

// Атрибуты
public:

// Операции
public:
	void PushElement(CString Val, int WhatThis);//Положить элемент на стек
	Element *PopElement(int index);//Снять элемент со стека
	int getNumElements();//Размер стека
	int getCountOfNumbers();//Количество чисел до открывающей скобки
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
