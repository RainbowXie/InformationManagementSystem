# include "Menu.h"
extern int Key;
void PrintMenu()
{
    switch (Key)
    {
    case -1:
    {
        printf("       欢迎登陆信息管理系统！\n");
        printf("===================================\n");
        printf("      1. 增加字段\n");
        printf("      2. 修改字段\n");
        printf("      3. 查询字段\n");
        printf("      4. 删除字段\n");
        printf("      5. 统计总字数\n");
        printf("      6. 存储信息\n");
        printf("      0. 退出\n");
        printf("===================================\n");
        printf("请输入：");
    }
    case 1:
    {
        printf("请输入您要增加的字段：\n");
        break;
    }
    case 2:
    {
        printf("请输入您要修改的字段：\n");
        break;
    }
    case 3:
    {
        printf("请输入您要查询的字段：\n");
        break;
    }
    case 4:
    {
        printf("请输入您要删除的字段：\n");
        break;
    }
    case 5:
    {
        printf("当前的总字数为：\n");
        break;
    }
    case 6:
    {
        printf("目前空间使用情况：\n");
        break;
    }
    case 7:
    {
        
    }
    case 0:
    {
        printf("再见！");
        break;
    }
    }

    return 0;
}


int GetKey()
{
    int Key = 0;
    scanf("%1d", &Key);
    fflush(stdin);

    return Key;
}

