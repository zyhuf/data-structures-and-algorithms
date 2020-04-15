#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdlib.h>
#include <stdio.h>
typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkList;

//链表的头插法
void CreateListHead(LinkList *&L, ElemType a[], int n);
//链表的尾插法
void CreateListTail(LinkList *&L, ElemType a[], int n);

//释放链表
void DestroyList(LinkList *&L);

//得到链表的长度
int ListLength(LinkList *L);

//链表的插入
bool ListInsert(LinkList *&L, int i, ElemType e);

//链表的删除
bool ListDelete(LinkList *&L, int i, ElemType &e);

#endif // LINKLIST
