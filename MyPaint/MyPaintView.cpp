
// MyPaintView.cpp : implementation of the CMyPaintView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MyPaint.h"
#endif

#include "MyPaintDoc.h"
#include "MyPaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyPaintView

IMPLEMENT_DYNCREATE(CMyPaintView, CView)

BEGIN_MESSAGE_MAP(CMyPaintView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP ()
	ON_WM_MOUSEMOVE()

END_MESSAGE_MAP()

// CMyPaintView construction/destruction

//Default constructor
CMyPaintView::CMyPaintView() :
	m_FirstPoint (CPoint(0,0)), m_pTempShape (nullptr)
{
}

CMyPaintView::~CMyPaintView()
{
}

BOOL CMyPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

//Function creates a certain shape and returns a pointer to it
CShape * CMyPaintView::CreateElement() const
{
	CMyPaintDoc * pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	switch (pDoc->GetElementType())
	{
	case RECTANGLE:
		return new CRectangle(m_FirstPoint, m_SecondPoint,
			pDoc->GetElementColor(), pDoc->GetPenWidth());
	case ELLIPSE :
		return new CEllipse(m_FirstPoint, m_SecondPoint,
			pDoc->GetElementColor(), pDoc->GetPenWidth());
	case CURVE:
		return new CCurve(m_FirstPoint, m_SecondPoint,
			pDoc->GetElementColor(), pDoc->GetPenWidth());
	case LINE:
		return new CLine(m_FirstPoint, m_SecondPoint,
			pDoc->GetElementColor(), pDoc->GetPenWidth());

	}

}

// CMyPaintView drawing

//Left mouse button pressed
void CMyPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//Set initial point of drawing shape
	m_FirstPoint = point;
	//Receive all messages sent by mouse pointer
	SetCapture();

}
//Left mouse button released
void CMyPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	//Stop receiving messages 
	if (this == GetCapture())
		ReleaseCapture();

	//If pointer to temporary shape is not null then delete it
	if (m_pTempShape)
	{
		delete m_pTempShape;
		m_pTempShape = nullptr;
	}
}

//Mouse is moving 
void CMyPaintView::OnMouseMove(UINT nFlags, CPoint point)
{

	CClientDC aDC(this);
	// check if left mouse button is pressed
	// and mouse pointer within application window
	if (nFlags & MK_LBUTTON && this == GetCapture())
	{
		//Save position of cursor
		m_SecondPoint = point;
		if (m_pTempShape)
		{
			if (CURVE == GetDocument()->GetElementType())
			{
				//Add segment to curve
				static_cast <CCurve*> (m_pTempShape)->
					AddSegment(m_SecondPoint);
				//Draw shape
				m_pTempShape->Draw(&aDC);
				return;
			}
			//Redraw shape
			aDC.SetROP2(R2_NOTXORPEN);
			m_pTempShape->Draw(&aDC);
			delete m_pTempShape;
			m_pTempShape = nullptr;
			
		}
		//Create temporary shape and draw it 
		m_pTempShape = CreateElement();
		m_pTempShape->Draw(&aDC);

	}
}

void CMyPaintView::OnDraw(CDC* /*pDC*/)
{
	CMyPaintDoc* pDoc = GetDocument();
	
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
}


// CMyPaintView diagnostics

#ifdef _DEBUG
void CMyPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CMyPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyPaintDoc* CMyPaintView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyPaintDoc)));
	return (CMyPaintDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyPaintView message handlers



