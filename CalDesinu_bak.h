#if !defined(AFX_CALDESINU_H__631B43DC_59D6_4E9D_AA00_0970C398E3A7__INCLUDED_)
#define AFX_CALDESINU_H__631B43DC_59D6_4E9D_AA00_0970C398E3A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CalDesinu.h : header file
//

#include "vfw.h"

/////////////////////////////////////////////////////////////////////////////
// CCalDesinu dialog

class CCalDesinu : public CDialog
{
private:
	HDC      m_hdc;
	int      m_frames;
	int      m_width;
	int      m_height;
	int      m_nFrameIdx;
	int      m_SliderStartPos;
	int      m_SliderEndPos;

	// these variables are from the hardware system
	double   m_nGridSize;
	int      m_nGridNumb;
	long     m_nFreqHorz;
	int      m_nFreqVert;

	// these variables are used to determine control size/position on GUI
	int      m_info_height;
	int      m_curve_height;
	int      m_margin_edgeH;
	int      m_margin_edgeV;
	int      m_margin_middle;
	int      m_button_height;
	int      m_button_width;
	int      m_img_pix_bnd;
	
	BYTE    *m_dispBufferRaw;		// image buffer for display, raw video
	BYTE    *m_dispBufferDew;		// image buffer for display, dewarped video
	int     *m_UnMatrixIdx;
	float   *m_UnMatrixVal;
	BOOL     m_bHasLUT;

	int     *m_AveGridX;			// this vector stores the pixel summation in horizontal direction
	int     *m_AveGridY;			// this vector stores the pixel summation in vertical direction
	POINT   *m_DispGridX0;			// this vector display pixel variation in horizontal direction
	POINT   *m_DispGridY0;			// this vector display pixel variation in vertical direction
	POINT   *m_DispGridX1;			// this vector display pixel variation in horizontal direction
	POINT   *m_DispGridY1;			// this vector display pixel variation in vertical direction

	POINT   *m_localMinX;			// to save local minimum points on curve X
	POINT   *m_localMinY;			// to save local minimum points on curve Y
	int      m_localPtsX;
	int      m_localPtsY;

	CPen    m_penBlue;
	CPen    m_penRed;
	CPen    m_penBkColor;
	CPen   *m_pPenOld;

	LPBITMAPINFO  m_BitmapInfo;
	PAVISTREAM    m_pStream;

// Construction
public:
	BOOL         VerifyInputs();
	BOOL         BuildLUT(int *Index, float *Value);
	BOOL         UnwarpImage();
	LPBITMAPINFO CreateDIB(int cx, int cy);
	PAVISTREAM   GetAviStream(CString aviFileName, int *Frames, int *Width, int *Height, int *FirstFrame);
	BOOL         LoadVideo(PAVISTREAM pStream, int fIdxStart, int fIdxEnd);
	BOOL         LoadVideo(PAVISTREAM pStream, int frameIdx);
	BOOL         SetupWindowSize(int fWidth, int fHeight);
	BOOL         CalcXandY();
	void         DrawCurves(CPaintDC *pDC);
	void         RefreshFigures(BOOL f11, BOOL f12, BOOL f21, BOOL f22);
	void         DrawCross(CPaintDC *pDC, POINT localMin, CPen *pen);

	char         m_LUTfname[120];

	CCalDesinu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCalDesinu)
	enum { IDD = IDD_DLG_DESINUSOID };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalDesinu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCalDesinu)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CSliderCtrl* pScrollBar);
	afx_msg void OnLoadGrids();
	afx_msg void OnStartFrame();
	afx_msg void OnEndFrame();
	afx_msg void OnRunDesinu();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSaveLut();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALDESINU_H__631B43DC_59D6_4E9D_AA00_0970C398E3A7__INCLUDED_)
