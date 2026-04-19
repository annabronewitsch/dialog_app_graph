#pragma once
#include "stdafx.h"
#include <vector>

class Idata
{
	
public:
	Idata();
	virtual ~Idata();
	virtual size_t IGetPoints(std::vector<CPoint>& vec) = 0;
};

