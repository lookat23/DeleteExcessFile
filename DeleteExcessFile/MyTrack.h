#ifndef _MY_TRACK_H_
#define _MY_TRACK_H_

#ifdef UNICODE 
#define MYTRACK(STR)    \
    std::wstring strErr;      \
    strErr += L"¾¯¸æ£º";     \
    strErr += STR;           \
    OutputDebugString(strErr.c_str());
#else
#define MYTRACK(STR)  \
    std::string strErr;      \
    strErr += "¾¯¸æ£º";     \
    strErr += STR;          \
    OutputDebugString(strErr.c_str());
#endif

#endif