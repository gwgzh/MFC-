#pragma once


// A_diaglog 对话框

class A_diaglog : public CDialogEx
{
	DECLARE_DYNAMIC(A_diaglog)

public:
	A_diaglog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~A_diaglog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
