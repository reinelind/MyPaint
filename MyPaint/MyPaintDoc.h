
// MyPaintDoc.h : interface of the CMyPaintDoc class
//


#pragma once
#include "MyPaintConstants.h"

class CMyPaintDoc : public CDocument
{


protected: // create from serialization only
	CMyPaintDoc();
	DECLARE_DYNCREATE(CMyPaintDoc)

// Attributes
public:

// Operations
public:
	unsigned int GetElementType()
	{
		return m_Shape;
	}
	COLORREF GetElementColor()
	{
		return m_Color;
	}
	int GetPenWidth()
	{
		return m_PenWidth;
	}
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMyPaintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnColorRed(); 
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
	afx_msg void OnColorBlack();
	afx_msg void OnShapeLine();
	afx_msg void OnShapeCurve();
	afx_msg void OnShapeRectangle();
	afx_msg void OnShapeEllipse();
protected:
	ShapeType m_Shape; // Current shape
	COLORREF m_Color; // Current color
	int m_PenWidth; // Current pen width

public:
	afx_msg void OnUpdateShapeLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeCurve(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeRectangle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeEllipse(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorBlack(CCmdUI *pCmdUI);
	afx_msg void OnPenwidth1();
	afx_msg void OnPenwidth2();
	afx_msg void OnPenwidth4();
	afx_msg void OnPenwidth8();
	afx_msg void OnUpdatePenwidth2(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenwidth1(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenwidth4(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenwidth8(CCmdUI *pCmdUI);
	afx_msg void OnColorWhite();
	afx_msg void OnUpdateColorWhite(CCmdUI *pCmdUI);

};
