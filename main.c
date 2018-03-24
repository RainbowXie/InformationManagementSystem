# include "Menu.h"
# include "MyString.h"
# include <stdlib.h>

int Key = -1;   //Store option key.

int main()
{
    int iSerialNo = 0;
    char cDataBase[DBSIZ] = { 0 };
    char *pDB = cDataBase;

    while (1)
    {
        Key = -1;
        system("cls");
        PrintMenu();
        GetKey();

        if (!Key)
        {
            exit(0);
        }

        system("cls");
        
        switch (Key)
        {
        case 1:
        {
            PrintMenu();
            iSerialNo = InPutString(pDB);
            Key = 7;
            PrintMenu();
            OutPutString(pDB, iSerialNo);

            system("pause");
            break;
        }
        case 2:
        {

            ModifyString(pDB);
            break;
        }
        case 3:
        {
            PrintMenu();
            GetKey();
            if (0 == Key)
            {
                continue;
            }
            PrintSubMenu();
            GetSearchInfo();
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
        default:
        {
            PrintMenu();
        }
        }
    }
    system("pause");

    return 0;
}