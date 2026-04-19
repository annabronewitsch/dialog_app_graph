#pragma once

struct X_Y_s
{
	double x, y;
};
class CCalculation
{
public:
	CCalculation();
	~CCalculation();
	X_Y_s GetY_X(double R, double f, double r);


};

