#pragma once
#include "Shape.h"
#include <vector>
class CCurve :
	public CShape
{
public:
	
	//CCurve constructor
	CCurve(const CPoint & first, const CPoint & second, COLORREF aColor, int penWidth);
	//Forbid use of default constructor
	CCurve() = delete;
	//Add segment to curve
	void AddSegment(const CPoint& point);
	//Draw curve
	virtual void Draw(CDC * pDC);

	
protected:
	std::vector <CPoint> m_Points; // points of curve
	
};

