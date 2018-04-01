# include "MyString.h"
# define _CRT_SECURE_NO_WARNINGS
static char szCache[CACHESIZ] = { 0 };
static int iSerialNo[IDSIZ] = { 0 };
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
/*
Function: Add a string from szCache into string database, then flush szCache.

Parameter: pDb is the pointer of database.
Return Value: return the serial number of the stored string. if don't find enough space, return -2.

*/
int InPutString(char *pDB)
{
    int iRet = 0;
    int iStrLength = 0;
    iStrLength = GetString(szCache);
    iRet = AddString(pDB, iStrLength);

    return iRet;
}

/*
Function: Add a string from szCache into the string database, then flush szCache.
Set serial number which according to the input order as the 1st byte of each string.
Set string length as the 2nd byte of the string.
The 3rd byte begin to store string.
Parameter: pDb is the pointer of database, iStrLength is the Length of input string + 3byte.
Return Value: return the serial number of the stored string. if don't find enough space, return -2.
*/
int AddString(char *pDB, int iStrLength)
{
	int i = 1;
    char *pHead = NULL;
    pHead = FindSpace(pDB, iStrLength);
    //while ()
    if (NULL == pHead)
    {
        return -2;
    }
	while (1)
	{
		if (i != iSerialNo[i])
		{
			iSerialNo[i] = i;
			break;
		}
		i++;
	}
    
    *pHead = iSerialNo[i];
    pHead++;
    *pHead = iStrLength;
    pHead++;
    strcpy(pHead, szCache);
    FlushCache();
    return iSerialNo[i];
}

/*
Function: modify a string in database. if database have enough space excuting modify and flush szCache; if not, keep it as it is.
Parameter: Parameter: pDb is the pointer of database, iID is the serial number of the string.
Return Value: Return 1 if modify success, Return -2 if failure.
*/
int ModifyString(char *pDB, int iID)
{
	char* paryHead = NULL;
	size_t iLenDest = 0;
	size_t iLenIn = 0;
	if (NULL == (paryHead = FindString(pDB, iID)))
	{
		return -2;
	}
	iLenDest = *(paryHead + 1);
	iLenIn = strlen(szCache) + 3;
	if (iLenDest < iLenIn)
	{
		if (NULL == FindSpace(pDB, (strlen(szCache) + 3)))
		{
			return -2;
		}
	}

	DeleteString(pDB, iID);
	AddString(pDB, iLenIn);
	return 1;
}
//int SearchString(char *pDB, int Key)
//{
//    int iRet = 0;
//    switch (Key)
//    {
//    case 10:
//    {
//        iRet = GetID();
//        OutPutString(pDB, iRet);
//        break;
//    }
//    case 20:
//    {
//        iRet = SearchByStr(pDB);
//    }
//    case 30:
//    {
//        iRet = SearchByAddr(pDB);
//    }
//    }
//    return iRet;
//}

/*
Function: Delete a string from database, release it's serial number.
Parameter: pDb is the pointer of database, iID is the serial number of the string.
Return Value: return 0 if delete fail; return 1 if return success.
*/
int DeleteString(char *pDB, int iID)
{
	char* pHead = NULL;
	char* pTail = NULL;
	if (NULL == (pHead = FindString(pDB, iID)) && 0 == iSerialNo[iID])
	{
		return 0;
	}

	iSerialNo[iID] = 0;
	pTail = pHead + *(pHead + 1) - 1; 
	for (; pHead <= pTail; pHead++, pTail--)
	{
		*pHead = '\0';
		*pTail = '\0';
	}
	
	return 1;
}
/*
Function: Count the Number of each letter and record it in stCount.iaryLettersNumber[] as Alphabet order,
Count the whole number of letters.
Parameter: pDb is the pointer of database, stCount is the struct that store each letter number and the whole number.
*/
void Statistics(char *pDB, struct CountNumber* stCount)

{

	char* pszHead = NULL;
	char* pszTmp = NULL;
	
	for (size_t i = 0; i < LETTERCOUNT; i++)
	{
		(stCount->iaryLettersNumber)[i] = 0;
	}
	stCount->SumNumber = 0;

	for (int i = 0; i < IDSIZ; i++)
	{
		if (0 == iSerialNo[i])
		{
			continue;
		}

		pszHead = FindString(pDB, i);
		pszTmp = pszHead + 2;
		while ('\0' != *pszTmp)
		{
			for (int j = 0; j < LETTERCOUNT; j++)
			{
				if ((65 + j) == *pszTmp || (97 + j) == *pszTmp)
				{
					(stCount->iaryLettersNumber)[j]++;
					stCount->SumNumber++;
					break;
				}
			}
			pszTmp++;
		}
	}

}

void OutputStatistics(struct CountNumber* stCount)
{
	for (int i = 0; i < LETTERCOUNT; i++)
	{
		printf("%c有%d个，占总字数的 %d/%d。\r\n", i + 65, (stCount->iaryLettersNumber)[i], (stCount->iaryLettersNumber)[i], stCount->SumNumber);
	}
}

/*
Function: Output database space usage. if one byte was been used, output U, if not, output F.
Parameter: pDb is the pointer of database.
Return Value: return 1 if pDB not passed in properly; return 0 if Stactistics complete.
*/
int DBOutput(char *pDB)
{
	int iStatus = 0;
	
	if (NULL == pDB)
	{
		return 1;
	}
	for (int i = 0; i < DBSIZ; i++)
	{
		
		if (DBInfo(i))
		{
			printf("U ");
		}
		else
		{
			printf("F ");
		}
	}
	/*if (NULL == pDB)
	{
		return 1;
	}
	for (int i = 0; i < DBSIZ; i++)
	{
		if ('\0' == *(pDB))
		{
			DBOutPut(1);
		}
		else
		{
			DBOutPut(0);
		}
	}
*/
	return 0;
}
/*
Function: Check database space usage. 
Parameter: i is the space usage condition, 1 is used, 0 is not used.
Return Value: if one byte was been used, return 1, if not, return 0;
*/
int DBInfo(int i)
{
	if ('\0' == i)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
Function: Get a string from stdin to string cache.
Parameter: string cache adress.
Return value: Returns the number of string length + 1byte null character + 2byte flag bit.
*/
int GetString()
{
    int i = 0;
    int iStrLength = 0;

    for (; i < CACHESIZ; i++)
    {
        szCache[i] = '\0';
    }
    //fgets(szCache, 31, stdin);
    scanf("%30s", szCache);
    fflush(stdin);
   
    return strlen(szCache) + 1 + 2; //+1 is '\0'，+2 are serial number and flag bit.
}

/*
Function: Find a String from database by it's serial number, then output it on the screen.
Parameter: iID is String serial number, pDB is a pointer to the database.
Return value: return 1 if output success; return 0 if not.
*/
int OutPutString(char* pDB, int iID)
{

    
	if (SearchByNo(pDB, iID))
	{
		PutString();
		return 1;
	}
    
    //for (; i < DBSIZ; i++)
    //{
    //    if ('\0' == pDB[i])
    //    {
    //        continue;
    //    }
    //    else if (iID != pDB[i])
    //    {
    //        i += pDB[i + 1];
    //    }
    //    if (iID == pDB[i])
    //    {
    //        strcpy(szCache, &pDB[i + 2]);
    //        
    //        break;
    //    }
    //        
    //}
	return 0;
}

/*
Function: Output the String in the szCache, clear the szCache.
*/
void PutString()
{
	char* pHead = szCache;
    if ('\0' != szCache[0])
    {
        printf("No%d.%s\n", (int)*szCache, szCache + 2);
        FlushCache();
    }
}

/*
Function: Find contiguous space from pDB according to iStrLength.
Parameter: pDB is the pointer that pointed to the database which you want to store the string in.
iStrLength is the string length + 3byte.
Return value: return starting address of free space. if there don't have enough contiguous free space, return NULL.
*/
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
            return pchHead;
        }
        if ('\0' != pDB[i])
        {
            iCountSpace = 0;
            isChar = 1;
        }
    }

    pchHead = NULL;
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

/*
Function: Receive Search info from stdin, 
*/
//void GetSearchInfo()
//{
//    int iID = 0;
//    char* pID = NULL;
//    if (10 == Key)
//    {
//    }
//    if (20 == Key)
//    {
//        GetString();
//    }
//    if (30 == Key)
//    {
//        scanf("%8p", pID);
//        return pID;
//    }
//}

/*
Function: Find a String from database by it's serial number, copy it to szCache.
Parameter: iID is String serial number, pDB is a pointer to the database.
Return value: return 1 if find; return 0 if not find.
*/
int SearchByNo(char *pDB, int iID)
{
    char* pID = NULL;
    pID = FindString(pDB, iID);
	if (!pID)
	{
		return 0;
	}

    strcpy(szCache, (pID));
    //int i = 0;

    //for (; i < DBSIZ; i++)
    //{
    //    if ('\0' == pDB[i])
    //    {
    //        continue;
    //    }
    //    else if (iID != pDB[i]) //既不是'\0'，ID又不符合，
    //    {
    //        i += pDB[i + 1];
    //    }
    //    if (iID == pDB[i])
    //    {
    //        strcpy(szCache, &pDB[i + 2]);
    //        break;
    //    }
    //}
	return 1;
}
/*
Function: Search a string from database by inputted keyword, output all the string that include the keyword.
Return value: if not return 0;
*/
int SearchByStr(char *pDB)
{
    int iID = 1;
    int iRet = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    
    char *pcDB = NULL;   //Cache first address
    char *pDBHead = NULL;   //Current string first address
    char caryTmpDB[31] = { 0 };
    strcpy(caryTmpDB, szCache);
    pcDB = caryTmpDB;

    while (pDBHead = FindString(pDB, iID))
    {
        pDBHead += 2;

        for (i = 0; pDBHead[i] != '\0'; i++)
        {
            for (j = i, k = 0; pcDB[k] != '\0' && pDBHead[j] == pcDB[k]; j++, k++);
            
            if (k > 0 && pcDB[k] == '\0')
            {
                strcpy(szCache, pDBHead - 2/*[i + 2]*/);
                PutString();
                iRet++;
                break;
            }
        }
        iID++;
    }
    return iRet;
}

/*
Function: Find a string according to a address from user input, then copy it to the szCache.
Parameter: pDB is the Database.
Return Value: if find the string, return 1; else return 0.
*/
int SearchByAddr(char *pDB, char* pcAddr)
{
	char *pSrc = pcAddr;
	int iID = 1;
	char *pDest = NULL;
	int iLen = 0;

	do
	{		
		if (!(pDest = FindString(pDB, iID)))
		{
			break;
		}
		
		iLen = *(pDest + 1);

		if (pSrc >= pDest && pSrc <= (pDest + iLen - 1))
		{
			strcpy(szCache, (pDest));
			return 1;
		}

		iID++;

	} while (1);
	
    /*char *pSrc = (char *)*szCache;
	char *pDest = FindString(pDB, iID);
	for (; pDest < pDest && NULL != pDest; iID++)
	{
		pDest = FindString(pDB, iID);
	}*/

	return 0;
}

/*
Function: get serial number from stdin.
Return value: return serial number.
*/
int GetID()
{
    int iID = 0;
    scanf("%3d", &iID);
    return iID;
}
/*
Function: get serial number from stdin.
Return value: return serial number.
*/
char* GetAddr()
{
	char* pcAddr = NULL;
	scanf("%8p", &pcAddr);
	return pcAddr;
}
/*
Function: Find string first address from pDB.
Parameter: pDB is the Database first address; iID is the serial number of the string that need to find.
Return Value: If find ,return string serial number address; if not, return NULL.

*/
char *FindString(char *pDB, int iID)
{
    int i = 0;
    char* pHead = NULL;
    while (i < DBSIZ)
    {
        if ('\0' == pDB[i])
        {
            i++;
            continue;
        }
        else if (iID != pDB[i]) //既不是'\0'，ID又不符合，
        {
            i += pDB[i + 1];
        }
        if (iID == pDB[i])
        {
            pHead = &pDB[i];
            break;
        }
    }
    return pHead;
}

/*
Function: Defragmentation. move string forward.
Parameter: pDB is the Database first address.
*/
int Defragmentation(char* pDB)
{
	char* pHead = pDB;
	char* pMove = pDB;
	int iIsSpace = 1;	//前一个为'\0'则为0，非'\0'则为1
	int i = 0;
	int iIsMoved = 0;	//发生转移置为1
	if (!pDB)
	{
		return -2;
	}

	while (i < DBSIZ)
	{
		if (!(0 == iIsSpace && '\0' == *pHead) && (1 != iIsMoved))	//前一个是'\0'，且当前也是'\0'，并且前一步没有交换过就停下来。
		{
			if ('\0' == *pHead)
			{
				iIsSpace = 0;
			}
			else
			{
				iIsSpace = 1;
			}
			pHead++;
			//iIsMoved = 0;
		}
		/*if (1 == iIsMoved)
		{

		iIsMoved = 0;
		}*/
		if ((pMove <= pHead || '\0' == *(pMove)) && !(1 == iIsMoved))
		{
			//iIsMoved = 0;
			pMove++;
			i++;
		}
		/*
		如果pMove不等于pHead，且前一步交换过，pMove指向非'\0'；并且pMove != pHead就交换。
		或者pMove不等于pHead，pHead前一个为'\0'，pMove指向非'\0'；并且pMove != pHead就交换。
		*/
		if (((1 == iIsMoved && '\0' != *pMove) || (0 == iIsSpace && '\0' == *pHead && '\0' != *pMove))
			&& (pMove != pHead))	
		{								
			*pHead = *pMove;
			*pMove = '\0';
			iIsMoved = 1;
			iIsSpace = 1;
			pHead++;
			pMove++;
			i++;
			continue;
		}
		iIsMoved = 0;
		//i++;
	}

	return 0;
}