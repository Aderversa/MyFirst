#include"list.h"

int main()
{
	initgraph(1200, 800);
	struct List* plist;
	ListInit(&plist);
	srand((unsigned int)time(NULL));
	struct Node* pnode=NULL;
	while (1)
	{
		//�����ڵ�
		pnode=CreateNode(pnode);
		//����ڵ�
		InsertList(plist, pnode);
		//��ʾ�ڵ�
		TraverList(plist, ShowData);
		//�ƶ��ڵ�
		TraverList(plist, MoveData);
	}
}