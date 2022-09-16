// B_diaglog.cpp: 实现文件
//

#include "pch.h"
#include "11.1MFC对话框程序与控件.h"
#include "B_diaglog.h"
#include "afxdialogex.h"


// B_diaglog 对话框

IMPLEMENT_DYNAMIC(B_diaglog, CDialogEx)

B_diaglog::B_diaglog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

B_diaglog::~B_diaglog()
{
}

void B_diaglog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(B_diaglog, CDialogEx)
END_MESSAGE_MAP()


// B_diaglog 消息处理程序
