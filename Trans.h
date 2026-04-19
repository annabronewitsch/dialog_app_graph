#pragma once
#include "Calculation.h"
#include "atltypes.h"
class CTrans :
	public CCalculation
{
public:
	CTrans();
	~CTrans();
	void SetTransParam(int Xwidth, int Yheight);
	CPoint GetPoint(double R, double f, double r);

public:
	void SetScale(int nMul);
	double GetScale() { return m_ScaleMul; }
	
	CPoint Trans(double R, double f, double r);

protected:

	double m_ScaleMul = 1.;
	double m_Scale;
	CPoint m_center;

};
