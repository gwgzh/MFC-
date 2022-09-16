
// 11.1MFC对话框程序与控件Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "11.1MFC对话框程序与控件.h"
#include "11.1MFC对话框程序与控件Dlg.h"
#include "afxdialogex.h"
#include "B_diaglog.h"
#include "A_diaglog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &CAboutDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CAboutDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CMy 对话框



CMy::CMy(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY111MFC_DIALOG, pParent),flag(false),myColor(0),timer(0),TimerOn(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_Pic, PicControl);
}

BEGIN_MESSAGE_MAP(CMy, CDialogEx)
//	ON_WM_SYSCOMMAND()
//	ON_WM_PAINT()
//	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT2, &CMy::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CMy::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO1, &CMy::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMy::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CMy::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO4, &CMy::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_CHECK1, &CMy::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_COMBO2, &CMy::OnBnClickedRadio1)

	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CMy::OnDtnDatetimechangeDatetimepicker1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMy::OnLbnSelchangeList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMy::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CMy::OnBnClickedMfccolorbutton1)
	ON_CBN_SELCHANGE(IDC_MFCFONTCOMBO1, &CMy::OnCbnSelchangeMfcfontCombo1)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CMy::OnBnClickedRadio1)
//	ON_WM_CTLCOLOR()
ON_WM_CTLCOLOR()
//ON_WM_FONTCHANGE()
ON_BN_CLICKED(IDC_BUTTONTIMER, &CMy::OnBnClickedButtontimer)
ON_WM_TIMER()
ON_COMMAND(ID_32771, &CMy::On32771)
ON_COMMAND(ID_32772, &CMy::On32772)
ON_COMMAND(ID_32777, &CMy::On32777)
ON_COMMAND(ID_change1, &CMy::Onchangepicture1)
ON_COMMAND(ID_change2, &CMy::Onchangepicture2)
ON_COMMAND(ID_change3, &CMy::Onchangepicture3)

END_MESSAGE_MAP()


// CMy 消息处理程序

BOOL CMy::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);  //IDR_MENU1为菜单栏ID号
	SetMenu(&menu);
	//添加工具栏
	CToolBar tbr;
	tbr.LoadToolBar(IDR_TOOLBAR1);


	//DockControlBar(&m_toolBar);
	// 将“关于...”菜单项添加到系统菜单中。
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//*初始单选对话框*//
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);	//从1到2，（顺序很重要涉及分组）选中IDC_RADIO1
	CheckRadioButton(IDC_RADIO3, IDC_RADIO4, IDC_RADIO3);

	/*选取框添加选项*/
	CString work[2] =
	{
		_T("第一集团"),
		_T("XIHUADAXUE")
	};
	CComboBox* combobox;
	combobox = (CComboBox*)GetDlgItem(IDC_COMBO1);
	combobox->DeleteString(0);
	for (int i = 0; i < 2; i++) combobox->AddString(work[i]);

	/*clist初始化*/
	CString list[7] =
	{
		_T("低于1000"),
		_T("1000~2000"),
		_T("2000~3000"),
		_T("3000~4000"),
		_T("4000~5000"),
		_T("5000~6000"),
		_T("大于6000")
	};
	CListBox* clist = (CListBox*)GetDlgItem(IDC_LIST1);
	for(int i=0;i<sizeof(list)/sizeof(CString);i++) clist->AddString(list[i]);

	/*初始化字体*/
	//CComboBox* combobox2 = ((CComboBox*)GetDlgItem(IDC_COMBO2));


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//void CMy::OnSysCommand(UINT nID, LPARAM lParam)
//{
//	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
//	{
//		CAboutDlg dlgAbout;
//		dlgAbout.DoModal();
//	}
//	else
//	{
//		CDialogEx::OnSysCommand(nID, lParam);
//	}
//}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

//void CMy::OnPaint()
//{
//	if (IsIconic())
//	{
//		CPaintDC dc(this); // 用于绘制的设备上下文
//
//		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
//
//		// 使图标在工作区矩形中居中
//		int cxIcon = GetSystemMetrics(SM_CXICON);
//		int cyIcon = GetSystemMetrics(SM_CYICON);
//		CRect rect;
//		GetClientRect(&rect);
//		int x = (rect.Width() - cxIcon + 1) / 2;
//		int y = (rect.Height() - cyIcon + 1) / 2;
//
//		// 绘制图标
//		dc.DrawIcon(x, y, m_hIcon);
//	}
//	else
//	{
//		CDialogEx::OnPaint();
//	}
//}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
//HCURSOR CMy::OnQueryDragIcon()
//{
//	return static_cast<HCURSOR>(m_hIcon);
//}



void CAboutDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CAboutDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMy::公用事件处理(int myControlID)
{
	// TODO: 在此处添加实现代码.
	CString text;
	GetDlgItemText(myControlID, text);
	GetDlgItem(IDC_STATIC1)->SetWindowTextW(text);	//系统bug不用管直接编译。
}


void CMy::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	公用事件处理(GetDlgItem(IDC_EDIT2)->GetDlgCtrlID());
}

void CMy::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UINT ID = LOWORD(GetCurrentMessage()->wParam);
	公用事件处理(GetDlgItem(ID)->GetDlgCtrlID());
}


void CMy::OnDtnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	UINT ID = LOWORD(GetCurrentMessage()->wParam);
	公用事件处理(GetDlgItem(ID)->GetDlgCtrlID());
	*pResult = 0;
}


void CMy::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT ID = LOWORD(GetCurrentMessage()->wParam);
	int index = ((CListBox*)GetDlgItem(ID))->GetCurSel();
	CString text;
	((CListBox*)GetDlgItem(ID))->GetText(index, text);
	SetDlgItemText(IDC_STATIC1, text);
}

void CMy::OnBnClickedMfccolorbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CMFCColorButton* ColorPicke;
	ColorPicke = (CMFCColorButton*) GetDlgItem(IDC_MFCCOLORBUTTON1);
	myColor = ColorPicke->GetColor();
	flag = true;
	GetDlgItem(IDC_STATIC1)->RedrawWindow();
}


void CMy::OnCbnSelchangeMfcfontCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT ID = LOWORD(GetCurrentMessage()->wParam);
	CMFCFontComboBox* FontCombobox = ((CMFCFontComboBox*)GetDlgItem(ID));
	CString text = FontCombobox->GetSelFont()->m_strName;
	SetDlgItemText(IDC_STATIC1,text);

	/*修改字体*/
	m_font.CreatePointFont(100,text, NULL);
	GetDlgItem(IDC_STATIC1)->SetFont(&m_font, true);


	/*遍历控件ID，将字体应用于全局*/

	CWnd* pWnd = NULL;
	pWnd = GetWindow(GW_CHILD);	//获取第一个子控件

	while (pWnd)
	{
		//对控件进行处理

		// if CWnd is a child window, the function searches for the next (or previous) child window.
		pWnd->SetFont(&m_font, true);
		pWnd = pWnd->GetNextWindow();
	}
	m_font.Detach();	//解除占用
	
}


HBRUSH CMy::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if ((pWnd->GetDlgCtrlID() == IDC_STATIC1) && flag)
	{
		pDC->SetTextColor(RGB(255, 0, 0));
		pDC->SetBkColor(myColor);
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;

}


void CMy::OnBnClickedButtontimer()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!TimerOn)	//开始计时
	{
		SetDlgItemTextW(IDC_STATIC1, _T("开始计时"));
		TimerOn = true;
		SetTimer(1, 500, NULL);
	}
	else//关闭计时器
	{
		SetDlgItemTextW(IDC_STATIC1, _T(" 停止计时"));
		TimerOn = false;
		KillTimer(1);
	}
}

void CMy::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (TimerOn)
	{
		timer++;
		char ch[6] = {};
		_itoa_s(timer, ch, 10);
		CString text(ch);
		SetDlgItemTextW(IDC_STATICTIMER, text);	
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CMy::On32771()	//菜单事件处理函数
{
	// TODO: 在此添加命令处理程序代码
	A_diaglog* pDlg = new A_diaglog;
	pDlg->Create(IDD_DIALOG1, this); //IDD_DIALOG2就是刚才添加资源的Dialog的ID
	pDlg->ShowWindow(SW_SHOW);
}


void CMy::On32772()
{
	// TODO: 在此添加命令处理程序代码
	B_diaglog b;
	b.DoModal();
}


void CMy::On32777()
{
	// TODO: 在此添加命令处理程序代码
	CMenu* myMenu;
	myMenu = GetMenu()->GetSubMenu(1);
	//隐藏或显示照片
	if (!PicControl.ShowWindow(SW_HIDE))
	{
		//成功隐藏则退出，否则显示
		PicControl.ShowWindow(SW_SHOW);
		//取消复选框
	}
	else
	{
		myMenu->CheckMenuItem(ID_32777, MF_BYCOMMAND|MF_CHECKED);
	}
}



void CMy::Onchangepicture1()
{
	// TODO: 在此添加命令处理程序代码
	CBitmap m_Bitmap;

	HBITMAP hBitmap;

	m_Bitmap.LoadBitmap(IDB_BITMAP1);//加载位图

	hBitmap = (HBITMAP)m_Bitmap.GetSafeHandle();//获得位图的句柄

	PicControl.SetBitmap(hBitmap);
	//PicControl.Detach();
}
void CMy::Onchangepicture2()
{
	// TODO: 在此添加命令处理程序代码
	CBitmap m_Bitmap;

	HBITMAP hBitmap;

	m_Bitmap.LoadBitmap(IDB_BITMAP2);//加载位图

	hBitmap = (HBITMAP)m_Bitmap.GetSafeHandle();//获得位图的句柄

	PicControl.SetBitmap(hBitmap);
}

void CMy::Onchangepicture3()
{
	// TODO: 在此添加命令处理程序代码
	CBitmap m_Bitmap;

	HBITMAP hBitmap;

	m_Bitmap.LoadBitmap(IDB_BITMAP3);//加载位图

	hBitmap = (HBITMAP)m_Bitmap.GetSafeHandle();//获得位图的句柄

	PicControl.SetBitmap(hBitmap);

}


