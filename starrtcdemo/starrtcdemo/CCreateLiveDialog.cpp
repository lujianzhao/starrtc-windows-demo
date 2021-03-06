// CCreateLiveDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CCreateLiveDialog.h"
#include "afxdialogex.h"



// CCreateLiveDialog 对话框

IMPLEMENT_DYNAMIC(CCreateLiveDialog, CDialogEx)

CCreateLiveDialog::CCreateLiveDialog(CUserManager* pUserManager, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CREATE_LIVE, pParent)
{
	m_pUserManager = pUserManager;
	m_bPublic = false;
}

CCreateLiveDialog::~CCreateLiveDialog()
{
}

void CCreateLiveDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CREATE_LIVE_NAME, m_liveNameEdit);
	DDX_Control(pDX, IDC_CHECK_PUBLIC, m_publicCheckBox);
}


BEGIN_MESSAGE_MAP(CCreateLiveDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CREATE_LIVE, &CCreateLiveDialog::OnBnClickedButtonCreateLive)
END_MESSAGE_MAP()


// CCreateLiveDialog 消息处理程序


void CCreateLiveDialog::OnBnClickedButtonCreateLive()
{
	m_bPublic = false;
	m_strLiveName = "";
	m_liveNameEdit.GetWindowText(m_strLiveName);
	if (1 == m_publicCheckBox.GetCheck())
	{
		m_bPublic = true;
	}
	if (m_strLiveName != "")
	{
		OnOK();
	}
	else
	{
		AfxMessageBox("直播名称不能为空");
	}
}
