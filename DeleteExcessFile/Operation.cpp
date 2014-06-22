#include "StdAfx.h"
#include "Operation.h"
#include <algorithm>
using namespace std;

COperation::COperation(void)
{
}


COperation::~COperation(void)
{
}


BOOL COperation::CheckDuplicate(vector<CString>& vecStr, CString strField)
{
    if(strField.IsEmpty())
    {
        MYTRACK(_T("CheckDuplicate�У��ֶ�Ϊ��"));
        return TRUE;
    }
    if(find(vecStr.begin(), vecStr.end(), strField) == vecStr.end())
    {
        return FALSE;
    }else
    {
        return TRUE;
    }
}

void COperation::UpdateShowEdit(std::vector<CString>& vecStr, CEdit* pEdit)
{
    ASSERT(pEdit);
    CString strText;
    std::vector<CString>::iterator it_begin = vecStr.begin();
    std::vector<CString>::iterator it_current;
    for(;it_begin != vecStr.end(); )
    {
        it_current = it_begin;
        strText += *it_current;
        it_begin++;   
        if(it_begin != vecStr.end())
            strText += _T("\r\n");
    }
    pEdit->SetWindowText(strText);
    
}

void COperation::FindBmpFile(std::vector<CString>& vecStr, CString strFoldername)
{
    CString m_cstrFileList=L"";   
    CFileFind tempFind;   
    BOOL bFound; //�ж��Ƿ�ɹ��ҵ��ļ�  
    bFound=tempFind.FindFile(strFoldername   +   "\\*.*");   //�޸�" "���ݸ��޶������ļ�����  
    CString strTmp;   //����ҵ������ļ��� ����ļ���·��  
    while(bFound)      //���������ļ�  
    {   
        bFound=tempFind.FindNextFile(); //��һ��ִ��FindNextFile��ѡ�񵽵�һ���ļ����Ժ�ִ��Ϊѡ����һ���ļ�  
        if(tempFind.IsDots())   
            continue; //����ҵ����Ƿ����ϲ��Ŀ¼ ��������β���  
        if(tempFind.IsDirectory())   //�ҵ������ļ��У���������ļ����µ��ļ�  
        {   
            strTmp=L"";   
            strTmp=tempFind.GetFilePath();  
            FindBmpFile(vecStr, strTmp);   
        }   
        else   
        {   
            CString fileName = tempFind.GetFileName();
            int dotPos = fileName.ReverseFind('.');
            if(dotPos == -1)        // û������ļ�����
                continue;
            CString fileExt = fileName.Right(fileName.GetLength() - dotPos - 1);
            //------------------------------------------------------------------
            if(std::find(vecStr.begin(), vecStr.end(), fileExt) != vecStr.end())
            {
                // ɾ���ļ�
/*                int a =10;*/
                CString filePath = tempFind.GetFilePath();
//                 // ��APIֱ��ɾ�����ŵ�����վ ̫Σ����
//                 ::DeleteFile(filePath);
                if(!DeleteFile(filePath))
                {
                    CString strTemp = L"ɾ���ļ�\"";
                    strTemp += filePath + L"\"ʧ��";
                    MYTRACK(strTemp.GetBuffer());
                }

            }
            
        }   
    }   
    tempFind.Close();   
    return;   
}

BOOL COperation::DeleteFile(CString filePath)
{
    SHFILEOPSTRUCT FileOp={0}; 
    FileOp.fFlags = FOF_ALLOWUNDO;   //����Żػ���վ
    FileOp.fFlags |= FOF_NOCONFIRMATION; //������ȷ�϶Ի���
    FileOp.fFlags |= FOF_FILESONLY;     // ֻ�����ļ����������ļ��У�
    filePath += '\0';
    FileOp.pFrom = filePath.GetBuffer(); 
    FileOp.pTo = NULL;      //һ��Ҫ��NULL
    FileOp.wFunc = FO_DELETE;    //ɾ������
    return SHFileOperation(&FileOp) == 0; 
}