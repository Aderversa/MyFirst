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
		//创建节点
		pnode=CreateNode(pnode);
		//插入节点
		InsertList(plist, pnode);
		//显示节点
		TraverList(plist, ShowData);
		//移动节点
		TraverList(plist, MoveData);
	}
}