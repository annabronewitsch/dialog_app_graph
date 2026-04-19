#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "Artist.h"

#define BORDER_W 3 // Ширина границы для рисования осей

// CArtist

IMPLEMENT_DYNAMIC(CArtist, CStatic)
//макрос, который предоставляет информацию о типе времени 
//выполнения для поддержки таких макросов, как isKindOf и GetRuntimeClass.

CArtist::CArtist() // выделение переменной Artist из класса Artist
{
}

CArtist::~CArtist()
{
	// Деструктор переменной Artist из класса Artist (освобождение памяти)
}

BEGIN_MESSAGE_MAP(CArtist, CStatic) // Регистрация обработчиков сообщений
	ON_WM_PAINT() // Обработчик сообщения WM_PAINT
END_MESSAGE_MAP()

void CArtist::SetBkColor(COLORREF color) // Установка цвета фона
{
	m_bkCol = color; // Сохранить цвет фона
	Invalidate(); // Перерисовать окно
}

void CArtist::OnPaint() // определение функции OnPaint класса Artist
{
	TRACE("OnPaint работает\n"); // Отладка: вывод сообщения в трассировку
	CPaintDC dc(this); // Создание контекста устройства для рисования

	CRect rc; // Прямоугольник для хранения размеров клиентской области
	GetClientRect(&rc); // Получить размеры клиентской области окна

	dc.FillSolidRect(&rc, m_bkCol); // Заполнить прямоугольник цветом фона

	CRgn rgn; // Создать регион для обрезки
	rgn.CreateRectRgnIndirect(&rc);
	dc.SelectClipRgn(&rgn); // Установить регион обрезки

	CPen penO; // Объявить ручку для рисования осей координат
	COLORREF col0 = RGB(75, 23, 183); // Определить цвет по цветовой модели RGB

	HGDIOBJ pold = dc.SelectObject(penO); // Сохранить текущую ручку

	penO.CreatePen(PS_SOLID, 1, col0); // Создать ручку с заданными параметрами
	dc.SelectObject(penO); // Выбрать созданную ручку

	//далее: рисуем координатные оси
	dc.MoveTo(rc.left + BORDER_W, rc.CenterPoint().y); //команда: переместить ручку в (почти) начало оси х и центр оси у
	dc.LineTo(rc.right - BORDER_W, rc.CenterPoint().y); //... и нарисовать линию из этой точки до точки: (почти) конец оси х и центр оси у
	dc.MoveTo(rc.CenterPoint().x, rc.top + BORDER_W); // переместить ручку в (почти) начало оси y и центр оси x
	dc.LineTo(rc.CenterPoint().x, rc.bottom + BORDER_W); //... и нарисовать линию из этой точки до точки : (почти) конец оси y и центр оси x

	if (m_Idata) // Если есть данные для отрисовки
	{
		CPen penG; // Создать новый объект типа "ручка"
		COLORREF colG = RGB(248, 243, 43); // Определить цвет графика
		penG.CreatePen(PS_SOLID, 2, colG); // свойства линии, к-рую будет рисовать созданная ручка 
		dc.SelectObject(penG); // Выбрать созданную ручку
		std::vector<CPoint> vecP; // Создать вектор для хранения точек
		//size_t sz = pMain->GetPoints(vecP); //varB
		size_t sz = m_Idata->IGetPoints(vecP); //var A - с помощью интерфейса получить точки
		if (sz) // Если точки получены
		{
			dc.MoveTo(vecP[0]); // Переместить ручку в первую точку
			for (auto Pt : vecP) // Пройти по всем точкам
			{
				dc.LineTo(Pt); // Нарисовать линию к следующей точке
			}
		}
	}
	dc.SelectObject(pold); // Восстановить предыдущую ручку
}

 