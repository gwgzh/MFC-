// CDIALOG1.cpp: 实现文件
//

#include "pch.h"
#include "MFC_Windows2.h"
#include "CDIALOG1.h"
#include "afxdialogex.h"


// CDIALOG1 对话框

IMPLEMENT_DYNAMIC(CDIALOG1, CDialogEx)

CDIALOG1::CDIALOG1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDIALOG1::~CDIALOG1()
{
}

void CDIALOG1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDIALOG1, CDialogEx)
END_MESSAGE_MAP()


// CDIALOG1 消息处理程序
