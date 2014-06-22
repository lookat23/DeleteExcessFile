
// DeleteExcessFileDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DeleteExcessFile.h"
#include "DeleteExcessFileDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CDeleteExcessFileDlg �Ի���




CDeleteExcessFileDlg::CDeleteExcessFileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteExcessFileDlg::IDD, pParent),
    m_pDeleteAddEdit(NULL),m_pDeleteShowEdit(NULL),m_pSelectDIrEdit(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);


}

void CDeleteExcessFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDeleteExcessFileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_SELECTDIRBUTTON, &CDeleteExcessFileDlg::OnBnClickedSeletedirbutton)
    ON_BN_CLICKED(IDC_DELETEADDBUTTON, &CDeleteExcessFileDlg::OnBnClickedDeleteaddbutton)
    ON_BN_CLICKED(IDC_EXECUTEBUTTON, &CDeleteExcessFileDlg::OnBnClickedExecutebutton)
END_MESSAGE_MAP()


// CDeleteExcessFileDlg ��Ϣ�������

BOOL CDeleteExcessFileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

    //  ���ҳ�����edit���ָ��
    m_pSelectDIrEdit = static_cast<CEdit*>(GetDlgItem(IDC_SELECTDIREDIT));
    m_pDeleteAddEdit = static_cast<CEdit*>(GetDlgItem(IDC_DELETEADDEDIT));
    m_pDeleteShowEdit = static_cast<CEdit*>(GetDlgItem(IDC_DELETESHOWEDIT));

    ASSERT(m_pSelectDIrEdit && "EditControl is NULL");
    ASSERT(m_pDeleteAddEdit && "EditControl is NULL");
    ASSERT(m_pDeleteShowEdit && "EditControl is NULL");

    // ȷ�����а�ťָ��
    m_arrButton[CBUTTON_DELETE_ADD] = static_cast<CButton*>(GetDlgItem(IDC_DELETEADDBUTTON));
    m_arrButton[CBUTTON_SELECT_DIR] = static_cast<CButton*>(GetDlgItem(IDC_SELECTDIRBUTTON));
    m_arrButton[CBUTTON_EXECUTE] = static_cast<CButton*>(GetDlgItem(IDC_EXECUTEBUTTON));
    ASSERT(m_arrButton[CBUTTON_DELETE_ADD] && "ButtonControl is NULL");
    ASSERT(m_arrButton[CBUTTON_SELECT_DIR] && "ButtonControl is NULL");
    ASSERT(m_arrButton[CBUTTON_EXECUTE] && "ButtonControl is NULL");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDeleteExcessFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
		CDialogEx::OnSysCommand(nID, lParam);
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDeleteExcessFileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDeleteExcessFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDeleteExcessFileDlg::OnBnClickedSeletedirbutton()
{
    // TODO: Add your control notification handler code here
    TCHAR szPath[MAX_PATH];     //���ѡ���Ŀ¼·�� 
    CString str;

    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName = szPath;   
    bi.lpszTitle = L"��ѡ����Ҫ�����Ŀ¼��";   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //����ѡ��Ŀ¼�Ի���
    LPITEMIDLIST lp = SHBrowseForFolder(&bi); 

    if(lp && SHGetPathFromIDList(lp, szPath))
    {
        m_pSelectDIrEdit->SetWindowText(szPath);
    }

}


void CDeleteExcessFileDlg::OnBnClickedDeleteaddbutton()
{
    // TODO: Add your control notification handler code here
    CString strType;
    m_pDeleteAddEdit->GetWindowText(strType);
    // ���պ��Ƿ��Ѿ�����
    if(!strType.IsEmpty() && !m_cOperation.CheckDuplicate(m_vecType, strType))
    {
        m_vecType.push_back(strType);
    }
    // ˢ����ʾ��
    m_cOperation.UpdateShowEdit(m_vecType, m_pDeleteShowEdit);
    // �����ӹ�������edit
    m_pDeleteAddEdit->SetWindowText(_T(""));
}


void CDeleteExcessFileDlg::OnBnClickedExecutebutton()
{
    // TODO: Add your control notification handler code here
    CString strDir;
    m_pSelectDIrEdit->GetWindowText(strDir);
    if(strDir.IsEmpty()) return;
    DisableAllButton();
    m_cOperation.FindBmpFile(m_vecType, strDir);
    EnableAllButton();
}

void CDeleteExcessFileDlg::DisableAllButton()
{
    size_t len = sizeof(m_arrButton)/sizeof(m_arrButton[0]);
    for(size_t i = 0; i < len; i++)
    {
        m_arrButton[i]->EnableWindow(FALSE);
    }
}
void CDeleteExcessFileDlg::EnableAllButton()
{
    size_t len = sizeof(m_arrButton)/sizeof(m_arrButton[0]);
    for(size_t i = 0; i < len; i++)
    {
        m_arrButton[i]->EnableWindow(TRUE);
    }
}