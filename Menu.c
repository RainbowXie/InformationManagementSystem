# include "Menu.h"
extern int Key;
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
        printf("�����룺");
    }
    case 1:
    {
        printf("��������Ҫ���ӵ��ֶΣ�\n");
        break;
    }
    case 2:
    {
        printf("��������Ҫ�޸ĵ��ֶΣ�\n");
        break;
    }
    case 3:
    {
        printf("��������Ҫ��ѯ���ֶΣ�\n");
        break;
    }
    case 4:
    {
        printf("��������Ҫɾ�����ֶΣ�\n");
        break;
    }
    case 5:
    {
        printf("��ǰ��������Ϊ��\n");
        break;
    }
    case 6:
    {
        printf("Ŀǰ�ռ�ʹ�������\n");
        break;
    }
    case 7:
    {
        
    }
    case 0:
    {
        printf("�ټ���");
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

