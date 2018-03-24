# include "MyString.h"
# define _CRT_SECURE_NO_WARNINGS
static char szCache[CACHESIZ] = { 0 };
static int iSerialNo = 0;
//int StringControl(char *pDB, char *szCache)
//{
//    int iStrLength = 0;
//    switch (Key)
//    {
//    case 1:
//    {
//        
//        iStrLength = GetString(szCache);
//        AddString(pDB, szCache, iStrLength);
//        Key = 7;
//        
//        break;
//    }
//    case 2:
//    {
//        ModifyString(pDB, szCache);
//        break;
//    }
//    case 3:
//    {
//        SearchString(pDB);
//        break;
//    }
//    case 4:
//    {
//        DeleteString(pDB, szCache);
//        break;
//    }
//    case 5:
//    {
//        Statistics(pDB);
//        break;
//    }
//    case 6:
//    {
//        DBInfo(pDB);
//
//        break;
//    }
//    }
//    return 0;
//}

int InPutString(char *pDB)
{
    int iRet = 0;
    int iStrLength = 0;
    iStrLength = GetString(szCache);
    iRet = AddString(pDB, iStrLength);

    return iRet;
}

/*
Function: Add a string into the string database. 
Set serial number which according to the input order as the 1st byte of each string.
Set string length as the 2nd byte of the string.
The 3rd byte begin to store string.
Parameter: pDb is the pointer of database, iStrLength is the Length of input string.
*/
int AddString(char *pDB, int iStrLength)
{
    char *pHead = NULL;
    pHead = FindSpace(pDB, iStrLength);
    //while ()
    if (NULL == pHead)
    {
        return -2;
    }
    iSerialNo++;
    *pHead = iSerialNo;
    pHead++;
    *pHead = iStrLength;
    pHead++;
    strcpy(pHead, szCache);
    FlushCache();
    return iSerialNo;
}

void ModifyString(char *pDB, const char *szCache)
{

}
int SearchString(char *pDB)
{
    int iRet = 0;
    switch (Key)
    {
    case 10:
    {
        iRet = SearchByNo();
        break;
    }
    case 20:
    {
        iRet = SearchByStr();
    }
    case 30:
    {
        iRet = SearchByAddr();
    }
    }
    return iRet;
}
void DeleteString(char *pDB)
{

}
int Statistics(char *pDB)
{

}

char DBInfo(char *pDB)
{

}

/*
function: Input a string to string cache.
Parameter: string cache adress.
Return value: Returns the number of string length + 2byte flag bit.
*/
int GetString()
{
    int i = 0;
    int iStrLength = 0;

    for (; i < CACHESIZ; i++)
    {
        szCache[i] = '\0';
    }
    scanf("%30s", szCache);
    fflush(stdin);
   
    return strlen(szCache) + 1 + 2; //+1 is '\0'，+2 are serial number and flag bit.
}

void OutPutString(char* pDB, int iID)
{
    int i = 0;
    
    for (; i < DBSIZ; i++)
    {
        if ('\0' == pDB[i])
        {
            continue;
        }
        else if (iID != pDB[i])
        {
            i += pDB[i + 1];
        }
        if (iID == pDB[i])
        {
            strcpy(szCache, &pDB[i + 2]);
            PutString();
            break;
        }
            
    }
}

void PutString()
{
    if ('\0' != szCache[0])
    {
        printf("%s", szCache);
        FlushCache();
    }
}

static char* FindSpace(char* pDB, int iStrLength)
{
    char *pchHead = NULL;
    int isChar = 1;
    int i = 0;
    int iCountSpace = 0;

    for (i = 0; i < DBSIZ; i++)
    {
        if ('\0' == pDB[i] && isChar)   //如果前一字节是字符，当前字节是'\0'，就作为开头
        {
            pchHead = &pDB[i + 1];
            isChar = 0;
        }
        if ('\0' == pDB[i])
        {
            iCountSpace++;
        }
        if (iCountSpace > iStrLength)
        {
            break;
        }
        if ('\0' != pDB[i])
        {
            iCountSpace = 0;
            isChar = 1;
        }
    }

    return pchHead;
}

void FlushCache()
{
    int i = 0;
    for (i = 0; i < CACHESIZ; i++)
    {
        szCache[i] = '\0';
    }
}
void GetSearchInfo()
{
    
}
int SearchByNo(char *pDB)
{
    int i = 0;

    for (; i < DBSIZ; i++)
    {
        if ('\0' == pDB[i])
        {
            continue;
        }
        else if (iID != pDB[i])
        {
            i += pDB[i + 1];
        }
        if (iID == pDB[i])
        {
            strcpy(szCache, &pDB[i + 2]);
            PutString();
            break;
        }

    }
}
int SearchByStr(char *pDB)
{

}
int SearchByAddr(char *pDB)
{

}