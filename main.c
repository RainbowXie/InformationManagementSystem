# include "Menu.h"

int main()
{
    char cDataBase[1000] = { 0 };
    int Key = -1;
    
    PrintMenu(Key);
    Key = InputUnit();
    system("cls");
    PrintMenu(Key);
    StringControl(Key, cDataBase);

    system("pause");

    return 0;
}