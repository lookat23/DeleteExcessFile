#pragma once
#include <vector>
class COperation
{
public:
    COperation(void);
    ~COperation(void);
    BOOL CheckDuplicate(std::vector<CString>& vecStr, CString strField);        // ���vec�����Ƿ��Ѿ������ֶ�
    void UpdateShowEdit(std::vector<CString>& vecStr, CEdit* pEdit);      // ˢ����ʾ�������ͱ�ɾ��edit
    void FindBmpFile(std::vector<CString>& vecStr, CString strFoldername);                                        // ����ָ��Ŀ¼
    BOOL DeleteFile(CString filePath);      //ɾ���ļ�
};

