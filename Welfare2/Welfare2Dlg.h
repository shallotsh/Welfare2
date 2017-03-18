
// Welfare2Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Location2CodeEncode.h"


// CWelfare2Dlg 对话框
class CWelfare2Dlg : public CDialogEx
{
// 构造
public:
	CWelfare2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WELFARE2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 自定义变量
	Location2CodeEncode *location;

	CEdit m_dataBoldA;
	CEdit m_dataBoldB;
	CEdit m_dataCodeA;
	CEdit m_dataCodeB;
	CEdit m_dataIssue;
	CButton m_handleGenA;
	CButton m_handleGenB;
	CButton m_handleKillA;
	CButton m_handleKillB;
	CButton m_handlePrint;
	CButton m_handleReset;
	CButton m_handleSaveA;
	CButton m_handleSaveB;
	CRichEditCtrl m_output;
//	CListBox m_listCode;
//	CListCtrl m_listTitle;
	afx_msg void OnClickedHandleGenA();
	CListBox m_listCode;
	CListCtrl m_listTitle;
	afx_msg void OnBnClickedHandleKillA();
	afx_msg void OnBnClickedHandleSaveA();
	afx_msg void OnBnClickedHandleGenB();
	afx_msg void OnBnClickedHandleKillB();
	afx_msg void OnBnClickedHandleSaveB();
	afx_msg void OnBnClickedHandlePrint();
	afx_msg void OnBnClickedHandleReset();
	afx_msg void OnNMClickListTitle(NMHDR *pNMHDR, LRESULT *pResult);

	virtual void OnOK();

	CButton m_handleResetAll;
	afx_msg void OnBnClickedHandleResetAll();
	CStatic m_outputTitle;
	// 十位
	CEdit m_dataCodeA2;
	CEdit m_dataCodeB2;
};
