#pragma once
#include "Shape.h"

class CLine :
	public CShape
{
public:
	
	// CLine constructor
	CLine(const CPoint &start, const CPoint& end, COLORREF aColor, int penWidth);
	// forbid use of default constructor
	CLine() = delete;
	//Line draw function
	virtual void Draw(CDC * pDC);
protected:

	CPoint m_StartPoint; //start point of line
	CPoint m_EndPoint; //end point of line
	
};

