// Shape.cpp
//

#include "stdafx.h"
#include "MyPaint.h"
#include "Shape.h"


// CShape

CShape::CShape()
{
}

CShape::~CShape()
{
}

//Receive bounding rect
CRect CShape::GetBoundRect() const
{
	CRect boundingRect(m_EnclosingRect);
	return boundingRect;
}



