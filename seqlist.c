#include "seqlist.h"

void InitList(SeqList* list)
{
	list->capacity = INT_SEQLIST_SIZE;
	list->size = 0;
	list->base = calloc(list->capacity, sizeof(Data));
	assert(list->base != NULL);
}

void push_back(SeqList* list, Data data)
{
	if (list->size >= list->capacity)
	{
		return;
	}
	list->base[list->size] = data;
	list->size++;
}

void show_list(SeqList* list)
{
	for (int i = 0; i < list->size; i++)
		printf("%d ", list->base[i]);
	printf("\n");
}

void push_front(SeqList* list, Data data)
{
	if (list->size >= list->capacity)
	{
		return;
	}
	for (int i = list->size; i > 0; i--)
		list->base[i] = list->base[i - 1];
	list->base[0] = data;
	list->size++;
}

void insert(SeqList* list, int index, Data data)
{
	if (index>list->size)
	{
		return;
	}
	for (int i = list->size; i > index; i--)
	{
		list->base[i] = list->base[i - 1];
	}
	list->base[index] = data;
	list->size++;
}

void pop_back(SeqList* list)
{
	if (!IsEmpty(list))
	{
		list->size--;
	}
}

void pop_front(SeqList* list)
{
	if (!IsEmpty(list))
	{
		for (int i = 0; i < list->size - 1; i++)
		{
			list->base[i] = list->base[i + 1];
		}
		list->size--;
	}
}

bool IsEmpty(SeqList* list)
{
	return list->base == NULL;
}

int find(SeqList* list,int item)
{
	for (int i = 0; i < list->size; i++)
	{
		if (list->base[i] == item)
			return i;
	}
	return -1;
}

void erase_pos(SeqList* list, int pos)
{
	if (!IsEmpty(list))
	{
		for (int i = pos; i < list->size - 1; i++)
		{
			list->base[i] = list->base[i + 1];
		}
		list->size--;
	}
}

void erase_val(SeqList* list, int item)
{
	int ret=find(list,item);
	if (ret == -1)
	{
		printf("表中无该值\n");
	}
	else
	{
		for (int i = ret; i < list->size - 1; i++)
		{
			list->base[i] = list->base[i + 1];
		}
		list->size--;
	}
}

void sort(SeqList* list)
{
	if(!IsEmpty(list))
	{
		for (int i = 0; i < list->size - 1; i++)
		{
			for (int j = 0; j < list->size - i - 1; j++)
			{
				if (list->base[j] > list->base[j + 1])
				{
					int tmp = list->base[j];
					list->base[j] = list->base[j + 1];
					list->base[j + 1] = tmp;
				}
			}
		}
	}
}

int size(SeqList* list)
{
	return list->size;
}

void reverse(SeqList* list)
{
	if (IsEmpty(list))
	{
		return;
	}
	for (int i = 0; i < list->size / 2; i++)
	{
		int tmp = list->base[i];
		list->base[i] = list->base[list->size - 1 - i];
		list->base[list->size - 1 - i] = tmp;
	}
}

void clear(SeqList* list)
{
	free(list->base);
	list->size = 0;
}
