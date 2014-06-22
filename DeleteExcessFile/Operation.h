#pragma once
#include <vector>
class COperation
{
public:
    COperation(void);
    ~COperation(void);
    BOOL CheckDuplicate(std::vector<CString>& vecStr, CString strField);        // 检查vec里面是否已经存在字段
    void UpdateShowEdit(std::vector<CString>& vecStr, CEdit* pEdit);      // 刷新显示哪种类型被删的edit
    void FindBmpFile(std::vector<CString>& vecStr, CString strFoldername);                                        // 遍历指定目录
    BOOL DeleteFile(CString filePath);      //删除文件
};

