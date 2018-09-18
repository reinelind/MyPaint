#pragma once
#include "Shape.h"
class CRectangle :
	public CShape
{
public:
	
	//CRectangle constructor
	CRectangle(const CPoint & start, const CPoint &end
		, COLORREF aColor, int penWidth);
	//Forbid use of default constuctor
	CRectangle() = delete;
	//Drawing function
	virtual void Draw(CDC * pDC);

};

