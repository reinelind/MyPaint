#include "stdafx.h"
#include "Ellipse.h"
#include <cmath>

// CEllipse constructor
CEllipse::CEllipse(const CPoint & start, const CPoint & end, COLORREF aColor, int penWidth)
{
	// Define enclosing rectangle for ellipse
	m_EnclosingRect = CRect(start.x, start.y, end.x, end.y);
	m_EnclosingRect.NormalizeRect();
	
	// Set color of ellipse bounding
	m_Color = aColor;
	// Set pen
	m_PenWidth = penWidth;
}
// Ellipse's drawing function
void CEllipse::Draw(CDC * pDC)
{
	//Create a pen and check if the pen can be initialized 
	CPen aPen;
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
	{
		AfxMessageBox(_T("Failed to create a pen"), MB_OK);
		AfxAbort();
	}
	//Select the created pen
	CPen * pOldPen = pDC->SelectObject(&aPen);
	//Select a brush
	CBrush * pOldBrush = static_cast <CBrush*> (pDC->SelectStockObject(NULL_BRUSH));

	//Draw an ellipse 
	pDC->Ellipse(m_EnclosingRect);

	
}
