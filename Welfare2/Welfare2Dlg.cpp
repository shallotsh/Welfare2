
// Welfare2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Welfare2.h"
#include "Welfare2Dlg.h"
#include "afxdialogex.h"

#include "CApplication.h"
#include "CMyDocument.h"
#include "CDocuments.h"
#include "CMyFont.h"
#include "CRange.h"
#include "CSelection.h"
#include "CParagraphFormat.h"
#include "CParagraph.h"
#include "CParagraphs.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWelfare2Dlg 对话框



CWelfare2Dlg::CWelfare2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WELFARE2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWelfare2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATA_BOLD_A, m_dataBoldA);
	DDX_Control(pDX, IDC_DATA_BOLD_B, m_dataBoldB);
	DDX_Control(pDX, IDC_DATA_CODE_A, m_dataCodeA);
	DDX_Control(pDX, IDC_DATA_CODE_B, m_dataCodeB);
	DDX_Control(pDX, IDC_DATA_ISSUE, m_dataIssue);
	DDX_Control(pDX, IDC_HANDLE_GEN_A, m_handleGenA);
	DDX_Control(pDX, IDC_HANDLE_GEN_B, m_handleGenB);
	DDX_Control(pDX, IDC_HANDLE_KILL_A, m_handleKillA);
	DDX_Control(pDX, IDC_HANDLE_KILL_B, m_handleKillB);
	DDX_Control(pDX, IDC_HANDLE_PRINT, m_handlePrint);
	DDX_Control(pDX, IDC_HANDLE_RESET, m_handleReset);
	DDX_Control(pDX, IDC_HANDLE_SAVE_A, m_handleSaveA);
	DDX_Control(pDX, IDC_HANDLE_SAVE_B, m_handleSaveB);
	DDX_Control(pDX, IDC_INFO_OUTPUT, m_output);
	//  DDX_Control(pDX, IDC_LIST_CODE, m_listCode);
	//  DDX_Control(pDX, IDC_LIST_TITLE, m_listTitle);
	DDX_Control(pDX, IDC_LIST_CODE, m_listCode);
	DDX_Control(pDX, IDC_LIST_TITLE, m_listTitle);
	DDX_Control(pDX, IDC_HANDLE_RESET_ALL, m_handleResetAll);
	DDX_Control(pDX, IDC_STATIC_OUTPUT, m_outputTitle);
}

BEGIN_MESSAGE_MAP(CWelfare2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_HANDLE_GEN_A, &CWelfare2Dlg::OnClickedHandleGenA)
	ON_BN_CLICKED(IDC_HANDLE_KILL_A, &CWelfare2Dlg::OnBnClickedHandleKillA)
	ON_BN_CLICKED(IDC_HANDLE_SAVE_A, &CWelfare2Dlg::OnBnClickedHandleSaveA)
	ON_BN_CLICKED(IDC_HANDLE_GEN_B, &CWelfare2Dlg::OnBnClickedHandleGenB)
	ON_BN_CLICKED(IDC_HANDLE_KILL_B, &CWelfare2Dlg::OnBnClickedHandleKillB)
	ON_BN_CLICKED(IDC_HANDLE_SAVE_B, &CWelfare2Dlg::OnBnClickedHandleSaveB)
	ON_BN_CLICKED(IDC_HANDLE_PRINT, &CWelfare2Dlg::OnBnClickedHandlePrint)
	ON_BN_CLICKED(IDC_HANDLE_RESET, &CWelfare2Dlg::OnBnClickedHandleReset)
	ON_NOTIFY(NM_CLICK, IDC_LIST_TITLE, &CWelfare2Dlg::OnNMClickListTitle)
	ON_BN_CLICKED(IDC_HANDLE_RESET_ALL, &CWelfare2Dlg::OnBnClickedHandleResetAll)
END_MESSAGE_MAP()


// 处理回车键
BOOL CWelfare2Dlg::PreTranslateMessage(MSG* MSG)
{
	if (MSG->message == WM_KEYDOWN && MSG->wParam == VK_ESCAPE)
		return TRUE;
	else
		return CDialog::PreTranslateMessage(MSG);
}

// 处理OK
void CWelfare2Dlg::OnOK()
{
	// do nothing
}

// CWelfare2Dlg 消息处理程序

BOOL CWelfare2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	location = new Location2CodeEncode();

	m_listTitle.InsertColumn(0, _T("预测队列"));
	m_listTitle.SetColumnWidth(0, 80);

	m_dataIssue.SetWindowTextW(_T("888"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CWelfare2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWelfare2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CWelfare2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 工具函数系列
// 输出到列表

void output2List(CListBox &listBox, vector<Location2Code> data) {
	listBox.ResetContent();
	for (vector<Location2Code>::iterator it = data.begin(); it != data.end(); it++) {
		CString tmp;
		tmp.Format(_T("[%d]-%d%d"), it->freq, it->codeSeq[0], it->codeSeq[1]);
		listBox.AddString(tmp);
	}
}

void updateListTitle(CListCtrl &m_listTitle, CString item) {
	if (item.GetLength() == 0) {
		return;
	}
	// 更新分组
	int count = m_listTitle.GetItemCount();
	m_listTitle.InsertItem(count, item);
}


void CWelfare2Dlg::OnClickedHandleGenA()
{
	CString codeString;
	m_dataCodeA.GetWindowTextW(codeString);
	int length = codeString.GetLength();
	if (length == 0) {
		MessageBox(_T("请输入组码序列"), _T("百十位: 输入序列为空"), MB_OK);
		return;
	}

	if (location->isGenerateACode() && !location->isSavedACode()) {
		int key = MessageBox(_T("上一组百十位预测码未保存，是否现在保存?"), _T("保存？"), MB_OKCANCEL);
		if (key == IDOK) {
			location->save(location->aCode, A);
			// 更新分组
			updateListTitle(m_listTitle, _T("A组:百十位"));
		}
	}

	if (location->isGenerateBCode() && !location->isGenerateBCode()) {
		int key = MessageBox(_T("上一组十个位预测码未保存，是否现在保存?"), _T("保存？"), MB_OKCANCEL);
		if (key == IDOK) {
			location->save(location->bCode, B);
			// 更新分组
			updateListTitle(m_listTitle, _T("B组:十个位"));
		}
	}
	
	set<int> numbers;
	char *p = (LPSTR)(LPCTSTR)codeString;
	for (int j = 0; j<2 * length; j = j + 2)
	{
		int tmp = *(p + j) - 48;
		numbers.insert(tmp);
	}
	
	location->generateACode(numbers);

	// 输出到列表
	output2List(m_listCode, location -> tmpCode);

	CString stat;
	stat.Format(_T("预测码, 百十位: %d 注"), location->tmpCode.size());
	m_output.SetWindowTextW(stat);
	m_outputTitle.SetWindowTextW(_T("百十位预测码"));
} 


void CWelfare2Dlg::OnBnClickedHandleKillA()
{
	CString codeString;
	m_dataBoldA.GetWindowTextW(codeString);
	int length = codeString.GetLength();
	if (length == 0) {
		MessageBox(_T("请输入胆杀序列"), _T("百十位: 输入序列为空"), MB_OK);
		return;
	}

	set<int> numbers;
	char *p = (LPSTR)(LPCTSTR)codeString;
	for (int j = 0; j<2 * length; j = j + 2)
	{
		int tmp = *(p + j) - 48;
		numbers.insert(tmp);
	}

	int before = location->tmpCode.size();

	location->killCode(numbers);

	output2List(m_listCode, location->tmpCode);

	CString stat;
	stat.Format(_T("百十位杀码, 余: %d 注， 杀: %d 注"), location->tmpCode.size(), before - location->tmpCode.size());
	m_output.SetWindowTextW(stat);
	m_outputTitle.SetWindowTextW(_T("百十位预测码"));
}




void CWelfare2Dlg::OnBnClickedHandleSaveA()
{
	if (!location->isGenerateACode() || location->isSavedACode()) 
	{
		return;
	}
	// 保存组码到A
	location->save(location->aCode, A);
	
	// 更新分组
	updateListTitle(m_listTitle, _T("A组:百十位"));

	// 输出到列表
	output2List(m_listCode, location->aCode);
}


void CWelfare2Dlg::OnBnClickedHandleGenB()
{
	CString codeString;
	m_dataCodeB.GetWindowTextW(codeString);
	int length = codeString.GetLength();
	if (length == 0) {
		MessageBox(_T("请输入组码序列"), _T("十个位: 输入序列为空"), MB_OK);
		return;
	}

	if (location->isGenerateACode() && !location->isSavedACode()) {
		int key = MessageBox(_T("上一组百十位预测码未保存，是否现在保存?"), _T("保存？"), MB_OKCANCEL);
		if (key == IDOK) {
			location->save(location->aCode, A);
			// 更新分组
			updateListTitle(m_listTitle, _T("A组:百十位"));
		}
	}

	if (location->isGenerateBCode() && !location->isGenerateBCode()) {
		int key = MessageBox(_T("上一组十个位预测码未保存，是否现在保存?"), _T("保存？"), MB_OKCANCEL);
		if (key == IDOK) {
			location->save(location->bCode, B);
			// 更新分组
			updateListTitle(m_listTitle, _T("B组:十个位"));
		}
	}

	set<int> numbers;
	char *p = (LPSTR)(LPCTSTR)codeString;
	for (int j = 0; j<2 * length; j = j + 2)
	{
		int tmp = *(p + j) - 48;
		numbers.insert(tmp);
	}

	location->generateBCode(numbers);

	// 输出到列表
	output2List(m_listCode, location->tmpCode);
	
	CString stat;
	stat.Format(_T("预测码, 十个位: %d 注"), location->tmpCode.size());
	m_output.SetWindowTextW(stat);
	m_outputTitle.SetWindowTextW(_T("十个位预测码"));
}


void CWelfare2Dlg::OnBnClickedHandleKillB()
{
	CString codeString;
	m_dataBoldB.GetWindowTextW(codeString);
	int length = codeString.GetLength();
	if (length == 0) {
		MessageBox(_T("请输入胆杀序列"), _T("十个位: 输入序列为空"), MB_OK);
		return;
	}

	set<int> numbers;
	char *p = (LPSTR)(LPCTSTR)codeString;
	for (int j = 0; j<2 * length; j = j + 2)
	{
		int tmp = *(p + j) - 48;
		numbers.insert(tmp);
	}

	int before = location->tmpCode.size();

	location->killCode(numbers);

	output2List(m_listCode, location->tmpCode);

	CString stat;
	stat.Format(_T("十个位杀码, 余: %d 注， 杀: %d 注"), location->tmpCode.size(), before - location->tmpCode.size());
	m_output.SetWindowTextW(stat);
	m_outputTitle.SetWindowTextW(_T("十个位预测码"));
}


void CWelfare2Dlg::OnBnClickedHandleSaveB()
{
	if (!location->isGenerateBCode() || location->isSavedBCode())
	{
		return;
	}
	// 保存组码到B
	location->save(location->bCode, B);

	// 更新分组
	updateListTitle(m_listTitle, _T("B组:十个位"));

	// 输出到列表
	output2List(m_listCode, location->bCode);
}


// 打印数据
void printVector(CSelection oSel, vector<Location2Code> vec, CString mTitle) {
	CString spacestr = _T("      ");
	CString separator = _T("\n-------------------------------");
	CMyFont font = oSel.get_Font();
	font.put_Size(12);
	CString str;
	str.Format(_T(" \n\n "));
	oSel.TypeText(str + mTitle);
	oSel.TypeText(separator);
	font.put_Size(10);
	oSel.TypeParagraph();
	for (vector<Location2Code>::iterator it = vec.begin(); it != vec.end(); it++) {
		CString tmp;
		tmp.Format(_T("[%d]%d%d"), it->freq, it->codeSeq[0], it->codeSeq[1]);
		oSel.TypeText(tmp);
		oSel.MoveLeft(COleVariant((short)2), COleVariant((short)1), COleVariant((short)1));
		font.put_Size(14);
		oSel.MoveRight(COleVariant((short)2), COleVariant((short)1), COleVariant((short)0));
		font.put_Size(10);
		oSel.TypeText(spacestr);
	}
}


void CWelfare2Dlg::OnBnClickedHandlePrint()
{
	if (!location->isSavedACode() && !location->isSavedBCode()) {
		MessageBox(_T("没有预测数据，请先预测"), _T("预测序列为空"), MB_OK);
		return;
	}

	CString issue;
	m_dataIssue.GetWindowTextW(issue);
	if (issue.GetLength() == 0) {
		issue = _T("888");
	}
	CString stat;
	stat.Format(_T("正在导出定位二码...请稍候..."), location->aCode.size(), location->bCode.size());

	// 导出到word
	// 定义word操作变量
	COleVariant  vTrue((short)TRUE),
		vFalse((short)FALSE),
		vopt((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	CApplication oWordApp;
	CSelection oSel;
	CDocuments oDocs;
	CMyDocument oDoc;
	CParagraphs paragraphs;


	if (!oWordApp.CreateDispatch(_T("Word.Application"))) {
		AfxMessageBox(_T("word初始化失败！"), MB_OK & MB_SETFOREGROUND);
		return;  // 返回，否则程序崩溃 
	}
	// 先不显示
	oWordApp.put_Visible(false);

	oDocs = oWordApp.get_Documents();
	oDoc = oDocs.Add(vopt, vopt, vopt, vopt);
	oSel = oWordApp.get_Selection();
	oSel.WholeStory();

	CParagraphFormat cformat = oSel.get_ParagraphFormat();
	cformat.put_Alignment(0);

	CMyFont font = oSel.get_Font();
	CString str;
	str.Format(_T("\t\t第 %s 期 福彩3D码《定位二码序列》\n"), issue);
	font.put_Name(_T("黑体"));
	font.put_Size(18);
	oSel.TypeText(str);
	str.Format(_T("\t\t\t\t\t\t\t本报表由 “定位二码法” 导出！！\n"));
	font.put_Name(_T("宋体"));
	font.put_Size(12);
	oSel.TypeText(str);
	oSel.TypeParagraph();
	font.put_Size(14);

	if (location->isGenerateACode() && location->isSavedACode()) {
		CString title;
		title.Format(_T("※ 百十位 ※ 定位二码: %d 注 "), location->aCode.size());
		printVector(oSel, location->aCode, title);
	}

	if (location->isGenerateACode() && location->isSavedACode()) {
		CString title;
		title.Format(_T("※ 十个位 ※ 定位二码: %d 注 "), location->bCode.size());
		printVector(oSel, location->bCode, title);
	}

	stat.Format(_T("定位二码已经导出, 百十位: %d 注; 十个位:%d 注"), location->aCode.size(), location->bCode.size());
	m_output.SetWindowTextW(stat);

	// 显示报表
	oWordApp.put_Visible(true);

}



void CWelfare2Dlg::OnBnClickedHandleReset()
{
	m_listCode.ResetContent();
	m_listTitle.DeleteAllItems();
	m_dataCodeA.SetWindowTextW(_T(""));
	m_dataCodeB.SetWindowTextW(_T(""));
	m_dataBoldA.SetWindowTextW(_T(""));
	m_dataBoldB.SetWindowTextW(_T(""));
	m_output.SetWindowTextW(_T(""));
}


void CWelfare2Dlg::OnNMClickListTitle(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if (pNMListView->iItem != -1) {
		int index = pNMListView->iItem;

	}
	*pResult = 0;
}


void CWelfare2Dlg::OnBnClickedHandleResetAll()
{
	location->clear();
	OnBnClickedHandleReset();
}
