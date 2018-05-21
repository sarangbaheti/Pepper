#pragma once
#include "PepperTreeCtrl.h"
#include "PepperList.h"

class CViewRightTop : public CScrollView
{
public:
	virtual void OnDraw(CDC* pDC); // overridden to draw this view
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	DECLARE_DYNCREATE(CViewRightTop)
protected:
	CViewRightTop() {}; // protected constructor used by dynamic creation
	virtual ~CViewRightTop() {};
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	afx_msg void OnListSectionsGetDispInfo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnListImportGetDispInfo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnListRelocGetDispInfo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnListExceptionGetDispInfo(NMHDR *pNMHDR, LRESULT *pResult);
	DECLARE_MESSAGE_MAP()
private:
	SIZE m_sizeLineDistance { };
	CFont m_fontSummary;
	std::wstring m_strFileName { };
	std::wstring m_strFileType { };
	Ilibpe * m_pLibpe { };
	CChildFrame* m_ChildFrame { };
	CPepperDoc* m_pMainDoc { };
	CPepperList m_listDOSHeader;
	CPepperList m_listDOSRich;
	CPepperList m_listNTHeader;
	CPepperList m_listFileHeader;
	CPepperList m_listOptHeader;
	CPepperList m_listDataDirs;
	CPepperList m_listSecHeaders;
	CPepperList m_listExportDir;
	CPepperList m_listImportDir;
	CPepperList m_listExceptionDir;
	CPepperList m_listSecurityDir;
	CPepperList m_listRelocDir;
	CPepperList m_listDebugDir;
	CPepperList m_listLoadConfigDir;
	CPepperList m_listBoundImportDir;
	CPepperList m_listDelayImportDir;
	CPepperList m_listTLSDir;
	CPepperTreeCtrl m_treeResourceDirTop;
	bool m_fFileSummaryShow = false;
	LONG m_dwPeStart { };
	DWORD m_dwFileSummary { };
	LONG m_ScrollWidth { };
	LONG m_ScrollHeight { };
	std::map<DWORD, std::wstring> m_mapSecFlags { };
	PLIBPE_SECHEADER m_pSectianHeaders { };
	PLIBPE_IMPORT m_pImportTable { };
	PLIBPE_EXCEPTION m_pExceptionDir { };
	PLIBPE_RELOCATION m_pRelocTable { };
	CWnd* m_pActiveList { };

	int listCreateDOSHeader();
	int listCreateDOSRich();
	int listCreateNTHeader();
	int listCreateFileHeader();
	int listCreateOptHeader();
	int listCreateDataDirs();
	int listCreateSections();
	int listCreateExportDir();
	int listCreateImportDir();
	int treeCreateResourceDir();
	int listCreateExceptionDir();
	int listCreateSecurityDir();
	int listCreateRelocDir();
	int listCreateDebugDir();
	int listCreateLoadConfigDir();
	int listCreateBoundImportDir();
	int listCreateDelayImportDir();
	int listCreateTLSDir();
};