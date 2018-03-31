# include "Menu.h"

/*
Function: All output Option
*/
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
        printf("请选择：");
        break;
    }
    case 1:
    {
        printf("请输入您要增加的字符串，字符串长度小于30个字节：\n");
        break;
    }
    case 2:
    {
        printf("请输入您要修改的字符串：\n");
        break;
    }
    case 3:
    {
        printf("      请选择您查询的方式：\n");
        printf("===================================\n");
        printf("      1. 按编号查询\n");
        printf("      2. 模糊查询\n");
        printf("      3. 按地址查询\n");
        printf("      0. 返回\n");
        printf("===================================\n");
        printf("请选择：");
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
        printf("您输入的字符串是：");
        break;
    }
    case 8:
    {
        printf("您查找的字符串是：");
        break;
    }
    case 9:
    {
        printf("1.继续查询\n");
        printf("0.返回\n");
        printf("请选择：");
        break;
    }
    case 10:
    {
        printf("请输入编号：");
        break;
    }
	case 11:
	{
		printf("您要修改的字符串是：\r\n");
		break;
	}
	case 12:
	{
		printf("您想修改成啥样≡[。。]≡\n");
	}
    case 20:
    {
        printf("请输入字符串：");
        break;
    }
	case 21:
	{
		printf("确定修改吗？\r\n");
		printf("1.确定\r\n");
		printf("2.重新输入\r\n");
		printf("3.返回\r\n");
		break;
	}
    case 30:
    {
        printf("请输入地址：");
        break;
    }
	case 31:
	{
		printf("请输入ID:");
		break;
	}
	case 40:
	{
		printf("不存在的欸(+_+)?\n");
		break;
	}
    case 0:
    {
        printf("再见！");
        break;
    }
    //abnormal exit
    case -2:
    {
        printf("System Crash!!!!!!!!!!!!\n");
        exit(0);
        break;
    }
    }
    
    return ;
}

/*
Function: Receive input options.
*/
void GetKey()
{
    fflush(stdin);
    scanf("%1d", &Key);
    fflush(stdin);

}

