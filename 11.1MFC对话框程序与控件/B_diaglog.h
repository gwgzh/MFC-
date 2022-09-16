#pragma once


// B_diaglog 对话框

class B_diaglog : public CDialogEx
{
	DECLARE_DYNAMIC(B_diaglog)

public:
	B_diaglog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~B_diaglog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
