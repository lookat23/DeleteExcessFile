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
        MYTRACK(_T("CheckDuplicate中，字段为空"));
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
    BOOL bFound; //判断是否成功找到文件  
    bFound=tempFind.FindFile(strFoldername   +   "\\*.*");   //修改" "内容给限定查找文件类型  
    CString strTmp;   //如果找到的是文件夹 存放文件夹路径  
    while(bFound)      //遍历所有文件  
    {   
        bFound=tempFind.FindNextFile(); //第一次执行FindNextFile是选择到第一个文件，以后执行为选择到下一个文件  
        if(tempFind.IsDots())   
            continue; //如果找到的是返回上层的目录 则结束本次查找  
        if(tempFind.IsDirectory())   //找到的是文件夹，则遍历该文件夹下的文件  
        {   
            strTmp=L"";   
            strTmp=tempFind.GetFilePath();  
            FindBmpFile(vecStr, strTmp);   
        }   
        else   
        {   
            CString fileName = tempFind.GetFileName();
            int dotPos = fileName.ReverseFind('.');
            if(dotPos == -1)        // 没后序的文件忽略
                continue;
            CString fileExt = fileName.Right(fileName.GetLength() - dotPos - 1);
            //------------------------------------------------------------------
            if(std::find(vecStr.begin(), vecStr.end(), fileExt) != vecStr.end())
            {
                // 删除文件
/*                int a =10;*/
                CString filePath = tempFind.GetFilePath();
//                 // 这API直接删除不放到回收站 太危险了
//                 ::DeleteFile(filePath);
                if(!DeleteFile(filePath))
                {
                    CString strTemp = L"删除文件\"";
                    strTemp += filePath + L"\"失败";
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
    FileOp.fFlags = FOF_ALLOWUNDO;   //允许放回回收站
    FileOp.fFlags |= FOF_NOCONFIRMATION; //不出现确认对话框
    FileOp.fFlags |= FOF_FILESONLY;     // 只运行文件（不允许文件夹）
    filePath += '\0';
    FileOp.pFrom = filePath.GetBuffer(); 
    FileOp.pTo = NULL;      //一定要是NULL
    FileOp.wFunc = FO_DELETE;    //删除操作
    return SHFileOperation(&FileOp) == 0; 
}