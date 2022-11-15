#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

#define INT_SEQLIST_SIZE 20

typedef int Data;    //��ʾ������������ͣ�ADT��
typedef struct       //����˳���
{
	Data* base;     //ָ���׵�ַ��ָ��
	int capacity;   //������������
	int size;       //��ǰԪ������
}SeqList;

void InitList(SeqList* list);
void push_back(SeqList* list, Data data);
void show_list(SeqList* list);
void push_front(SeqList* list, Data data);
void insert(SeqList* list, int index, Data data);
void pop_back(SeqList* list);
void pop_front(SeqList* list);
bool IsEmpty(SeqList* list);
int find(SeqList* list,int item);
void erase_pos(SeqList* list, int pos);
void erase_val(SeqList*list,int item);
void sort(SeqList* list);
int size(SeqList* list);
void reverse(SeqList* list);
void clear(SeqList* list);
#endif