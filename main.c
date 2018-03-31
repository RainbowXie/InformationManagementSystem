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
			if (!OutPutString(pDB, iSerialNo))
			{
				Key = 40;
				PrintMenu();
			}

            system("pause");
            break;
        }
        case 2:
        {
			while (36 != Key)
			{	
				Key = 2;
				PrintMenu();
				GetString();
				Key = 11;
				PrintMenu();
				if (!SearchByStr(pDB))
				{
					Key = 40;
					PrintMenu();
					system("pause");
					system("cls");
					break;
				}
				Key = 31;
				PrintMenu();
				iSerialNo = GetID();
				Key = 21;
				PrintMenu();
				GetKey();
				Key *= 12;
				switch (Key)
				{
				case 12:
				{
					PrintMenu();
					GetString();
					ModifyString(pDB, iSerialNo);
					break;
				}
				case 24:
				{
					system("cls");
					break;
				}
				case 36:
				{
					break;
				}
				}/*switch (Key) end*/
			}/*while (1) end*/
            break;
		}/*case 2 end*/
        case 3:
        {

			while (Key)
            {
                Key = 3;
                PrintMenu();
                GetKey();
                if (0 == Key)
                {
                    continue;
                }
                system("cls");
				Key *= 10;
				PrintMenu();

                switch (Key)
                {
                case 10:
                {
                    iSerialNo = GetID();
                    Key = 8;
                    PrintMenu();
					if (!OutPutString(pDB, iSerialNo))
					{
						Key = 40;
						PrintMenu();
					}
                    break;
                }
                case 20:
				{
                    GetString();
					Key = 8;
					PrintMenu();
					if (!SearchByStr(pDB))
					{
						Key = 40;
						PrintMenu();
					}

                    break;
                }
                case 30:
                {
					char* pcAddr = NULL;
					pcAddr = GetAddr();
					
					Key = 8;
					PrintMenu();
					if (!SearchByAddr(pDB, pcAddr))
					{
						Key = 40;
						PrintMenu();
					}
					PutString();
					break;
                }
                }
                Key = 9;
                PrintMenu();
                GetKey();
                system("cls");
            }
            break;
        }
        case 4:
        {
			iSerialNo = GetID();
            DeleteString(pDB, iSerialNo);
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
		}/*switch (Key) end*/;
    }
    system("pause");

    return 0;
}