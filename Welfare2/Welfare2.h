
// Welfare2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWelfare2App: 
// �йش����ʵ�֣������ Welfare2.cpp
//

class CWelfare2App : public CWinApp
{
public:
	CWelfare2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWelfare2App theApp;