# include "Menu.h"
# include "MyString.h"
extern int Key;

int StringControl(char *pDB, char *szCache)
{
    
    switch (Key)
    {
    case 1:
    {
        
        GetString(szCache);
        AddString(pDB, szCache);
        break;
    }
    case 2:
    {
        ModifyString(pDB, szCache);
        break;
    }
    case 3:
    {
        SearchString(pDB);
        break;
    }
    case 4:
    {
        DeleteString(pDB, szCache);
        break;
    }
    case 5:
    {
        Statistics(pDB);
        break;
    }
    case 6:
    {
        DBInfo(pDB);

        break;
    }
    }
}

void AddString(char *pDB, const char *szCache)
{
    
}

void ModifyString(char *pDB, const char *szCache)
{

}
void SearchString(char *pDB)
{

}
void DeleteString(char *pDB, const char *szCache)
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
*/
int GetString(char* szCache)
{
    scanf("%30s", szCache);
}