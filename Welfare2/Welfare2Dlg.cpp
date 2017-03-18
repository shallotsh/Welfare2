
// Welfare2Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CWelfare2Dlg �Ի���



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


// ����س���
BOOL CWelfare2Dlg::PreTranslateMessage(MSG* MSG)
{
	if (MSG->message == WM_KEYDOWN && MSG->wParam == VK_ESCAPE)
		return TRUE;
	else
		return CDialog::PreTranslateMessage(MSG);
}

// ����OK
void CWelfare2Dlg::OnOK()
{
	// do nothing
}

// CWelfare2Dlg ��Ϣ�������

BOOL CWelfare2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	location = new Location2CodeEncode();

	m_listTitle.InsertColumn(0, _T("Ԥ�����"));
	m_listTitle.SetColumnWidth(0, 80);

	m_dataIssue.SetWindowTextW(_T("888"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CWelfare2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CWelfare2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���ߺ���ϵ��
// ������б�

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
	// ���·���
	int count = m_listTitle.GetItemCount();
	m_listTitle.InsertItem(count, item);
}


void CWelfare2Dlg::OnClickedHandleGenA()
{
	CString codeString;
	m_dataCodeA.GetWindowTextW(codeString);
	int length = codeString.GetLength();
	if (length == 0) {
		MessageBox(_T("��������������"), _T("��ʮλ: ��������Ϊ��"), MB_OK);
		return;
	}

	if (location->isGenerateACode() && !location->isSavedACode()) {
		int key = MessageBox(_T("��һ���ʮλԤ����δ���棬�Ƿ����ڱ���?"), _T("���棿"), MB_OKCANCEL);
		if (key == IDOK) {
			location->save(location->aCode, A);
			// ���·���
			updateListTitle(m_listTitle, _T("A��:��ʮλ"));
		}
	}

	if (location->isGenerateBCode() && !location->isGenerateBCode()) {
		int key = MessageBox(_T("��һ��ʮ��λԤ����δ���棬�Ƿ����ڱ���?"), _T("���棿"), MB_OKCANCEL);
		if (key == IDOK) {
			location->save(location->bCode, B);
			// ���·���
			updateListTitle(m_listTitle, _T("B��:ʮ��λ"));
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

	// ������б�
	output2List(m_listCode, location -> tmpCode);

	CString stat;
	stat.Format(_T("Ԥ����, ��ʮλ: %d ע"), location->tmpCode.size());
	m_output.SetWindowTextW(stat);
	m_outputTitle.SetWindowTextW(_T("��ʮλԤ����"));
} 


void CWelfare2Dlg::OnBnClickedHandleKillA()
{
	CString codeString;
	m_dataBoldA.GetWindowTextW(codeString);
	int length = codeString.GetLength();
	if (length == 0) {
		MessageBox(_T("�����뵨ɱ����"), _T("��ʮλ: ��������Ϊ��"), MB_OK);
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
	stat.Format(_T("��ʮλɱ��, ��: %d ע�� ɱ: %d ע"), location->tmpCode.size(), before - location->tmpCode.size());
	m_output.SetWindowTextW(stat);
	m_outputTitle.SetWindowTextW(_T("��ʮλԤ����"));
}




void CWelfare2Dlg::OnBnClickedHandleSaveA()
{
	if (!location->isGenerateACode() || location->isSavedACode()) 
	{
		return;
	}
	// �������뵽A
	location->save(location->aCode, A);
	
	// ���·���
	updateListTitle(m_listTitle, _T("A��:��ʮλ"));

	// ������б�
	output2List(m_listCode, location->aCode);
}


void CWelfare2Dlg::OnBnClickedHandleGenB()
{
	CString codeString;
	m_dataCodeB.GetWindowTextW(codeString);
	int length = codeString.GetLength();
	if (length == 0) {
		MessageBox(_T("��������������"), _T("ʮ��λ: ��������Ϊ��"), MB_OK);
		return;
	}

	if (location->isGenerateACode() && !location->isSavedACode()) {
		int key = MessageBox(_T("��һ���ʮλԤ����δ���棬�Ƿ����ڱ���?"), _T("���棿"), MB_OKCANCEL);
		if (key == IDOK) {
			location->save(location->aCode, A);
			// ���·���
			updateListTitle(m_listTitle, _T("A��:��ʮλ"));
		}
	}

	if (location->isGenerateBCode() && !location->isGenerateBCode()) {
		int key = MessageBox(_T("��һ��ʮ��λԤ����δ���棬�Ƿ����ڱ���?"), _T("���棿"), MB_OKCANCEL);
		if (key == IDOK) {
			location->save(location->bCode, B);
			// ���·���
			updateListTitle(m_listTitle, _T("B��:ʮ��λ"));
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

	// ������б�
	output2List(m_listCode, location->tmpCode);
	
	CString stat;
	stat.Format(_T("Ԥ����, ʮ��λ: %d ע"), location->tmpCode.size());
	m_output.SetWindowTextW(stat);
	m_outputTitle.SetWindowTextW(_T("ʮ��λԤ����"));
}


void CWelfare2Dlg::OnBnClickedHandleKillB()
{
	CString codeString;
	m_dataBoldB.GetWindowTextW(codeString);
	int length = codeString.GetLength();
	if (length == 0) {
		MessageBox(_T("�����뵨ɱ����"), _T("ʮ��λ: ��������Ϊ��"), MB_OK);
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
	stat.Format(_T("ʮ��λɱ��, ��: %d ע�� ɱ: %d ע"), location->tmpCode.size(), before - location->tmpCode.size());
	m_output.SetWindowTextW(stat);
	m_outputTitle.SetWindowTextW(_T("ʮ��λԤ����"));
}


void CWelfare2Dlg::OnBnClickedHandleSaveB()
{
	if (!location->isGenerateBCode() || location->isSavedBCode())
	{
		return;
	}
	// �������뵽B
	location->save(location->bCode, B);

	// ���·���
	updateListTitle(m_listTitle, _T("B��:ʮ��λ"));

	// ������б�
	output2List(m_listCode, location->bCode);
}


// ��ӡ����
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
		MessageBox(_T("û��Ԥ�����ݣ�����Ԥ��"), _T("Ԥ������Ϊ��"), MB_OK);
		return;
	}

	CString issue;
	m_dataIssue.GetWindowTextW(issue);
	if (issue.GetLength() == 0) {
		issue = _T("888");
	}
	CString stat;
	stat.Format(_T("���ڵ�����λ����...���Ժ�..."), location->aCode.size(), location->bCode.size());

	// ������word
	// ����word��������
	COleVariant  vTrue((short)TRUE),
		vFalse((short)FALSE),
		vopt((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	CApplication oWordApp;
	CSelection oSel;
	CDocuments oDocs;
	CMyDocument oDoc;
	CParagraphs paragraphs;


	if (!oWordApp.CreateDispatch(_T("Word.Application"))) {
		AfxMessageBox(_T("word��ʼ��ʧ�ܣ�"), MB_OK & MB_SETFOREGROUND);
		return;  // ���أ����������� 
	}
	// �Ȳ���ʾ
	oWordApp.put_Visible(false);

	oDocs = oWordApp.get_Documents();
	oDoc = oDocs.Add(vopt, vopt, vopt, vopt);
	oSel = oWordApp.get_Selection();
	oSel.WholeStory();

	CParagraphFormat cformat = oSel.get_ParagraphFormat();
	cformat.put_Alignment(0);

	CMyFont font = oSel.get_Font();
	CString str;
	str.Format(_T("\t\t�� %s �� ����3D�롶��λ�������С�\n"), issue);
	font.put_Name(_T("����"));
	font.put_Size(18);
	oSel.TypeText(str);
	str.Format(_T("\t\t\t\t\t\t\t�������� ����λ���뷨�� ��������\n"));
	font.put_Name(_T("����"));
	font.put_Size(12);
	oSel.TypeText(str);
	oSel.TypeParagraph();
	font.put_Size(14);

	if (location->isGenerateACode() && location->isSavedACode()) {
		CString title;
		title.Format(_T("�� ��ʮλ �� ��λ����: %d ע "), location->aCode.size());
		printVector(oSel, location->aCode, title);
	}

	if (location->isGenerateACode() && location->isSavedACode()) {
		CString title;
		title.Format(_T("�� ʮ��λ �� ��λ����: %d ע "), location->bCode.size());
		printVector(oSel, location->bCode, title);
	}

	stat.Format(_T("��λ�����Ѿ�����, ��ʮλ: %d ע; ʮ��λ:%d ע"), location->aCode.size(), location->bCode.size());
	m_output.SetWindowTextW(stat);

	// ��ʾ����
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
