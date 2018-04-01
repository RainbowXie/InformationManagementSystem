# include "Menu.h"
# include "MyString.h"
# include <stdlib.h>

int Key = -1;   //Store option key.

int main()
{
    int iSerialNo = 0;
    char cDataBase[DBSIZ] = { 0 };
    char *pDB = cDataBase;
	struct CountNumber stCount = { { 0 }, 0 };	//Statistical data
	

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
		}/*case 1: end*/
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
				Key = 12;
				PrintMenu();
				GetString();
				Key = 21;
				PrintMenu();
				GetKey();
				Key *= 12;
				switch (Key)
				{
				case 12:
				{
					if (-2 == ModifyString(pDB, iSerialNo))
					{
						Key = 13; 
						PrintMenu();
					}
					else
					{
						Key = 14;
						PrintMenu();

					}
					system("pause");
					Key = 36;
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
				default:
				{
					system("cls");
					Key = -3;
					PrintMenu();
					system("pause");
					break;
				}
				}/*switch (Key) end*/
			}/*while (1) end*/
            break;
		}/*case 2: end*/
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
				default:
				{
					system("cls");
					Key = -3;
					PrintMenu();
					system("pause");
					break;
				}
				}/*switch(Key) end*/
                Key = 9;
                PrintMenu();
                GetKey();
                system("cls");
			}/*while(36 == Key) end*/
            break;
        }
        case 4:
        {
			while (32 != Key && -3 != Key)
			{
				Key = 4;
				PrintMenu();
				GetString();
				Key = 15;
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
				Key = 22;
				PrintMenu();
				GetKey();
				Key *= 16;
				switch (Key)
				{
				case 16:
				{
					if (0 == DeleteString(pDB, iSerialNo))
					{
						Key = 17;
						PrintMenu();
					}
					else
					{
						PrintMenu();
					}
					system("pause");
					Key = 32;
					break;
				}
				case 32:
				{
					break;
				}
				default:
				{
					system("cls");
					Key = -3;
					PrintMenu();
					system("pause");
					break;
				}
				}/*switch (Key) end*/
			}/*while (1) end*/
			break;
        }
        case 5:
        {
			Statistics(pDB, &stCount);
			OutputStatistics(&stCount);
			system("pause");
            break;
        }
        case 6:
        {
			PrintMenu();
			DBOutput(pDB);
			Key = 18;
			PrintMenu();
			GetKey();
			switch (Key)
			{
			case 1:
			{
				Defragmentation(pDB);
				Key = 19;
				PrintMenu();
			}
			case 2:
			{
				break;
			}
			default:
			{
				Key = -3;
				PrintMenu();
				break;
			}
			}/*switch(Key) end*/
            break;
		}/*case 6: end*/
		default:
		{
			system("cls");
			Key = -3;
			PrintMenu();
			system("pause");
			break;
		}
		}/*switch (Key) end*/;
    }
    system("pause");

    return 0;
}