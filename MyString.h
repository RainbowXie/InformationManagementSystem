# include <stdio.h>
# include <string.h>
# define _CRT_SECURE_NO_WARNINGS
# define CACHESIZ 34
# define DBSIZ 1000
# define IDSIZ 251
# define LETTERCOUNT 26

struct CountNumber
{
	int iaryLettersNumber[LETTERCOUNT];
	int SumNumber;
};

//extern int Key;

int GetString();
int AddString(char *pDB, int iStrLenght);
int InPutString(char *pDB);

int ModifyString(char *pDB, int iID);

char *FindString(char *pDB, int iID);
int SearchByNo(char *pDB, int iID);
int SearchByStr(char *pDB);
int SearchByAddr(char *pDB, char* pcAddr);
int GetID();
char* GetAddr();

int DeleteString(char *pDB, int iID);

void Statistics(char *pDB, struct CountNumber* stCount);
void OutputStatistics(struct CountNumber* stCount);

int DBInfo(char* pDB, int i);
int DBOutput(char* pDB);
int Defragmentation(char* pDB);

int OutPutString(char* pDB, int iID);
void PutString();

static char* FindSpace(char* pDB, int iStrLength);

void FlushCache();