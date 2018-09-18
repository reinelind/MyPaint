
// MyPaintDoc.cpp : implementation of the CMyPaintDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MyPaint.h"
#endif

#include "MyPaintDoc.h"
#include "resource.h"
#include "MyPaintConstants.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyPaintDoc

IMPLEMENT_DYNCREATE(CMyPaintDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyPaintDoc, CDocument)
	ON_COMMAND(ID_COLOR_RED, &CMyPaintDoc::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CMyPaintDoc::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CMyPaintDoc::OnColorBlue)
	ON_COMMAND(ID_COLOR_BLACK, &CMyPaintDoc::OnColorBlack)
	ON_COMMAND(ID_SHAPE_LINE, &CMyPaintDoc::OnShapeLine)
	ON_COMMAND(ID_SHAPE_CURVE, &CMyPaintDoc::OnShapeCurve)
	ON_COMMAND(ID_SHAPE_RECTANGLE, &CMyPaintDoc::OnShapeRectangle)
	ON_COMMAND(ID_SHAPE_ELLIPSE, &CMyPaintDoc::OnShapeEllipse)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_LINE, &CMyPaintDoc::OnUpdateShapeLine)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_CURVE, &CMyPaintDoc::OnUpdateShapeCurve)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_RECTANGLE, &CMyPaintDoc::OnUpdateShapeRectangle)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_ELLIPSE, &CMyPaintDoc::OnUpdateShapeEllipse)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CMyPaintDoc::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CMyPaintDoc::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CMyPaintDoc::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, &CMyPaintDoc::OnUpdateColorBlack)
	ON_COMMAND(ID_PENWIDTH_1, &CMyPaintDoc::OnPenwidth1)
	ON_COMMAND(ID_PENWIDTH_2, &CMyPaintDoc::OnPenwidth2)
	ON_COMMAND(ID_PENWIDTH_4, &CMyPaintDoc::OnPenwidth4)
	ON_COMMAND(ID_PENWIDTH_8, &CMyPaintDoc::OnPenwidth8)
	ON_UPDATE_COMMAND_UI(ID_PENWIDTH_2, &CMyPaintDoc::OnUpdatePenwidth2)
	ON_UPDATE_COMMAND_UI(ID_PENWIDTH_1, &CMyPaintDoc::OnUpdatePenwidth1)
	ON_UPDATE_COMMAND_UI(ID_PENWIDTH_4, &CMyPaintDoc::OnUpdatePenwidth4)
	ON_UPDATE_COMMAND_UI(ID_PENWIDTH_8, &CMyPaintDoc::OnUpdatePenwidth8)
	ON_COMMAND(ID_COLOR_WHITE, &CMyPaintDoc::OnColorWhite)
	ON_UPDATE_COMMAND_UI(ID_COLOR_WHITE, &CMyPaintDoc::OnUpdateColorWhite)

END_MESSAGE_MAP()


// CMyPaintDoc construction/destruction


CMyPaintDoc::CMyPaintDoc() :m_Shape(LINE), m_Color(BLACK), m_PenWidth (1)
{
	

}

CMyPaintDoc::~CMyPaintDoc()
{
}

BOOL CMyPaintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}




// CMyPaintDoc serialization

void CMyPaintDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		
	}
	else
	{
		
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMyPaintDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMyPaintDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMyPaintDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMyPaintDoc diagnostics

#ifdef _DEBUG
void CMyPaintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyPaintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyPaintDoc commands

// Set red color
void CMyPaintDoc::OnColorRed()
{
	m_Color = RED; 
}

// Set green color
void CMyPaintDoc::OnColorGreen()
{
	m_Color = GREEN; 
}

// Set blue color
void CMyPaintDoc::OnColorBlue()
{
	m_Color = BLUE; 
}

// Set black color
void CMyPaintDoc::OnColorBlack()
{
	m_Color = BLACK; 
}
// Set white color 
void CMyPaintDoc::OnColorWhite()
{
	m_Color = WHITE;
}

// Select line for drawing
void CMyPaintDoc::OnShapeLine()
{
	m_Shape = LINE; 
}

// Select curve for drawing
void CMyPaintDoc::OnShapeCurve()
{
	m_Shape = CURVE;
}
// Select rectangle for drawing
void CMyPaintDoc::OnShapeRectangle()
{
	m_Shape = RECTANGLE;
}
// Select ellipse for drawing 
void CMyPaintDoc::OnShapeEllipse()
{
	m_Shape = ELLIPSE;
}
// Set pen width to 1
void CMyPaintDoc::OnPenwidth1()
{
	m_PenWidth = 1;
}

// Set pen width to 2
void CMyPaintDoc::OnPenwidth2()
{
	m_PenWidth = 2;
}

// Set pen width to 4
void CMyPaintDoc::OnPenwidth4()
{
	m_PenWidth = 4;
}

// Set pen width to 8
void CMyPaintDoc::OnPenwidth8()
{
	m_PenWidth = 8;
}

//Next functions are responsible for 
//showing which menu items are selected

void CMyPaintDoc::OnUpdateShapeLine(CCmdUI *pCmdUI)
{
	
	pCmdUI->SetCheck(m_Shape == LINE);

}


void CMyPaintDoc::OnUpdateShapeCurve(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Shape == CURVE);
}


void CMyPaintDoc::OnUpdateShapeRectangle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Shape == RECTANGLE);
}


void CMyPaintDoc::OnUpdateShapeEllipse(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Shape == ELLIPSE);
}


void CMyPaintDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Color == RED);

}


void CMyPaintDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Color == GREEN);

}


void CMyPaintDoc::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Color == BLUE);

}


void CMyPaintDoc::OnUpdateColorBlack(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Color == BLACK);

}

void CMyPaintDoc::OnUpdateColorWhite(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Color == WHITE);
}


void CMyPaintDoc::OnUpdatePenwidth1(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_PenWidth == 1);

}

void CMyPaintDoc::OnUpdatePenwidth2(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_PenWidth == 2);
}


void CMyPaintDoc::OnUpdatePenwidth4(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_PenWidth == 4);
}


void CMyPaintDoc::OnUpdatePenwidth8(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_PenWidth == 8);
}



