#include <iostream>
#include <cstring>
using namespace std;

class CMyString {
public:
    CMyString(const char *pData = NULL);
    CMyString(const CMyString& str);
    CMyString& operator=(const CMyString& str);
    ~CMyString(void);

private:
    char *m_pData;
};


CMyString::CMyString(const char *pData): m_pData(NULL) {
    if(pData != NULL) {
        m_pData = new char[strlen(pData)+1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString& str): m_pData(NULL) {
    if(str.m_pData != NULL) {
        m_pData = new char[strlen(str.m_pData)+1];
        strcpy(m_pData, str.m_pData);
    }
}

CMyString& CMyString::operator=(const CMyString& str) {
    if(this != &str) {
        CMyString strTemp(str);
        char *temp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = temp;
    }

    return *this;
}

CMyString::~CMyString(void) {
    if(m_pData != NULL) {
        delete[] m_pData;
        m_pData = NULL;
    }
}

int main(int argc, char *argv[]) {
    CMyString str1("hello, world!");
    CMyString str2 = "I am klb3713.";
    str1 = str2;

    return 0;
}
