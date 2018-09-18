#include "stdafx.h"
#include "Curve.h"

// Curve drawing function 
void CCurve::Draw(CDC * pDC)
{
	//Create a pen and check if the pen can be initialized 
	CPen aPen;
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		AfxMessageBox(_T("Failed to create a pen"), MB_OK);
		AfxAbort();
	}
	//Select the created pen
	CPen *pOldPen = pDC->SelectObject(&aPen);

	//Draw segments of curve
	pDC->MoveTo(m_Points[0]);
	for (size_t i = 1; i < m_Points.size(); ++i)
		pDC->LineTo(m_Points[i]);
	
}
//CCurve constructor
CCurve::CCurve(const CPoint & first, const CPoint & second, COLORREF aColor, int penWidth)
{
	//Save initial points
	m_Points.push_back(first);
	m_Points.push_back(second);
	//Set color 
	m_Color = aColor;
	//Set enclosing rectangle
	m_EnclosingRect = CRect(min(first.x, second.x),
		min(first.y, second.y),
		max(first.x, second.x),
		max(first.y, second.y));
	//Set pen width
	m_PenWidth = penWidth;
}
//Add segment of curve
void CCurve::AddSegment(const CPoint & point)
{
	//Save current point
	m_Points.push_back(point);
	//Set enclosing rectangle for segment of curve
	m_EnclosingRect = CRect(min(point.x, m_EnclosingRect.left),
		min(point.y, m_EnclosingRect.top),
		max(point.x, m_EnclosingRect.right),
		max(point.y, m_EnclosingRect.bottom));

}


