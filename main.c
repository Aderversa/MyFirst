#define _CRT_SECURE_NO_WARNINGS
#include"seqlist.h"

void menu()
{
	printf("****************************************\n");
	printf("*  [1]push_back         [2]push_front  *\n");
	printf("*  [3]show_list         [4]insert      *\n");
	printf("*  [5]pop_back          [6]pop_front   *\n");
	printf("*  [7]erase_pos         [8]erase_val   *\n");
	printf("*  [9]find              [10]size       *\n");
	printf("*  [11]sort             [12]reverse    *\n");
	printf("*  [13]clear            [14]quit       *\n");
	printf("*  [15]cls              [16]InitList   *\n");
	printf("****************************************\n");
	printf("****************************************\n");
}

int main()
{
	SeqList list;
	int input = 0,index=-1,pos=-1,ret;
	Data item = -1;
	InitList(&list);
	menu();
	while (1)
	{
		printf("��ѡ��Ҫ���еĲ�������ţ�");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("����Ҫִ�е�Ԫ��,����-1��Ϊ������־:");
			while (scanf("%d", &item), item != -1)
				push_back(&list, item);
			break;
		case 2:
			printf("����Ҫִ�е�Ԫ��,����-1��Ϊ������־:");
			while (scanf("%d", &item), item != -1)
				push_front(&list, item);
			break;
		case 3:
			show_list(&list);
			break;
		case 4:
			printf("�밴˳�������±��Ԫ�أ�");
			scanf("%d%d", &index, &item);
			insert(&list,index,item);
			break;
		case 5:
			pop_back(&list);
			break;
		case 6:
			pop_front(&list);
			break;
		case 7:
			printf("������Ҫɾ�����±꣺");
			scanf("%d", &pos);
			erase_pos(&list, pos);
			break;
		case 8:
			printf("��������Ҫɾ����Ԫ�أ�");
			scanf("%d", &item);
			erase_val(&list, item);
			break;
		case 9:
			printf("������Ҫ���ҵ�Ԫ�أ�");
			scanf("%d", &item);
			ret=find(&list, item);
			if (ret == -1)
				printf("�����޸�Ԫ��\n");
			else
				printf("�ҵ�%d�ˣ��±���%d\n", item, ret);
			break;
		case 10:
			ret=size(&list);
			printf("��СΪ%d\n", ret);
			break;
		case 11:
			sort(&list);
			break;
		case 12:
			reverse(&list);
			break;
		case 13:
			clear(&list);
			break;
		case 14:
			return 0;
		case 15:
			system("cls");
			menu();
			break;
		case 16:
			InitList(&list);
			break;
		default:
			printf("�������!!!!\n");
			break;
		}
	}
	return 0;
}