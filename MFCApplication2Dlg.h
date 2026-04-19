
// MFCApplication2Dlg.h : файл заголовка
//

#pragma once
#include "Artist.h"
#include "afxwin.h"
#include "Trans.h"
#include "Idata.h"
#include <vector>
#include "Resource.h"
#include <afxcmn.h>



// диалоговое окно CMFCApplication2Dlg
class CMFCApplication2Dlg : public CDialogEx
	,Idata
{
// Создание
public:
	CMFCApplication2Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV




// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	CArtist m_artist;

	afx_msg void OnEnChangeEditA();
	size_t GetPoints(std::vector<CPoint> & vecPt);
	double m_R;
	double m_r;
	double m_f;
protected:
	CTrans m_Trans;
	std::vector<CPoint> m_vecPt;
	CEdit m_EditA;
	CEdit m_Edit2;
	CEdit m_Edit3;
protected:
	bool Calc();
	bool bCreated = false;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual size_t IGetPoints(std::vector<CPoint>& vec);
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBtnAnime();
	afx_msg void OnBnClickedCancel();
	double m_rotationAngle = 0.0;
	afx_msg void OnCbnSelchangeComboCol();
	afx_msg void OnBnClickedButton1();
	CSliderCtrl m_SliderSc;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	void UpdateHintText();
	CStatic m_StaticScale;
	CButton m_btnSave;
	CButton m_btnClear;
	CButton m_btnOK;
	CButton m_btnCancel;
	CStatic m_StaticHint;

	afx_msg void OnBnClickedBtnInsertF();
	double m_autoF = 0.0; // для хранения рассчитанного f

};
