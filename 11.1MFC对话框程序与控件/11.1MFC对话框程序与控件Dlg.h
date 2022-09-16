
// 11.1MFC对话框程序与控件Dlg.h: 头文件
//

#pragma once


// CMy 对话框
class CMy : public CDialogEx
{
// 构造
public:

	CMy(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY111MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
//	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
//	afx_msg void OnPaint();
//	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void 公用事件处理(int myControlID);
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedMfccolorbutton1();

	/*my code*/
public:
	COLORREF myColor;
	bool flag;
	afx_msg void OnCbnSelchangeMfcfontCombo1();
	CFont m_font;
	time_t timer;
	bool TimerOn;
	CMFCToolBar  m_toolBar;
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	afx_msg void OnFontChange();
	afx_msg void OnBnClickedButtontimer();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void On32771();
	afx_msg void On32772();
	CStatic PicControl;
	afx_msg void On32777();
	afx_msg void Onchangepicture1();
	afx_msg void Onchangepicture2();
	afx_msg void Onchangepicture3();
};
