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
        printf("       ��ӭ��½��Ϣ����ϵͳ��\n");
        printf("===================================\n");
        printf("      1. �����ֶ�\n");
        printf("      2. �޸��ֶ�\n");
        printf("      3. ��ѯ�ֶ�\n");
        printf("      4. ɾ���ֶ�\n");
        printf("      5. ͳ��������\n");
        printf("      6. �洢��Ϣ\n");
        printf("      0. �˳�\n");
        printf("===================================\n");
        printf("��ѡ��");
        break;
    }
    case 1:
    {
        printf("��������Ҫ���ӵ��ַ������ַ�������С��30���ֽڣ�\n");
        break;
    }
    case 2:
    {
        printf("��������Ҫ�޸ĵ��ַ�����\n");
        break;
    }
    case 3:
    {
        printf("      ��ѡ������ѯ�ķ�ʽ��\n");
        printf("===================================\n");
        printf("      1. ����Ų�ѯ\n");
        printf("      2. ģ����ѯ\n");
        printf("      3. ����ַ��ѯ\n");
        printf("      0. ����\n");
        printf("===================================\n");
        printf("��ѡ��");
        break;
    }
    case 4:
    {
        printf("��������Ҫɾ�����ַ�����\n");
        break;
    }
    case 5:
    {
        printf("��ǰ��������Ϊ��\n");
        break;
    }
    case 6:
    {
        printf("Ŀǰ�ռ�ʹ�������(UΪ��ʹ�ÿռ䣬FΪδʹ�ÿռ�)\n");
        break;
    }
    case 7:
    {
        printf("��������ַ����ǣ�");
        break;
    }
    case 8:
    {
        printf("�����ҵ��ַ����ǣ�");
        break;
    }
    case 9:
    {
        printf("1.������ѯ\n");
        printf("0.����\n");
        printf("��ѡ��");
        break;
    }
    case 10:
    {
        printf("�������ţ�");
        break;
    }
	case 11:
	{
		printf("��Ҫ�޸ĵ��ַ����ǣ�\r\n");
		break;
	}
	case 12:
	{
		printf("�����޸ĳ�ɶ����[����]��\n");
		break;
	}
	case 13:
	{
		printf("�ռ䲻���˨r(�s���t)�q\n");
		break;
	}
	case 14:
	{
		printf("�޸ĳɹ���\n");
		break;
	}
	case 15:
	{
		printf("��Ҫɾ�����ַ����ǣ�\n");
		break;
	}
	case 16:
	{
		printf("ɾ���ɹ���\n");
		break;
	}
	case 17:
	{
		printf("ɾ��ʧ�ܣ��n��\n");
		break;
	}
	case 18:
	{
		printf("\r\n");
		printf("\r\n");
		printf("�Ƿ������Ƭ����\n");
		printf("1.��\n");
		printf("2.��\n");
		printf("��ѡ��\n");

		break;
	}
	case 19:
	{
		printf("������ɣ�\n");
		break;
	}
    case 20:
    {
        printf("�������ַ�����");
        break;
    }
	case 21:
	{
		printf("ȷ���޸���\r\n");
		printf("1.ȷ��\r\n");
		printf("2.��������\r\n");
		printf("3.����\r\n");
		break;
	}
	case 22:
	{
		printf("ȷ��ɾ����\r\n");
		printf("1.ȷ��\r\n");
		printf("2.����\r\n");
		break;
	}
    case 30:
    {
        printf("�������ַ��");
        break;
    }
	case 31:
	{
		printf("������ID:");
		break;
	}
	case 40:
	{
		printf("�����ڵĚG(+_+)?\n");
		break;
	}
    case 0:
    {
        printf("�ټ���");
        break;
    }
    //abnormal exit
	case -3:
	{
		printf("��û���ѡ��->_->\n");
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
    fflush(stdin);
    scanf("%1d", &Key);
    fflush(stdin);

}

