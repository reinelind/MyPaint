#include "stdafx.h"
#include "Rectangle.h"


// CRectangle constructor
CRectangle::CRectangle(const CPoint & start, const CPoint & end, COLORREF aColor, int penWidth)
{
	//Set color
	m_Color = aColor;
	//Set pen width
	m_PenWidth = penWidth;
	
	//Set enclosing rectangle
	m_EnclosingRect = CRect(start, end);
	m_EnclosingRect.NormalizeRect();
}
// Rectangle drawing function
void CRectangle::Draw(CDC * pDC)
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
	//Select a brush
	CBrush * pOldBrush = static_cast <CBrush*>(pDC->SelectStockObject(NULL_BRUSH));
	//Draw a rectangle
	pDC->Rectangle(m_EnclosingRect);

}
