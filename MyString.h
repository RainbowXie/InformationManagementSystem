# include <stdio.h>
# include <string.h>
# define _CRT_SECURE_NO_WARNINGS
# define CACHESIZ 31
# define DBSIZ 1000

//extern int Key;

int GetString();
int AddString(char *pDB, int iStrLenght);
int InPutString(char *pDB);

void ModifyString(char *pDB, int iID);

char *FindString(char *pDB, int iID);
int SearchString(char *pDB, int Key);
int SearchByNo(char *pDB, int iID);
int SearchByStr(char *pDB);
int SearchByAddr(char *pDB, char* pcAddr);
int GetID();
char* GetAddr();

void GetSearchInfo();
int DeleteString(char *pDB, int iID);

int Statistics(char *pDB);

char DBInfo(char *pDB);

int OutPutString(char* pDB, int iID);
void PutString();

static char* FindSpace(char* pDB, int iStrLength);

void FlushCache();