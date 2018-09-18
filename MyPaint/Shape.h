#pragma once


class CShape : public CObject
{
public:
	//Shape drawing function
	virtual void Draw(CDC *pDC) {}
	virtual ~CShape();
	//Get bounding rect of shape
	CRect GetBoundRect() const;
	
protected:
	CRect m_EnclosingRect;
	int m_PenWidth; //Width pen
	COLORREF m_Color; //Boundaries color of shape
	CShape(); //Forbid use of default constructor

};


