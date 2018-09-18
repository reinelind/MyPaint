#include "stdafx.h"
#include "Line.h"

// Constructor of CLine
CLine::CLine(const CPoint& start, const CPoint& end, COLORREF aColor, int penWidth):
	m_StartPoint (start), m_EndPoint(end)
{
	// Set a pen width
	m_PenWidth = penWidth;
	// Set color of line
	m_Color = aColor;

	// Set an eclosing rectangle for line
	m_EnclosingRect = CRect(start, end);
	m_EnclosingRect.NormalizeRect();
}
// Line drawing function
void CLine::Draw(CDC* pDC)
{
	//Create a pen and check if the pen can be initialized 
	CPen aPen;
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		AfxMessageBox(_T("Failed to create a pen"), MB_OK);
		AfxAbort();
	}
	//Select the created pen
	CPen* pOldPen = pDC->SelectObject(&aPen);
	//Set start point of line
	pDC->MoveTo(m_StartPoint);
	//Draw line to end point of line
	pDC->LineTo(m_EndPoint);	
}
