#ifndef _MY_TRACK_H_
#define _MY_TRACK_H_

#ifdef UNICODE 
#define MYTRACK(STR)    \
    std::wstring strErr;      \
    strErr += L"���棺";     \
    strErr += STR;           \
    OutputDebugString(strErr.c_str());
#else
#define MYTRACK(STR)  \
    std::string strErr;      \
    strErr += "���棺";     \
    strErr += STR;          \
    OutputDebugString(strErr.c_str());
#endif

#endif