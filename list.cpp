#include"list.h"

int ListInit(struct List** pplist)
{
	*pplist = (struct List*)malloc(sizeof(struct List));
	if (NULL == *pplist)
		return 0;
	else
	{
		(*pplist)->pfront = NULL;
		(*pplist)->prear = NULL;
		(*pplist)->count = 0;
	}
	return 1;
}

int IsEmpty(struct List* plist)
{
	if (plist->count == 0)
		return 1;
	else
		return 0;
}

void TraverList(struct List* plist, void(*Traver)(struct Node* pnode))
{
	struct Node* ptemp = plist->pfront;
	int listsize = plist->count;
	while (listsize)
	{
		if (ptemp != NULL)
		{
			Traver(ptemp);
			ptemp = ptemp->pnext;
			listsize--;
		}
	}
}

void InsertList(struct List* plist, struct Node* pnode)
{//β�巨
	if (IsEmpty(plist))
		plist->pfront = pnode;
	else
		plist->prear->pnext = pnode;

	plist->prear = pnode;
	plist->count++;
}

void ShowData(struct Node* pnode)
{
	int i;
	for (i = 0; i < 20; i++)
	{
		if (pnode!=NULL&&pnode->data.ch[i] != '\0')
		{
			settextcolor(pnode->data.color);
			outtextxy(pnode->data.x, pnode->data.y - i * 32, pnode->data.ch[i]);
		}
		else
			break;
	}
}

void MoveData(struct Node* pnode)
{
	pnode->data.y++;
}

struct Node* CreateNode(struct Node* pnode)
{
	int n = rand() % 10 + 5;
	pnode = (struct Node*)malloc(sizeof(struct Node));
	pnode->data.x = rand() % 1200;
	pnode->data.y = 0;
	pnode->data.color = RGB(rand() % 255, rand() % 255, rand() % 255);
	for (int i = 0; i < n; i++)
	{
		pnode->data.ch[i] = rand() % 26 + 65;
	}
	pnode->data.ch[n] = '\0';
	pnode->pnext = NULL;
	return pnode;
}