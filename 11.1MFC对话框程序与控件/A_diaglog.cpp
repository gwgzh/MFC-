// A_diaglog.cpp: 实现文件
//

#include "pch.h"
#include "11.1MFC对话框程序与控件.h"
#include "A_diaglog.h"
#include "afxdialogex.h"


// A_diaglog 对话框

IMPLEMENT_DYNAMIC(A_diaglog, CDialogEx)

A_diaglog::A_diaglog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

A_diaglog::~A_diaglog()
{
}

void A_diaglog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(A_diaglog, CDialogEx)
END_MESSAGE_MAP()


// A_diaglog 消息处理程序
