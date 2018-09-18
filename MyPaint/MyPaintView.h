
// MyPaintView.h : interface of the CMyPaintView class
//

#pragma once

#include "Shape.h"
#include "Curve.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
class CMyPaintView : public CView
{
protected: // create from serialization only
	CMyPaintView();
	DECLARE_DYNCREATE(CMyPaintView)

// Attributes
public:
	CMyPaintDoc* GetDocument() const;

// Operations
public:
	// Mouse left button is down
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	// Mouse left button is released
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	// Mouse is moving
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	CShape * m_pTempShape ; //Temporary shape
	CPoint m_SecondPoint; 
	CShape * CreateElement() const; 
	

// Implementation
public:
	virtual ~CMyPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint m_FirstPoint;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

#ifndef _DEBUG  // debug version in MyPaintView.cpp
inline CMyPaintDoc* CMyPaintView::GetDocument() const
   { return reinterpret_cast<CMyPaintDoc*>(m_pDocument); }
#endif

