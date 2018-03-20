# include "Menu.h"

void StringControl(int Key, char *pDB)
{
    switch (Key)
    {
    case 1:
    {
        InputUnit()
        AddString(pDB);
        break;
    }
    case 2:
    {
        ModifyString(pDB);
        break;
    }
    case 3:
    {
        SearchString(pDB);
        break;
    }
    case 4:
    {
        DeleteString(pDB);
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

void AddString(char *pDB)
{
    
}

void ModifyString(char *pDB)
{

}
void SearchString(char *pDB)
{

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

