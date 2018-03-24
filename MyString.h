# include <stdio.h>
# include <string.h>

# define CACHESIZ 31
# define DBSIZ 1000

//extern int Key;

int GetString();
int AddString(char *pDB, int iStrLenght);
int InPutString(char *pDB);

void ModifyString(char *pDB);

int SearchString(char *pDB);
int SearchByNo(char *pDB);
int SearchByStr(char *pDB);
int SearchByAddr(char *pDB);

void DeleteString(char *pDB);

int Statistics(char *pDB);

char DBInfo(char *pDB);

void OutPutString(char* pDB, int iID);
void PutString();

static char* FindSpace(char* pDB, int iStrLength);

void FlushCache();