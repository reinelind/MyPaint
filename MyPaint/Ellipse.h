#pragma once
#include "Shape.h"

class CEllipse :
	public CShape
{
public:
	//CEllipse constructor
	CEllipse(const CPoint& start, const CPoint& end, COLORREF aColor, int penWidth);
	//Forbid use of default constructor 
	CEllipse() = delete;
	//Drawing function
	virtual void Draw(CDC *pDC);

	
};



