#pragma once

#include "Idata.h"
// CArtist

class CArtist : public CStatic
{
	DECLARE_DYNAMIC(CArtist)

public:
	CArtist();
	virtual ~CArtist();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		void SetBkColor(COLORREF color);
	void OnPaint();
	void SetIdataPtr(Idata* pData) { m_Idata = pData;}
protected:
	Idata *m_Idata = nullptr;
	COLORREF m_bkCol = RGB(66, 49, 137);
};

 
