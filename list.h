#pragma once

#define _SILENCE_AMP_DEPRECATION_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>

struct Data
{
	int x;
	int y;
	char ch[20];
	int color;
};
struct Node
{
	struct Data data;
	struct Node* pnext;
};
struct List
{
	struct Node* pfront;
	struct Node* prear;
	int count;
};

int ListInit(struct List** pplist);
int IsEmpty(struct List* plist);
void TraverList(struct List* plist, void(*Traver)(struct Node* pnode));
void InsertList(struct List* plist, struct Node* pnode);
void ShowData(struct Node* pnode);
void MoveData(struct Node* pnode);
struct Node* CreateNode(struct Node* pnode);