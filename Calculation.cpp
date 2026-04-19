
#include "stdafx.h"
#include "Calculation.h"


CCalculation::CCalculation() // выделение переменной CCalculation из класса CCalculation
{
}


CCalculation::~CCalculation() // деструктор переменной CCalculation из класса CCalculation
{
}


// функция для вычисления координат точки по заданным параметрам

X_Y_s CCalculation::GetY_X(double R, double f, double r)
{
	X_Y_s a; // Создать структуру для хранения координат

	// Вычислить коэффициент k как отношение R к r
	double k = R / r;

	// Вычислить координату Y по формуле
	a.y = r * (k - 1) * (sin(f) - sin((k - 1) * f) / (k - 1));

	// Вычислить координату X по формуле
	a.x = r * (k - 1) * (cos(f) + cos((k - 1) * f) / (k - 1));

	return a; // Вернуть структуру с вычисленными координатами
}

