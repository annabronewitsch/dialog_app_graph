#include "stdafx.h"
#include "Trans.h"
#define _USE_MATH_DEFINES
#include <math.h>


// Инициализировать члены класса CTrans значениями по умолчанию
CTrans::CTrans()
	: m_Scale(0)
	, m_center(0, 0)
{
}

// Деструктор класса CTrans

CTrans::~CTrans()
{
}

// Функция для установки параметров преобразования
void CTrans::SetTransParam(int Xwidth, int Yheight)
{
	double scX, scY; // Создать переменные для хранения масштабов

	// Вычислить масштаб по оси X
	scX = (double)(Xwidth - 2 * BORDER_W) / (2. * M_PI);

	// Вычислить масштаб по оси Y
	scY = (double)(Yheight - 2 * BORDER_W) / 2.;

	// Установить координаты центра
	m_center.x = Xwidth / 2;
	m_center.y = Yheight / 2;

	// Установить масштаб как минимальное значение из scX и scY
	m_Scale = min(scX, scY);
}

// Функция для получения преобразованной точки
CPoint CTrans::GetPoint(double R, double f, double r)
{
	CPoint Cur = Trans(R, f, r); // Получить преобразованные координаты
	Cur.Offset(m_center.x, m_center.y); // Сдвинуть точку относительно центра
	return Cur; // Вернуть преобразованную точку
}

// Функция для преобразования координат
CPoint CTrans::Trans(double R, double f, double r)
{
	X_Y_s a = GetY_X(R, f, r); // Получить координаты точки
	 
	// Применить масштаб
	return CPoint(
		floor(a.x * m_Scale * m_ScaleMul + 0.5),
		-floor(a.y * m_Scale * m_ScaleMul + 0.5)
	);
}


void CTrans::SetScale(int nMul)
{
	switch (nMul)

	{
	case 0: m_ScaleMul = 1.; break;
	case 1: m_ScaleMul = 2.; break;
	case 2: m_ScaleMul = 4.; break;
	case -1: m_ScaleMul = .5; break;
	case -2: m_ScaleMul = .25; break;



	}
}