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
        printf("请输入您要修改的字符串ID：");
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
        printf("请输入您要删除的字符串ID：\n");
        break;
    }
    case 5:
    {
        printf("当前的总字数为：\n");
        break;
    }
    case 6:
    {
        printf("目前空间使用情况：(U为已使用空间，F为未使用空间)\n");
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
		break;
	}
	case 13:
	{
		printf("失败了╮(╯▽╰)╭\n");
		break;
	}
	case 14:
	{
		printf("修改成功。\n");
		break;
	}
	case 15:
	{
		printf("您要删除的字符串是：\n");
		break;
	}
	case 16:
	{
		printf("删除成功。\n");
		break;
	}
	case 17:
	{
		printf("删除失败＞﹏＜\n");
		break;
	}
	case 18:
	{
		printf("\r\n");
		printf("\r\n");
		printf("是否进行碎片整理？\n");
		printf("1.是\n");
		printf("2.否\n");
		printf("请选择：\n");

		break;
	}
	case 19:
	{
		printf("整理完成！\n");
		break;
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
	case 22:
	{
		printf("确定删除吗？\r\n");
		printf("1.确定\r\n");
		printf("2.返回\r\n");
		break;
	}
    case 30:
    {
        printf("请输入地址：");
        break;
    }
	case 31:
	{
		printf("您要删除的字符串是：\n");
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
	case -3:
	{
		printf("咱没这个选项->_->\n");
		break;
	}
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
	Key = -3;
    fflush(stdin);
    scanf("%1d", &Key);
    fflush(stdin);

}

