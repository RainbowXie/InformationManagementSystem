# include "Menu.h"
# include "MyString.h"

int Key = -1;
int main()
{
    char cDataBase[1000] = { 0 };
    char szCache[30] = { 0 };

    PrintMenu(cDataBase);
    Key = GetKey();
    system("cls");
    PrintMenu(cDataBase);
    StringControl(cDataBase, szCache);

    system("pause");

    return 0;
}