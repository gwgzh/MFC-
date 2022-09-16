
// 11.1MFC对话框程序与控件.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CMy111MFC对话框程序与控件App:
// 有关此类的实现，请参阅 11.1MFC对话框程序与控件.cpp
//

class CMy111MFC对话框程序与控件App : public CWinApp
{
public:
	CMy111MFC对话框程序与控件App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy111MFC对话框程序与控件App theApp;
