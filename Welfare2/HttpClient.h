#pragma once
//////////////////////////////////// HttpClient.h  
#include <afxinet.h>  
#include <string>  
using namespace std;

#define  GOOGLE_AGENT  _T("Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36")  

// 操作成功  
#define SUCCESS        0  
// 操作失败  
#define FAILURE        1  
// 操作超时 www.it165.net  
#define OUTTIME        2  

class CHttpClient
{
public:
	CHttpClient(LPCTSTR strAgent = GOOGLE_AGENT);
	virtual ~CHttpClient(void);

	int HttpGet(LPCTSTR strUrl, LPCTSTR strPostData, CString &strResponse);
	int HttpPost(LPCTSTR strUrl, LPCTSTR strPostData, CString &strResponse);

private:
	int ExecuteRequest(LPCTSTR strMethod, LPCTSTR strUrl, LPCTSTR strPostData, CString &strResponse);
	void Clear();

private:
	CInternetSession *m_pSession;
	CHttpConnection *m_pConnection;
	CHttpFile *m_pFile;
};

