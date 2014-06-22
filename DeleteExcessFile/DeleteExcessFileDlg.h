
// DeleteExcessFileDlg.h : ͷ�ļ�
//

#pragma once
#include "Operation.h"


// CDeleteExcessFileDlg �Ի���
class CDeleteExcessFileDlg : public CDialogEx
{
// ����
public:
	CDeleteExcessFileDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DELETEEXCESSFILE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedSeletedirbutton();
private:
    void DisableAllButton();
    void EnableAllButton();
private:
    enum ENUM_CBUTTON
    {
        CBUTTON_SELECT_DIR,
        CBUTTON_DELETE_ADD,
        CBUTTON_EXECUTE
    };
private:
    CEdit* m_pSelectDIrEdit;
    CEdit* m_pDeleteAddEdit;
    CEdit* m_pDeleteShowEdit;
    CButton* m_arrButton[3];
    std::vector<CString> m_vecType;
    COperation m_cOperation;
public:
    afx_msg void OnBnClickedDeleteaddbutton();
    afx_msg void OnBnClickedExecutebutton();
};
