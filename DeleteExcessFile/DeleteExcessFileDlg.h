
// DeleteExcessFileDlg.h : 头文件
//

#pragma once
#include "Operation.h"


// CDeleteExcessFileDlg 对话框
class CDeleteExcessFileDlg : public CDialogEx
{
// 构造
public:
	CDeleteExcessFileDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DELETEEXCESSFILE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
